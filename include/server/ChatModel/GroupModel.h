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
    GroupModel(/* args */);
    bool createGroup(Group &group);

    //加入群组
    bool addGroup(int userId, int group_id, string role);

    vector<Group> queryGroup(int userId);

    /*根据指定的用户id查询制定的群组里面的用户列表，返回该群组中除该用户外的列表*/
    vector<int> queryGroupUsers(int userId, int groupId);
    ~GroupModel();
};

GroupModel::GroupModel(/* args */)
{
}

GroupModel::~GroupModel()
{
}

#endif