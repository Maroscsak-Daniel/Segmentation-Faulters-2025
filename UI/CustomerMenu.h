#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "LoginUI.h"
#include "../Repo/Order_repo.h"
#include "../Repo/ProductRepo.h"

class CustomerMenu {
private:
    CustomerRepo& customer_repo;
    ProductRepo& product_repo;
    OrderRepository& order_repo;

public:
    explicit CustomerMenu(UserRepo& repo);

    CustomerMenu(CustomerRepo customer_repo, ProductRepo & product_repo, OrderRepository & order_repo);

    void show();
};

#endif // CUSTOMERMENU_H
