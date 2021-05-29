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
    string userName; //�û���
    string userId; //�û���¼�ʺ�
    string userPasswd; //�û�����
    int questionIndex;//�ܱ��������
    string answer; //�ܱ���
    bool state; //�û�����״̬
};

#endif