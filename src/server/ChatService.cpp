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
    msg_handler_map.insert({LOG_MSG_GO, bind(&ChatService::login, this, _1, _2, _3)}); //��½
    msg_handler_map.insert({LOGINOUT_MSG, bind(&ChatService::loginOut, this, _1, _2, _3)}); //ע��
    msg_handler_map.insert({REG_MSG_GO, bind(&ChatService::regist, this, _1, _2, _3)}); //ע��
    msg_handler_map.insert({ONE_CHAT_MSG, bind(&ChatService::oneChat, this, _1, _2, _3)});//˽��
    msg_handler_map.insert({ADD_FRIEND_MSG, bind(&ChatService::addFriend, this, _1, _2, _3)});//��Ӻ���
    msg_handler_map.insert({CREATE_GROUP_MSG, bind(&ChatService::createGroup, this, _1, _2, _3)});//����Ⱥ��
    msg_handler_map.insert({ADD_GROUP_MSG, bind(&ChatService::addGroup, this, _1, _2, _3)});//���Ⱥ��
    msg_handler_map.insert({GROUP_CHAT_MSG, bind(&ChatService::groupMsg, this, _1, _2, _3)});//Ⱥ��
    msg_handler_map.insert({SEARCH_CHATRECORD_GO, bind(&ChatService::searchRecord, this, _1, _2, _3)});//���������¼
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
/*��¼ҵ��*/
void ChatService::login(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {
    cout << js << "1" <<endl;;
    string id = js["id"];
    string passwd = js["passwd"];
    User user = userModel.query(id);
     cout << "2" << js;
    if (user.getUserPasswd() == passwd && user.getUserId()== id) {
        /*��ѯ�Ƿ�����*/
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

/*ע��ҵ��*/
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

/*һ��һ����*/
void ChatService::oneChat(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*��Ӻ���*/
void ChatService::addFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*��ѯ����*/
void ChatService::searchFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*��ѯ�����¼*/
void ChatService::searchRecord(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*����Ⱥ��*/
void ChatService::ChatService::createGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*���Ⱥ��*/
void ChatService::ChatService::addGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*Ⱥ����Ϣ*/
void ChatService::ChatService::groupMsg(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}

/*ע��ҵ��*/
void ChatService::ChatService::loginOut(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time) {

}


/*�������쳣ҵ������*/
void ChatService::reset() {

}
ChatService::~ChatService() {

}
