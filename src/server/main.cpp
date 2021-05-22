#include <iostream>
#include <signal.h>
#include "../../include/server/ChatServer.h"
#include "../../include/server/ChatServer.h"

using namespace std;

//
void reset_handler(int) {
    cout << "ctrl+c" << endl;
    exit(0);
}

int main (int argc, char * argv[]) {
    if (argc < 2) {
        cerr << "Please invaild example: ./ExeNAME Port" << endl;
        exit(-1);
    }
    uint16_t port = static_cast<uint16_t>(atoi(argv[1]));
    signal(SIGINT,reset_handler); //
    muduo::net::EventLoop loop;
    muduo::net::InetAddress listenAddr(2007);
    ChatServer server(&loop, listenAddr, "chatServer");
    server.start();
    loop.loop();
}