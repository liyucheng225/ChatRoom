#include "UserModel.h"

int UserModel::getUserId() {
    return userId;
}

string UserModel::getUserName() {
    return userName;
}

string UserModel::getUserPasswd() {
    return userPasswd;
}

bool UserModel::getUserstate() {
    return state;
}

void UserModel::setUserName(string userName) {
    this->userName = userName;
}
void UserModel::setUserPasswd(string userPasswd) {
    this->userPasswd = userPasswd;
}
void UserModel::setUserId(int userId) {
    this->userId = userId;
}
void UserModel::setUserState(bool state) {
    this->state = state;
}   