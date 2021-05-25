#include "User.h"

User::User(int userId, string userName, string userPasswd, bool state) {
    this->userId =userId;
    this->userName = userName;
    this->userPasswd = userPasswd;
    this->state = state;
}
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
User::User() {

}
User::~User() {

}