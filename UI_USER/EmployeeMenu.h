
#ifndef EMPLOYEEMENU_H
#define EMPLOYEEMENU_H

#include "../User/UserRepo.h"

class EmployeeMenu {
private:
    UserRepo& userRepo;
public:
    EmployeeMenu(UserRepo& repo) : userRepo(repo) {}
    void show();
};

#endif
