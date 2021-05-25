#ifndef CHATSERVICE_H
#define CHATSERIVCE_H
#include <mutex>
#include <unordered_map>
#include <muduo/net/TcpConnection.h>
#include "ChatServer.h"
#include "json.hpp"
#include "UserModel.h"
#include "OfflineMessageModel.h"
#include "FriendModel.h"
#include "GroupModel.h"

using json = nlohmann::json;
using namespace std;
using MsgHandler = function<void(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time)>;

class ChatService
{
public:
    static ChatService *instance();
    /*��¼ҵ��*/
    void login(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*ע��ҵ��*/
    void regist(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*һ��һ����*/
    void oneChat(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*��Ӻ���*/
    void addFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*��ѯ����*/
    void searchFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*��ѯ�����¼*/
    void searchRecord(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*����Ⱥ��*/
    void createGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*���Ⱥ��*/
    void addGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*Ⱥ����Ϣ*/
    void groupMsg(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*ע��ҵ��*/
    void loginOut(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*��ȡ��Ϣ��Ӧ�Ĵ�����*/
    MsgHandler get_handler(int msgid);

    /*�������쳣ҵ������*/
    void reset();
    
private:
    /*ע����Ϣ�Լ���Ӧ�Ļص�����*/
    ChatService(/* args */);
    ~ChatService();
    /* data */
private:
    /*�洢�¼������Ļص�����*/
    unordered_map<int,MsgHandler> msg_handler_map;

    /*�洢�����û���������������ڷ��������û�����Ϣ��ע���̰߳�ȫ*/
    unordered_map<int,muduo::net::TcpConnectionPtr> user_connection_map;
    mutex conn_mutex;

    UserModel userModel;
    OfflineMessageModel offlineMessageModel;
    FriendModel friendModel;
    GroupModel groupModel;
};


#endif
