// EmployeeMenu.cpp
#include "EmployeeMenu.h"
#include "../Domain/Employee.h"
#include <iostream>

using namespace std;

void EmployeeMenu::show() {
    int option;
    do {
        cout << "\nEmployee Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. List All Employees\n";
        cout << "0. Logout\n";
        cout << "Choose option: ";
        cin >> option;

        switch (option) {
            case 1: {
                string fn, ln, email, password, pos, bd, code, remarks;
                double sal;
                cout << "First name: "; cin >> fn;
                cout << "Last name: "; cin >> ln;
                cout << "Email: "; cin >> email;
                cout << "Password: "; cin >> password;
                cout << "Position: "; cin >> pos;
                cout << "Birthdate (dd.mm.yyyy): "; cin >> bd;
                cout << "Short code: "; cin >> code;
                cout << "Salary: "; cin >> sal;
                cout << "Remarks: "; cin.ignore(); getline(cin, remarks);

                Employee* emp = new Employee(fn, ln, email, password, pos, bd, code, sal, remarks);
                if (!emp->isValidSalary() || !emp->isValidAge()) {
                    cout << "Invalid employee data.\n";
                    delete emp;
                } else {
                    //adaugare user
                }
                break;
            }
            case 2:
               //neimplementat get all users
            case 0:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (option != 0);
}
