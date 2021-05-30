// #ifndef USERMODEL_H
// #define USERMODEL_H

#include "User.h"
// class User;

class UserModel
{
public:
    UserModel(/* args */);
    
    /*����user*/
    bool insertUser(User &user);

    /*�����û�id��ѯuser��Ϣ*/
    User query(int id);

    //����״̬��Ϣ
    bool updateState(User user);
    bool updateUser(User user);
    bool queryId(int id);

    //�����û�״̬��Ϣ
    bool resetState(int state, int id);

    ~UserModel();
};


// #endif