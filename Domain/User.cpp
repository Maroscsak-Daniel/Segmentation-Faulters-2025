#include "User.h"
#include <utility>
#include <string>

int User::nextId = 1;

User::User(std::string email, std::string password, std::string role)
    : Id(nextId++), email(std::move(email)), password(std::move(password)), role(std::move(role)) {}

std::string User::getEmail() const { return email; }
std::string User::getRole() const { return role; }

int User::getId() const { return Id; }


bool User::verifyPassword(const std::string& inputPassword) const {
    return password == inputPassword;
}

void User::setEmail(const std::string& newEmail) {
    email = newEmail;
}

void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}
void User::setRole(const std::string& newRole) {
    role = newRole;
}
