#pragma once
#include <string>

class User {
protected:
    std::string email;
    std::string password;
    std::string role;     // "customer", "employee"
    int Id;
    static int nextId;
public:
    User(std::string email, std::string password, std::string role);
     ~User() = default;

    std::string getEmail() const;
    std::string getRole() const;



    [[nodiscard]] int getId() const;

    void setEmail(const std::string& newEmail);
    void setPassword(const std::string& newPassword);
    void setRole(const std::string& newRole);
    [[nodiscard]] bool verifyPassword(const std::string& inputPassword) const;
};
