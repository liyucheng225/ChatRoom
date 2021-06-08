#include "ChatService.h"

using namespace placeholders;

/*
    获取服务器业务处理模块的单例对象    
*/
ChatService* ChatService::instance() {
    static ChatService chatService;
    return &chatService;
}

/*
    生成随机数，用来生成用户id和群组id
*/
int ChatService::createRandNum(int number) {
    int max = pow(10, number);
    int min = pow(10, number - 1);
    srand((unsigned)time(0));
    return (rand() % (max - min) + min);     
}

/*
    构造函数
*/
ChatService::ChatService() {
    msg_handler_map.insert({LOG_MSG_GO, bind(&ChatService::login, this, _1, _2, _3)}); //登陆
    msg_handler_map.insert({LOGINOUT_MSG, bind(&ChatService::loginOut, this, _1, _2, _3)}); //注销
    msg_handler_map.insert({REG_MSG_GO, bind(&ChatService::regist, this, _1, _2, _3)}); //注册
    msg_handler_map.insert({ONE_CHAT_MSG, bind(&ChatService::oneChat, this, _1, _2, _3)});//私聊
    msg_handler_map.insert({ADD_FRIEND_MSG, bind(&ChatService::addFriend, this, _1, _2, _3)});//添加好友
    msg_handler_map.insert({CREATE_GROUP_MSG, bind(&ChatService::createGroup, this, _1, _2, _3)});//创建群组
    msg_handler_map.insert({ADD_GROUP_MSG, bind(&ChatService::addGroup, this, _1, _2, _3)});//添加群组
    msg_handler_map.insert({GROUP_CHAT_MSG, bind(&ChatService::groupMsg, this, _1, _2, _3)});//群聊
    msg_handler_map.insert({SEARCH_CHATRECORD_GO, bind(&ChatService::searchRecord, this, _1, _2, _3)});//查找聊天记录
}
/*
    用来获取对应消息的处理函数
*/
MsgHandler ChatService::get_handler(int msgId) {
    if (msg_handler_map.find(msgId) == msg_handler_map.end()) {
        return [=](const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
            LOG_ERROR << "msgId:" << msgId << "can not found handler!"; 
        };
    } else {
        return msg_handler_map[msgId];
    }

}

/*
    登录业务
*/
void ChatService::login(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    int id = js["id"];
    string passwd = js["passwd"];
    User user = userModel.query(id);
    cout << "用户查询结束" << user.getUserId() << user.getUserPasswd()  << "state:" << user.getUserstate() <<  endl;

    if (user.getUserPasswd() == passwd && user.getUserId()== id) {
        /*查询是否在线*/
        if (user.getUserstate() != LOGIN_BACK_NOONLINE) {
            json res;
            res["msgId"] = LOG_MSG_BACK;
            res["type"] = LOGIN_BACK_ISONLINE;
            conn->send(res.dump());
        } else {
            {
                lock_guard<mutex> lock(conn_mutex); //分别在构造和析构函数中上和解锁
                user_connection_map.insert({id,conn}); //保存在线用户的信息，用来发送消息
            }
            // user.setUserState(LOGIN_BACK_ISONLINE); //设置该用户为在线状态
            userModel.resetState(LOGIN_BACK_ISONLINE, id);

            //组装回复信息，包括该用户信息，该用户所在群组信息，该用户好友信息
            json res;
            res["msgId"] = LOG_MSG_BACK;
            res["type"] = LOGIN_BACK_SUCCESS;

            //用户信息
            res["id"] = user.getUserId();
            res["name"] = user.getUserName();

            //用户好友信息
            vector<User> friendList = friendModel.query(user.getUserId()); //查询用户好友列表;
            if (!friendList.empty()) {
                vector<string> friendRes;
                for (User &friend_ : friendList) {
                    cout << "返回的用户好友id" << friend_.getUserId() << endl;
                    json js;
                    js["id"] = friend_.getUserId();
                    js["name"] = friend_.getUserName();
                    js["state"] = friend_.getUserstate();
                    friendRes.push_back(js.dump());
                }
                res["friend"] = friendRes;
                cout << "好友信息：" << res["friend"] << endl;
            }

            //用户群组信息
            vector<Group> groupList;
            groupList = groupModel.queryGroup(user.getUserId());
            if (!groupList.empty()) {
                vector<string> groupRes;
                for (Group &group_: groupList) {
                    cout  << "群名：" << group_.getGroupName() << endl;
                    json groupJs;
                    groupJs["id"] = group_.getGroupId();
                    groupJs["name"] = group_.getGroupName();
                    groupJs["desc"] = group_.getGroupDesc();
                    vector<string> groupUserRes;
                    for (GroupUser &groupUser_ : group_.getUser()) {
                        json js;
                        js["id"] = groupUser_.getUserId();
                        js["name"] = groupUser_.getUserName();
                        js["state"] = groupUser_.getUserstate();
                        js["role"] = groupUser_.getRole();
                        cout << "jsjs::" << js << endl;
                        groupUserRes.push_back(js.dump());
                    }
                    groupJs["users"] = groupUserRes;
                    groupRes.push_back(groupJs.dump());
                }
                res["groups"] = groupRes;
            }
            cout << "回复消息：" << res.dump() << endl;
            conn->send(res.dump());
        }

    } else {
        json res;
        res["msgId"] = LOG_MSG_BACK;
        res["type"] = LOGIN_BACK_EMPTY;
        conn->send(res.dump());
    }
}

