#ifndef USERMODEL_H
#define USERMODEL_H

#include <iostream>
#include <string>

using namespace std;

class User
{
public:
    User(int userId, string userName, string userPasswd, bool state);
    void setUserName(string userName);
    void setUserPasswd(string userPasswd);
    void setUserId(int userId);
    void setUserState(bool state);
    int getUserId();
    string getUserName();
    string getUserPasswd();
    bool getUserstate();
    ~User();
private:
    /* data */
    string userName; //用户名
    int userId; //用户登录帐号
    string userPasswd; //用户密码
    bool state; //用户在线状态
};

#endif