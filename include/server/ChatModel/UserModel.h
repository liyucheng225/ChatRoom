// #ifndef USERMODEL_H
// #define USERMODEL_H

#include "./User.h"
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

    //重置用户状态信息
    bool reset_state();

    ~UserModel();
};


// #endif