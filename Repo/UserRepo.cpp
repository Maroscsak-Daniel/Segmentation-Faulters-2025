#include "../Repo/UserRepo.h"

void UserRepo::addUser(const User& user) {
    users.push_back(user);
}

User* UserRepo::findUserByEmail(const std::string& email) {
    for (auto& user : users) {
        if (user.getEmail() == email) {
            return &user;
        }
    }
    return nullptr;
}