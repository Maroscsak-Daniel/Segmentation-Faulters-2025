#pragma once
#include "../Repo/UserRepo.h"
using namespace std;
class AuthService {
private:
    std::string lastError;
public:
    static bool login(UserRepo& userRepo, const std::string& email, const std::string& password);

    static User* findUserByEmail(UserRepo& userRepo, const std::string& email);

    bool registerUser(UserRepo& userRepo, const std::string& email, const std::string& password, const std::string& role);
    //unicitate email in conectare

    bool is_user_valid(const string& email, const string& password, const string& role);

    const std::string& getLastError() const;  // getter pentru mesajul de eroare

    bool changePassword(UserRepo& userRepo, const std::string& email, const std::string& oldPassword, const std::string& newPassword);
};
