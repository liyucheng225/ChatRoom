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
    string userName; //�û���
    int userId; //�û���¼�ʺ�
    string userPasswd; //�û�����
    bool state; //�û�����״̬
};

#endif