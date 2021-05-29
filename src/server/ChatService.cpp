#include "ChatService.h"

using namespace placeholders;

ChatService* ChatService::instance() {
    static ChatService chatService;
    return &chatService;
}
void ChatService::createRandNum(string &id) {
    id.clear();
    int num = 0;
    srand((unsigned)time(0));
    id = to_string(rand() % 9 + 1);
    for (int i = 0; i < 10; i++) {
        id += to_string(rand() % 10);
    }
}
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

MsgHandler ChatService::get_handler(int msgId) {
    if (msg_handler_map.find(msgId) == msg_handler_map.end()) {
        return [=](const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
            LOG_ERROR << "msgId:" << msgId << "can not found handler!"; 
        };
    } else {
        return msg_handler_map[msgId];
    }

}
/*登录业务*/
void ChatService::login(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    cout << js << "1" <<endl;;
    string id = js["id"];
    string passwd = js["passwd"];
    User user = userModel.query(id);
     cout << "2" << js;
    if (user.getUserPasswd() == passwd && user.getUserId()== id) {
        /*查询是否在线*/
        if (user.getUserstate()) {
            json res;
            res["msgId"] = LOG_MSG_BACK;
            res["type"] = LOGIN_BACK_ISONLINE;
            conn->send(res.dump());
        } else {
            user_connection_map.insert({id,conn});
            user.setUserState(true);
            if (!userModel.updateState(user)) {
                perror("updateState error!");
            }
            json res;
            res["msgId"] = LOG_MSG_BACK;
            res["type"] = LOGIN_BACK_SUCCESS;
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
    string id;
    bool idIsEmpty;

    createRandNum(id);
    idIsEmpty =  userModel.queryId(id);
    while (idIsEmpty) {
        id.clear();
        // createRandNum(id);
        idIsEmpty = userModel.queryId(id);
    }

    User user;
    user.setUserId(id);
    user.setUserName(name);
    user.setUserPasswd(passwd);
    user.setUserQuestionIndex(question);
    user.setUserState(0);
    user.setUserAnswer(answer);
    
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

}

/*添加好友*/
void ChatService::addFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*查询朋友*/
void ChatService::searchFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*查询聊天记录*/
void ChatService::searchRecord(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*创建群聊*/
void ChatService::ChatService::createGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*添加群组*/
void ChatService::ChatService::addGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*群组消息*/
void ChatService::ChatService::groupMsg(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*注销业务*/
void ChatService::ChatService::loginOut(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}


/*服务器异常业务重置*/
void ChatService::reset() {

}
ChatService::~ChatService() {

}
