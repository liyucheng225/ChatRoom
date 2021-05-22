#ifndef USERMODEL_H
#define USERMODEL_H

#include <iostream>
using namespace std;

class UserModel
{
public:
    UserModel(int userId, string userName, string userPasswd, bool state);
    void setUserName(string userName);
    void setUserPasswd(string userPasswd);
    void setUserId(int userId);
    void setUserState(bool state);
    int getUserId();
    string getUserName();
    string getUserPasswd();
    bool getUserstate();
    ~UserModel();
private:
    /* data */
    string userName; //用户名
    int userId; //用户登录帐号
    string userPasswd; //用户密码
    bool state; //用户在线状态
};

#endif