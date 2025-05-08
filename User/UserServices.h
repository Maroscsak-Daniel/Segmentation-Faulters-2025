#pragma once
#include "UserRepo.h"

class AuthService {
public:
    static bool login(UserRepo& userRepo, const std::string& email, const std::string& password);
};