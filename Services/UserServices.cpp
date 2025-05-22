#include "UserServices.h"

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

bool AuthService::registerUser(UserRepo& userRepo, const std::string& email, const std::string& password, const std::string& role) {
    if (userRepo.findUserByEmail(email) != nullptr) {
        lastError = "Email already in use.";
        return false;
    }

    if (!isValidPassword(password)) {
        lastError = "Password must have at least 4 characters, an uppercase letter, and a digit.";
        return false;
    }

    if (!isValidEmail(email)) {
        lastError = "Invalid email format.";
        return false;
    }

    if (!isValidRole(role)) {
        lastError = "Invalid role. Allowed roles are: employee, customer.";
        return false;
    }

    const User newUser(email, password, role);
    userRepo.addUser(newUser);
    lastError.clear();  // clear dacă totul a mers bine
    return true;
}


bool AuthService::isValidPassword(const std::string& password) {
    if (password.length() < 4) return false;

    bool hasDigit = false;
    bool hasUpper = false;

    for (const char ch : password) {
        if (std::isdigit(ch)) hasDigit = true;
        if (std::isupper(ch)) hasUpper = true;
    }

    return hasDigit && hasUpper;
}

bool AuthService::isValidEmail(const std::string& email) {
    const size_t atPos = email.find('@');
    if (atPos == std::string::npos) {
        // Nu există caracterul '@'
        return false;
    }

    if (email.find('@', atPos + 1) != std::string::npos) {
        // Există mai mult de un '@'
        //npos marcheaza poz invalida- am cautat
        return false;
    }

    size_t dotPos = email.find('.', atPos);
    if (dotPos == std::string::npos) {
        // Nu există '.' după '@'
        return false;
    }

    if (atPos == 0) {
        return false;
    }

    if (dotPos == email.length() - 1) {
        return false;
    }
    return true;
}
bool AuthService::isValidRole(const std::string& role) {
    return role == "employee" ||
           role == "customer";
}

const std::string& AuthService::getLastError() const {
    return lastError;
}

