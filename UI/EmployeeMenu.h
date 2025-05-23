
#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "LoginUI.h"
#include "../Repo/CustomerRepo.h"
#include "../Repo/EmployeeRepo.h"

class EmployeeMenu {
private:
    CustomerRepo& customer_repo;
    ProductRepo& product_repo;
    EmployeeRepo& employeeRepo;
    OrderRepository& order_repo;
public:
    EmployeeMenu(CustomerRepo& customer_repo, ProductRepo& product_repo, EmployeeRepo& employeeRepo, OrderRepository& order_repo);
    void show() const;
};

#endif
