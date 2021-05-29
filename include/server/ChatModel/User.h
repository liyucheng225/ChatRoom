#ifndef USERMODEL_H
#define USERMODEL_H

#include <iostream>
#include <string>
# include <stdlib.h>
using namespace std;

class User
{
public:
    User(string userId, string userName, string userPasswd, int questionIndex, int state);
    void setUserName(string userName);
    void setUserPasswd(string userPasswd);
    void setUserId(string userId);
    void setUserState(int state);
    void setUserQuestionIndex(int index);
    void setUserAnswer(string answer);

    string getUserId();
    string getUserName();
    string getUserPasswd();
    int getUserstate();
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
    int state; //�û�����״̬
};

#endif