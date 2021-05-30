#include "UserModel.h"
#include "../../../include/server/dbModel/MySQL.hpp"
UserModel::UserModel(/* args */) {

}
/*增加user*/
bool UserModel::insertUser(User &user) {
    char sql[1024] = {0};
    /*组装sql语句*/
    sprintf(sql,"insert into user(id, passwd, name, state, question, answer) values('%d', '%s','%s','%d','%d','%s');", 
            user.getUserId(),user.getUserPasswd().c_str(), user.getUserName().c_str(), user.getUserstate(), 
            user.getUserQuestionIndex(), user.getUserAnswer().c_str());
    MySQL mysql;
    if (mysql.connect()) {
        if(mysql.update(sql)) {
            return true;
        }
    }
    return false;

}

/*根据用户id查询user信息*/
User UserModel::query(int id) {
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id=\"%d\";", id);
    MySQL mysql;
    if (mysql.connect()) {
        MYSQL_RES * res = mysql.query(sql);
        if (res != nullptr) {
            MYSQL_ROW row = mysql_fetch_row(res);
            if (row != nullptr) {
                User user;
                user.setUserId(atoi(row[0]));
                user.setUserPasswd(row[1]);
                user.setUserName(row[2]);
                user.setUserState(atoi(row[3]));
                mysql_free_result(res);
                return user;
            }
        }
    }
    return User();
}

//更新状态信息
bool UserModel::updateState(User user) {
    //组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "update user set state='%d'  where id=%d;", user.getUserstate(), user.getUserId());
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            cout << "update" << endl;
            return true;
        }
    }
    return false;
}
bool UserModel::updateUser(User user) {
    //组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "update user set name='%s',passwd = '%s'  where id=%d;", 
            user.getUserName().c_str(), user.getUserPasswd().c_str(), user.getUserId());
    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;

}
/*根据用户id查询id是否存在*/
bool UserModel::queryId(int id) {
    char sql[1024] = {0};
    sprintf(sql, "select * from user where id=%d;", id);
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
//重置用户状态信息
bool UserModel::resetState(int state, int id) {
      //组装SQL语句
    char sql[1024] = {0};
    sprintf(sql, "update user set state=%d where id=%d;", state, id);
    //cout << sql << endl;

    MySQL mysql;
    if (mysql.connect())
    {
        if (mysql.update(sql))
        {
            return true;
        }
    }
    return false;
}

UserModel::~UserModel() {

}