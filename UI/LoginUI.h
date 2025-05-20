#ifndef LOGINUI_H
#define LOGINUI_H

#include "../Repo/UserRepo.h"
#include "../Repo/ProductRepo.h"

class LoginUI {
private:
    UserRepo& userRepo;
public:
    bool displayLoginMenu();
    LoginUI(UserRepo& userRepoRef);
    void showMenuBasedOnRole(const std::string& role);
    void displayInitialMenu();
    void displayRegisterMenu();
    void showEmployeeMenu();
    void showCustomerMenu();
};

#endif // LOGINUI_H
