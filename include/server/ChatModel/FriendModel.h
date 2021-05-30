#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <vector>
#include "User.h"
#include "MySQL.hpp"
using namespace std;

//维护好友信息的结构方法
class FriendModel
{
public:
    //添加好友关系
    bool insert(int userId, int friendId);
    
    //返回用户好友列表
    vector<User> query(int userId);
    FriendModel();
    ~FriendModel();
};

#endif