/*注册业务*/
void ChatService::regist(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    string name = js["name"];
    string passwd = js["passwd"];
    int question = js["questionIndex"].get<int>();
    string answer = js["answer"];

    int id = createRandNum(9);//生成随即id
    bool idIsEmpty =  userModel.queryId(id); //判断id是否为空

    //如果为空则重新生成id
    while (idIsEmpty) {
        id = createRandNum(id);
        idIsEmpty = userModel.queryId(id);
    }

    /*填充该用户的信息*/
    User user;
    user.setUserId(id);
    user.setUserName(name);
    user.setUserPasswd(passwd);
    user.setUserQuestionIndex(question);
    user.setUserState(LOGIN_BACK_NOONLINE);
    user.setUserAnswer(answer);
    
    /*将用户数据存入数据库*/
    bool res = userModel.insertUser(user);
    if (res) {
        json response;
        response["msgId"] = REG_MSG_ACK;
        response["success"] = true;
        response["id"] = user.getUserId();
        conn->send(response.dump());
    } else {
        json response;
        response["msgId"] = REG_MSG_ACK;
        response["success"] = false;
        conn->send(response.dump());
    }
}

/*一对一聊天*/
void ChatService::oneChat(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    cout << "一对一聊天模块服务" << endl;
    int id = js["friendId"].get<int>();
    cout << "发送给" << id << endl;
    auto it = user_connection_map.find(id);
    if (it != user_connection_map.end()) {
        it->second->send(js.dump());
    } else {
        //存储离线消息
    }
}

/*添加好友*/
void ChatService::addFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    int id = js["id"].get<int>();
    int friendId = js["friendId"].get<int>();
    friendModel.insert(id, friendId);
}

/*查询朋友*/
void ChatService::searchFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*查询聊天记录*/
void ChatService::searchRecord(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*创建群聊*/
void ChatService::ChatService::createGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    Group group;
    int id;
    group.setGroupName(js["name"]);
    group.setGroupoDesc(js["desc"]);
    id = createRandNum(6);
    bool isIdEmpty = groupModel.queryId(id);
    while (isIdEmpty) {
        id = createRandNum(6);
        isIdEmpty = groupModel.queryId(id);
    }
    group.setGroupId(id);
}

/*添加群组*/
void ChatService::ChatService::addGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    int id = js["id"].get<int>();
    int groupId = js["groupId"].get<int>();
    groupModel.addGroup(id, groupId,"组员");
}

/*群组消息*/
void ChatService::ChatService::groupMsg(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    
}

/*
    注销业务
*/
void ChatService::ChatService::loginOut(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

    int userId = js["id"].get<int>();

    auto it = user_connection_map.find(userId);
    if (it != user_connection_map.end()) {
        user_connection_map.erase(it);
    }
    //更新用户状态
    userModel.resetState(LOGIN_BACK_NOONLINE,userId);
}


/*服务器异常业务重置*/
void ChatService::reset() {

}
ChatService::~ChatService() {

}
