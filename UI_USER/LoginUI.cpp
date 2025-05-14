//
// Created by user on 14.05.2025.
//
#include "LoginUI.h"
#include "../User/UserServices.h"  // pentru AuthService
#include <iostream>
#include "CustomerMenu.h"
#include "EmployeeMenu.h"

using namespace std;

void LoginUI::displayLoginMenu() {
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    if (AuthService::login(userRepo, email, password)) {
        User* user = userRepo.findUserByEmail(email);
        cout << "Login successful. Welcome! " << user->getRole() << "!\n";
        showMenuBasedOnRole(user->getRole());
    } else {
        cout << "Invalid email or password.\n";
    }
}

void LoginUI::showMenuBasedOnRole(const std::string& role) {
    if (role == "employee") {
        EmployeeMenu menu(userRepo);
        menu.show();
    } else if (role == "customer") {
        CustomerMenu menu(userRepo);
        menu.show();
    }
}
