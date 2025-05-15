#pragma once

#include <vector>
#include <string>
#include "User.h"
#include "../Order/Order_repo.h"

class UserRepo {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);
    User* findUserByEmail(const std::string& email);
    vector<User> getUsersByProduct(const std::string& productID, const OrderRepo& orderRepo) const;
};
