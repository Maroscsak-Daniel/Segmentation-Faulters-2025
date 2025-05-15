
#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "../Repo/UserRepo.h"

class CustomerMenu {
private:
    UserRepo& userRepo;
public:
    CustomerMenu(UserRepo& repo) : userRepo(repo) {}
    void show();
};

#endif
