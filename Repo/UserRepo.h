#pragma once
#include <vector>
#include "../Domain/User.h"

class UserRepo {
private:
    std::vector<User> users;
public:
    void addUser(const User& user);
    void removeUser(int id);
    void modifyUserData(int id, const std::string& newEmail, const std::string& newPassword, const std::string& newRole);
    std::vector<User> getUsers() const;
    User* findUserByEmail(const std::string& email);
};