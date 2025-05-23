#include "UserServices.h"
#include "../Services/Validator.h"


bool AuthService::login(UserRepo& userRepo, const std::string& email, const std::string& password) {
    const User* user = userRepo.findUserByEmail(email);
    if (user && user->verifyPassword(password)) {
        return true;
    }
    return false;
}

User* AuthService::findUserByEmail(UserRepo& userRepo, const std::string& email) {
    return userRepo.findUserByEmail(email);
}


bool AuthService::is_user_valid(const string& email, const string& password, const string& role) {
    if (! Validate::isValidPassword(password)) {
        lastError = "Password must have at least 4 characters, an uppercase letter, and a digit.";
        return false;
    }

    if (!Validate::isValidEmail(email)) {
        lastError = "Invalid email format.";
        return false;
    }

    if (! Validate::isValidRole(role)) {
        lastError = "Invalid role. Allowed roles are: employee, customer.";
        return false;
    }
    return true;
}

bool AuthService::registerUser(UserRepo& userRepo, const std::string& email, const std::string& password, const std::string& role) {
    if (userRepo.findUserByEmail(email) != nullptr) {
        lastError = "Email already in use.";
        return false;
    }
    if (!is_user_valid(email, password, role))
        return false;

    const User newUser(email, password, role);
    userRepo.addUser(newUser);
    lastError.clear();  // clear dacă totul a mers bine
    return true;
}



bool AuthService::changePassword(UserRepo& userRepo, const std::string& email, const std::string& oldPassword, const std::string& newPassword) {
    User* user = userRepo.findUserByEmail(email);
    if (!user) {
        lastError = "User not found.";
        return false;
    }
    if (!user->verifyPassword(oldPassword)) {
        lastError = "Old password is incorrect.";
        return false;
    }

    if (!Validate::isValidPassword(newPassword)) {
        lastError = "New password is invalid. Must contain at least 4 characters, one uppercase letter and one digit.";
        return false;
    }

    user->setPassword(newPassword);
    return true;
}


const std::string& AuthService::getLastError() const {
    return lastError;
}


