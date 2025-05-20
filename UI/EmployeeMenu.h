
#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "LoginUI.h"
#include "../Repo/UserRepo.h"

class EmployeeMenu {
private:
    UserRepo& userRepo;
public:
    EmployeeMenu(UserRepo& repo) : userRepo(repo) {}

    EmployeeMenu(CustomerRepo customer_repo, const ProductRepo & product_repo);

    void show();
};

#endif
