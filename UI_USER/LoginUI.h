#ifndef LOGINUI_H
#define LOGINUI_H

#include "../User/UserRepo.h"

class LoginUI {
public:
    void displayLoginMenu();

private:
    UserRepo userRepo;

    void showMenuBasedOnRole(const std::string& role);
    void showEmployeeMenu();
    void showCustomerMenu();
};

#endif // LOGINUI_H
