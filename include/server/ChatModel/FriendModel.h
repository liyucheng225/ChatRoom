#ifndef FRIENDMODEL_H
#define FRIENDMODEL_H

#include <vector>
#include "User.h"

using namespace std;

//ά��������Ϣ�Ľṹ����
class FriendModel
{
public:
    //��Ӻ��ѹ�ϵ
    bool insert(int user_id, int friend_id);

    //�����û������б�
    vector<User> query(int user_id);
};

#endif