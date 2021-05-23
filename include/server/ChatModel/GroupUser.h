#ifndef GROUPUSER_H
#define GROUPUSER_H
#include "User.h"

class GroupUser : public User
{
public:
    void setRole(string role);
    string getRole();
private:
    /* data */
    string role;
};

#endif