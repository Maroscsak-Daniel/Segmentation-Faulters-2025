#pragma once
#include <vector>
#include "../Domain/User.h"

class UserRepo {
private:
    std::vector<User> users;
public:
    void addUser(const User& user);
    User* findUserByEmail(const std::string& email);
};