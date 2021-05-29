#ifndef USERMODEL_H
#define USERMODEL_H

#include <iostream>
#include <string>
# include <stdlib.h>
using namespace std;

class User
{
public:
    User(string userId, string userName, string userPasswd, int questionIndex, bool state);
    void setUserName(string userName);
    void setUserPasswd(string userPasswd);
    void setUserId(string userId);
    void setUserState(bool state);
    void setUserQuestionIndex(int index);
    void setUserAnswer(string answer);

    string getUserId();
    string getUserName();
    string getUserPasswd();
    bool getUserstate();
    int getUserQuestionIndex();
    string getUserAnswer();
    User();
    ~User();
private:
    /* data */
    string userName; //用户名
    string userId; //用户登录帐号
    string userPasswd; //用户密码
    int questionIndex;//密保问题序号
    string answer; //密保答案
    bool state; //用户在线状态
};

#endif