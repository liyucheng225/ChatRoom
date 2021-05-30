#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <vector>
#include "User.h"
#include "MySQL.hpp"
using namespace std;

//ά��������Ϣ�Ľṹ����
class FriendModel
{
public:
    //��Ӻ��ѹ�ϵ
    bool insert(int userId, int friendId);
    
    //�����û������б�
    vector<User> query(int userId);
    FriendModel();
    ~FriendModel();
};

#endif