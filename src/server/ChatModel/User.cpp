#include "User.h"

User::User(string userId, string userName, string userPasswd, int index, bool state) {
    this->userId =userId;
    this->userName = userName;
    this->userPasswd = userPasswd;
    this->state = state;
    this->questionIndex = index;
    this->answer = answer;
}
string User::getUserId() {
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
int User::getUserQuestionIndex() {
    return questionIndex;
}
string User::getUserAnswer() {
    return answer;
}
void User::setUserQuestionIndex(int index) {
    this->questionIndex = index;
}
void User::setUserAnswer(string answer) {
    this->answer = answer;
}

void User::setUserName(string userName) {
    this->userName = userName;
}

void User::setUserPasswd(string userPasswd) {
    this->userPasswd = userPasswd;
}

void User::setUserId(string userId) {
    this->userId = userId;
}

void User::setUserState(bool state) {
    this->state = state;
}   
User::User() {

}
User::~User() {

}