#include "UserRepo.h"
#include <set>

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

std::vector<User> UserRepo::getUsersByProduct(const std::string& productID, const OrderRepo& orderRepo) const {
    vector<User> result;
    set<std::string> foundEmails;

    for (const auto& order : orderRepo.getAllOrders()) {
        for (const auto& product : order.getProducts()) {
            if (product.getId() == productID) {
                const string& email = order.getCustomer();
                if (foundEmails.find(email) == foundEmails.end()) {
                    foundEmails.insert(email);

                    for (const auto& user : users) {
                        if (user.getEmail() == email) {
                            result.push_back(user);
                            break;
                        }
                    }
                }
            }
        }
    }

    return result;
}
