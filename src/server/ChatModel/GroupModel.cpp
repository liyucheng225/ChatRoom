#include "GroupModel.h"
#include "MySQL.hpp"
bool GroupModel::createGroup(Group &group)
{
    char sql[1024] = {0};
    sprintf(sql, "insert into chatgroup(groupId,groupName,groupDesc) values('%d','%s','%s');",
            group.getGroupId(), group.getGroupName().c_str(), group.getGroupDesc().c_str());
    MySQL mysql;
    if (mysql.connect()) {
        if (mysql.update(sql)) {
            return true;
        }
    }
    return false;

}

//加入群组
bool GroupModel::addGroup(int userId, int groupId, string role)
{   
    char sql[1024] = {0};
    sprintf(sql, "insert into groupuser(userId,groupId,groupRole)  values('%d','%d','%s');", userId , groupId , role.c_str());
    MySQL mysql;
    if (mysql.connect()) {
        if (mysql.update(sql)) {
            return true;
        }
    }
    return false;
}

//查询用户所在群组信息
vector<Group> GroupModel::queryGroup(int userId)
{
    //查询该用户所有的群组
    char sql[1024] = {0};
    sprintf(sql, "select a.groupId,a.groupName,a.groupDesc from chatgroup a inner join groupuser b on b.groupId=a.groupId where b.userId=%d;",userId);
    vector<Group> v;
    MySQL mysql;
    if (mysql.connect()) {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr) {
                cout << "查询群：" << row[0] << " " << row[1] << " " << row[2] << endl;
                Group group;
                group.setGroupId(atoi(row[0]));
                group.setGroupName(row[1]);
                group.setGroupoDesc(row[2]);
                v.push_back(group);
                cout << "群id:" << group.getGroupId() << ",name:" << group.getGroupName() << endl;
            }
            mysql_free_result(res);
        }
    }

     //查询所有群组所有群员的信息
    for (Group &temp : v)
    {
        sprintf(sql, "select a.id,a.name,a.state,b.groupRole from user a inner join groupuser b on b.userId=a.id where b.groupId=%d;", temp.getGroupId());
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr) {
                GroupUser groupUser;
                groupUser.setUserId(atoi(row[0]));
                groupUser.setUserName(row[1]);
                groupUser.setUserState(atoi(row[2]));
                groupUser.setRole(row[3]);
                temp.getUser().push_back(groupUser);
                cout << "群成员名称：";
                for (auto n : temp.getUser()) {
                    cout << "群成员名称1：" << n.getUserId() << endl;
                }
                cout << "群成员" << groupUser.getUserId() << "Name:" << groupUser.getUserName() <<endl;
            }
            mysql_free_result(res);
        }
    }
    return v;
}

/*根据指定的用户id查询制定的群组里面的用户列表，返回该群组中除该用户外的列表*/
vector<int> GroupModel::queryGroupUsers(int userId, int groupId)
{
     //组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "select userId  from groupuser where groupId=%d and userId != %d;", groupId, userId);

    vector<int> v;
    MySQL mysql;
    if (mysql.connect())
    {
        MYSQL_RES *res = mysql.query(sql);
        if (res != nullptr) {
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(res)) != nullptr) { 
                v.push_back(atoi(row[0]));
            }
            mysql_free_result(res);
        }
    }
    return v;
}
/*根据用户id查询id是否存在*/
bool GroupModel::queryId(int id) {
    char sql[1024] = {0};
    sprintf(sql, "select * from chatgroup where groupId=%d;", id);
    MySQL mysql;
    if (mysql.connect()) {
        MYSQL_RES * res = mysql.query(sql);
        if (res != nullptr) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr) {
                if (atoi(row[0]) == id) {
                    mysql_free_result(res);
                    return true;
                }          
            }
        }
    }
    return false;
}