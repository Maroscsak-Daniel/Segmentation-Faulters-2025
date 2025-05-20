#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "../Repo/UserRepo.h"

class CustomerMenu {
private:
    UserRepo& userRepo;

public:
    explicit CustomerMenu(UserRepo& repo);

    static void show();
};

#endif // CUSTOMERMENU_H
