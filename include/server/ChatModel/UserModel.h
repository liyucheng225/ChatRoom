// #ifndef USERMODEL_H
// #define USERMODEL_H

#include "User.h"
// class User;

class UserModel
{
public:
    UserModel(/* args */);
    
    /*增加user*/
    bool insertUser(User &user);

    /*根据用户id查询user信息*/
    User query(int id);

    //更新状态信息
    bool updateState(User user);
    bool updateUser(User user);
    bool queryId(int id);

    //重置用户状态信息
    bool resetState(int state, int id);

    ~UserModel();
};


// #endif