
#include <iostream>
#include "User.h"
#include "UserRepo.h"
#include "UserServices.h"

void teste() {
    UserRepo repo;
    repo.addUser(User("test@email.com", "parola123", "customer"));

    std::cout << "[TEST 1] Login corect: ";
    if (AuthService::login(repo, "test@email.com", "parola123"))
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 2] Login gresit: ";
    if (!AuthService::login(repo, "alt@email.com", "parola123"))
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";
}
