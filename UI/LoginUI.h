#ifndef LOGINUI_H
#define LOGINUI_H
#include "../Repo/UserRepo.h"
#include "../Repo/ProductRepo.h"
#include "../Repo/CustomerRepo.h"
#include "../Repo/EmployeeRepo.h"
#include "../Repo/Order_repo.h"

class LoginUI {
private:
    UserRepo& userRepo;
    CustomerRepo& customerRepo;
    ProductRepo& productRepo;
    EmployeeRepo& employeeRepo;
    OrderRepository& orderRepo;
public:
    bool displayLoginMenu() const;
    void showMenuBasedOnRole(const std::string& role) const;

    LoginUI(UserRepo &ur, CustomerRepo &cr, ProductRepo &pr, EmployeeRepo &em, OrderRepository &orr);

    void displayInitialMenu() const;
    void displayRegisterMenu() const;
    void showEmployeeMenu() const;
    void showCustomerMenu() const;
};

#endif // LOGINUI_H
