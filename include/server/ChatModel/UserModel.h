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
    User query(string id);

    //����״̬��Ϣ
    bool updateState(User user);
    bool updateUser(User user);
    bool queryId(string id);

    //�����û�״̬��Ϣ
    bool reset_state();

    ~UserModel();
};


// #endif