#ifndef USERMODEL_H
#define USERMODEL_H

#include <iostream>
#include <string>
# include <stdlib.h>
using namespace std;

class User
{
public:
    User(int userId, string userName, string userPasswd, int questionIndex, int state, string answer);
    void setUserName(string userName);
    void setUserPasswd(string userPasswd);
    void setUserId(int userId);
    void setUserState(int state);
    void setUserQuestionIndex(int index);
    void setUserAnswer(string answer);

    int getUserId();
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
    int userId; //�û���¼�ʺ�
    string userPasswd; //�û�����
    int questionIndex;//�ܱ��������
    string answer; //�ܱ���
    int state; //�û�����״̬
};

#endif