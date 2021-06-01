#ifndef GROUPMODEL_H
#define GROUPMODEL_H

#include "Group.h"
#include <vector>
#include <string>
using namespace std;

class GroupModel
{
private:
    /* data */
public:
    bool createGroup(Group &group);

    //����Ⱥ��
    bool addGroup(int userId, int groupId, string role);

    vector<Group> queryGroup(int userId);

    /*����ָ�����û�id��ѯ�ƶ���Ⱥ��������û��б����ظ�Ⱥ���г����û�����б�*/
    vector<int> queryGroupUsers(int userId, int groupId);
    bool queryId(int id);
};

#endif