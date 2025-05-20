#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "LoginUI.h"
#include "../Repo/UserRepo.h"

class CustomerMenu {
private:
    UserRepo& userRepo;

public:
    explicit CustomerMenu(UserRepo& repo);

    CustomerMenu(CustomerRepo customer_repo, const ProductRepo & product_repo);

    static void show();
};

#endif // CUSTOMERMENU_H
