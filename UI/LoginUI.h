#ifndef LOGINUI_H
#define LOGINUI_H

#include "../Repo/UserRepo.h"
#include "../Repo/ProductRepo.h"
#include "../Repo/CustomerRepo.h"

class LoginUI {
private:
    UserRepo& userRepo;
    CustomerRepo& customerRepo;
    ProductRepo& productRepo;
public:
    bool displayLoginMenu();
    LoginUI(UserRepo& ur, CustomerRepo& cr, ProductRepo& pr);
    void showMenuBasedOnRole(const std::string& role);
    void displayInitialMenu();
    void displayRegisterMenu();
    void showEmployeeMenu();
    void showCustomerMenu();
};

#endif // LOGINUI_H
