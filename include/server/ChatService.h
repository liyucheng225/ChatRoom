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
    /*登录业务*/
    void login(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*注册业务*/
    void regist(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*一对一聊天*/
    void oneChat(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*添加好友*/
    void addFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*查询朋友*/
    void searchFriend(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*查询聊天记录*/
    void searchRecord(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*创建群聊*/
    void createGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*添加群组*/
    void addGroup(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*群组消息*/
    void groupMsg(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*注销业务*/
    void loginOut(const muduo::net::TcpConnectionPtr &conn, json &js, muduo::Timestamp time);

    /*获取消息对应的处理器*/
    MsgHandler get_handler(int msgid);

    /*服务器异常业务重置*/
    void reset();
    
private:
    /*注册消息以及对应的回调函数*/
    ChatService(/* args */);
    ~ChatService();
    /* data */
private:
    /*存储事件触发的回调函数*/
    unordered_map<int,MsgHandler> msg_handler_map;

    /*存储在线用户的链接情况，便于服务器给用户发消息，注意线程安全*/
    unordered_map<int,muduo::net::TcpConnectionPtr> user_connection_map;
    mutex conn_mutex;

    UserModel userModel;
    OfflineMessageModel offlineMessageModel;
    FriendModel friendModel;
    GroupModel groupModel;
};


#endif
