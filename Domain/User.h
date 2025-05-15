#pragma once
#include <string>

class User {
protected:
    std::string email;
    std::string password;
    std::string role;  // "customer", "employee"
public:
    User(std::string  email, std::string  password, std::string  role);
    virtual ~User() = default;

    [[nodiscard]] std::string getEmail() const;
    [[nodiscard]] std::string getRole() const;
    [[nodiscard]] bool verifyPassword(const std::string& inputPassword) const;
};