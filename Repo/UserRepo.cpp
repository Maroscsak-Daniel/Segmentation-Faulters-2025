#include "../Repo/UserRepo.h"

#include <algorithm>
#include <iostream>
#include <bits/ostream.tcc>

void UserRepo::addUser(const User& user) {
    users.push_back(user);
}
void UserRepo::removeUser(int id) {
    auto it = std::find_if(users.begin(), users.end(),
                           [id](const User& user) { return user.getId() == id; });
    if (it != users.end()) {
        users.erase(it);
    } else {
        std::cout << "User with id " << id << " does not exist.\n";
    }
}

void UserRepo::modifyUserData(int id, const std::string& newEmail, const std::string& newPassword, const std::string& newRole) {
    for (auto& user : users) {
        if (user.getId() == id) {
            user.setEmail(newEmail);
            user.setPassword(newPassword);
            user.setRole(newRole);
            return;
        }
    }
    std::cout << "User does not exist" << std::endl;
}

std::vector<User> UserRepo::getUsers() const{
    return users;
}


User* UserRepo::findUserByEmail(const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            return &user;
        }
    }
    return nullptr;
}