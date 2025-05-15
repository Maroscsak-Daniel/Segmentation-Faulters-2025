#include "User.h"

User::User(std::string email, std::string password, std::string role)
    : email(std::move(email)), password(std::move(password)), role(std::move(role)) {}

std::string User::getEmail() const { return email; }

std::string User::getRole() const { return role; }

bool User::verifyPassword(const std::string& inputPassword) const {
    return password == inputPassword;
}

bool User::hasOrderedProduct(const std::string& productID) const {
    for (const auto& p : orderedProducts) {
        if (p.getId() == productID) {
            return true;
        }
    }
    return false;
}

void User::addOrderedProduct(const Product& product) {
    orderedProducts.push_back(product);
}
