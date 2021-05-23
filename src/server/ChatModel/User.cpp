#include "User.h"

int User::getUserId() {
    return userId;
}

string User::getUserName() {
    return userName;
}

string User::getUserPasswd() {
    return userPasswd;
}

bool User::getUserstate() {
    return state;
}

void User::setUserName(string userName) {
    this->userName = userName;
}

void User::setUserPasswd(string userPasswd) {
    this->userPasswd = userPasswd;
}

void User::setUserId(int userId) {
    this->userId = userId;
}

void User::setUserState(bool state) {
    this->state = state;
}   