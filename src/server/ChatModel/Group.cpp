#include "Group.h"

Group::Group(int id, string name, string desc){
    this->groupId = id;
    this->groupName = name;
    this->desc = desc;
}
void Group::setGroupId(int groupId) {
    this->groupId = groupId;
}
void Group::setGroupName(string groupName) {
    this->groupName = groupName;
}
void Group::setGroupoDesc(string desc) {
    this->desc = desc;
}
int Group::getGroupId() {
    return groupId;
}
string Group::getGroupDesc() {
    return desc;
}
string Group::getGroupName() {
    return groupName;
}
vector<GroupUser> &Group::getUser() {

    return user;
}
Group::Group() {

}
Group::~Group() {
    
}