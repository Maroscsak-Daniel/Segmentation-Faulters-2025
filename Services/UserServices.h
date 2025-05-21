#pragma once
#include "../Repo/UserRepo.h"

class AuthService {
private:
    std::string lastError;
public:
    static bool login(UserRepo& userRepo, const std::string& email, const std::string& password);

    static User* findUserByEmail(UserRepo& userRepo, const std::string& email);

    bool registerUser(UserRepo& userRepo, const std::string& email, const std::string& password, const std::string& role);
    //unicitate email in conectare

    static bool isValidPassword(const std::string& password);
    //validare structura parola, lungime 4 + o majuscula(macar) + o cifra(macar)

    static bool isValidEmail(const std::string& email);
    static bool isValidRole(const std::string& role);

    const std::string& getLastError() const;  // getter pentru mesajul de eroare

    bool changePassword(UserRepo& userRepo, const std::string& email, const std::string& oldPassword, const std::string& newPassword);
};
