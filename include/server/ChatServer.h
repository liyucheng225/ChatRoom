#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <iostream>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Logging.h>
#include <ctime>
using namespace std;

class ChatServer {
public:
    //初始化聊天服务器对象
    ChatServer(muduo::net::EventLoop *loop, const muduo::net::InetAddress &listenAddr, const string &nameArg);

    //启动服务器
    void  start();

    //析构函数
    ~ChatServer();

private:
    //上报链接相关信息的回调函数
    void on_connection(const muduo::net::TcpConnectionPtr &);

    //上报读写信息相关信息的回调函数
    void on_message(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);

private:
    muduo::net::TcpServer server_; //组合的muduo库，实现服务器功能的类对象
    muduo::net::EventLoop *loop_; //指向事件循环对象的指针
};

#endif