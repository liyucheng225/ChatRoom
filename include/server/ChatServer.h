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
    //��ʼ���������������
    ChatServer(muduo::net::EventLoop *loop, const muduo::net::InetAddress &listenAddr, const string &nameArg);

    //����������
    void  start();

    //��������
    ~ChatServer();

private:
    //�ϱ����������Ϣ�Ļص�����
    void on_connection(const muduo::net::TcpConnectionPtr &);

    //�ϱ���д��Ϣ�����Ϣ�Ļص�����
    void on_message(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);

private:
    muduo::net::TcpServer server_; //��ϵ�muduo�⣬ʵ�ַ��������ܵ������
    muduo::net::EventLoop *loop_; //ָ���¼�ѭ�������ָ��
};

#endif