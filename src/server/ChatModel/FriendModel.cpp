#include "FriendModel.h"
#include "MySQL.hpp"

FriendModel::FriendModel() {

}

bool FriendModel::insert(int userId, int friendId) {
    char sql[1024] = {0};
    sprintf(sql, "insert into friend value (%d,%d);", userId, friendId);
    MySQL mysql;
    if (mysql.connect()) {
        if (mysql.update(sql)) {
            return true;
        }
        return false;
    }
    return false;
}
    
//返回用户好友列表
vector<User> FriendModel::query(int userId) {
    char sql[1024] = {0};
    sprintf(sql, "select  a.id,a.name,a.state from user a inner join friend b on b.friendld = a.id  where b.userld=%d;", userId);
    vector<User> v;
    MySQL mysql;
    if (mysql.connect()) {
        MYSQL_RES *res =  mysql.query(sql);
        if (res != nullptr) {
            MYSQL_ROW row = mysql_fetch_row(res);
            while (row != nullptr) {
                User user;
                user.setUserId(atoi(row[0]));
                user.setUserName(row[1]);
                user.setUserState(atoi(row[2]));
                v.push_back(user);
                mysql_free_result(res);
            } 
        }
    }
    return v;
}
FriendModel::~FriendModel() {

}