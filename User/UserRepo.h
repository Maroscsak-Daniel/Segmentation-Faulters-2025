#pragma once
#include <vector>
#include "User.h"

class UserRepo {
private:
    std::vector<User> users;
public:
    void addUser(const User& user);
    User* findUserByEmail(const std::string& email);
};