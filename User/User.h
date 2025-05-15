#pragma once

#include <string>
#include <vector>
#include "../Product/Product.h"

class User {
protected:
    std::string email;
    std::string password;
    std::string role;  // "customer", "employee"
    std::vector<Product> orderedProducts;

public:
    User(std::string email, std::string password, std::string role);
    virtual ~User() = default;

    std::string getEmail() const;
    std::string getRole() const;
    bool verifyPassword(const std::string& inputPassword) const;
    bool hasOrderedProduct(const std::string& productID) const;

    void addOrderedProduct(const Product& product);
};
