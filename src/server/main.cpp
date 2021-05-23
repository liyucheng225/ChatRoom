#include <iostream>
#include <signal.h>
#include "ChatServer.h"
#include "ChatService.h"
#include "MySQL.hpp"
using namespace std;

//
void reset_handler(int) {
    cout << "ctrl+c" << endl;
    exit(0);
}

int main (int argc, char * argv[]) {
    if (argc < 2) {
        cerr << "Please invaild example: ./ExeName Port" << endl;
        exit(-1);
    }
    uint16_t port = static_cast<uint16_t>(atoi(argv[1]));
    signal(SIGINT,reset_handler); //
    MySQL mysql;
    if (mysql.connet()) {
        cout << "af";
    }
    muduo::net::EventLoop loop;
    muduo::net::InetAddress listenAddr(2007);
    ChatServer server(&loop, listenAddr, "chatServer");
    server.start();
    loop.loop();
}