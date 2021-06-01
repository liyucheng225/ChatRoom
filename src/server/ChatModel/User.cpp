#include "User.h"

User::User(int userId, string userName, string userPasswd, int index, int state, string answer) {
    this->userId =userId;
    this->userName = userName;
    this->userPasswd = userPasswd;
    this->state = state;
    this->questionIndex = index;
    this->answer = answer;
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

int User::getUserstate() {
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

void User::setUserId(int userId) {
    this->userId = userId;
}

void User::setUserState(int state) {
    this->state = state;
}   
User::User() {

}
User::~User() {

}