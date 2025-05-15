// CustomerMenu.cpp
#include "CustomerMenu.h"
#include <iostream>
#include "../Domain/Customer.h"

using namespace std;

void CustomerMenu::show() {
    int option;
    do {
        cout << "\nCustomer Menu:\n";
        cout << "1. View Profile\n";
        cout << "2. View Products (not implemented)\n";
        cout << "0. Logout\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
            case 1: {
                string email;
                cout << "Enter your email: ";
                cin >> email;
                User* user = userRepo.findUserByEmail(email);
                //dupa cauta userul mai am de facut
            }
            case 2:
                cout << "Feature not implemented.\n";//nu am facut functia nu am products
                break;
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (option != 0);
}
