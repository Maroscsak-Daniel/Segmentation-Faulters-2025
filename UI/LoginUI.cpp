#include "LoginUI.h"
#include "../Services/UserServices.h"
#include "../Repo/UserRepo.h"

#include "EmployeeMenu.h"
#include "CustomerMenu.h"

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

LoginUI::LoginUI(UserRepo &ur, CustomerRepo &cr, ProductRepo &pr, EmployeeRepo &em, OrderRepository &orr)
        : userRepo(ur), customerRepo(cr), productRepo(pr), employeeRepo(em), orderRepo(orr) {}

void printLine() {
    cout << "=========================================\n";
}

void LoginUI::displayInitialMenu() const {
    int choice = -1;
    while (choice != 0) {
        printLine();
        cout << setw(35) << right << "WELCOME TO THE APP\n";
        printLine();
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                if (displayLoginMenu())
                    return;
                break;
            case 2:
                displayRegisterMenu();
                break;
            case 0:
                cout << "Exiting application. Goodbye!\n";
                return;
            default:
                cout << "Invalid option, please try again.\n";
        }
    }
}

bool LoginUI::displayLoginMenu() const {
    int attempts = 3;
    while (attempts > 0) {
        printLine();
        cout << setw(30) << right << "LOGIN TO YOUR ACCOUNT\n";
        printLine();

        string email, password;
        cout << "Email    : ";
        cin >> email;
        cout << "Password : ";
        cin >> password;

        if (AuthService::login(userRepo, email, password)) {
            const User* user = userRepo.findUserByEmail(email);
            if (!user) {
                cout << "Unexpected error: User not found after login.\n";
                return false;
            }
            cout << "\nLogin successful. Welcome, " << user->getRole() << "!\n\n";
            showMenuBasedOnRole(user->getRole());
            return true;
        } else {
            attempts--;
            cout << "\nInvalid email or password.";
            if (attempts > 0)
                cout << " Please try again (" << attempts << " attempts left).\n\n";
            else
                cout << " No attempts left. Returning to main menu...\n\n";
        }
    }
    return false;
}

void LoginUI::displayRegisterMenu() const {
    printLine();
    cout << setw(32) << right << "REGISTER NEW USER\n";
    printLine();

    string email, password, role;

    cout << "Enter email: ";
    cin >> email;
    while (!AuthService::isValidEmail(email)) {
        cout << "Invalid email format. Try again: ";
        cin >> email;
    }

    cout << "Enter password (minimim 4 characters, 1 uppercase, 1 digit): ";
    cin >> password;
    while (!AuthService::isValidPassword(password)) {
        cout << "Password too weak. Try again: ";
        cin >> password;
    }

    cout << "Enter role (employee/customer): ";
    cin >> role;
    while (!AuthService::isValidRole(role)) {
        cout << "Invalid role. Please enter 'employee' or 'customer': ";
        cin >> role;
    }

    AuthService auth;
    const bool result = auth.registerUser(userRepo, email, password, role);
    if (!result) {
        cout << "Registration failed: " << auth.getLastError() << "\n\n";
        return;
    }

    if (role == "employee") {
        string firstName, lastName, position, birthdate, shortCode, remarks;
        double salary;

        cout << "First Name: "; cin >> firstName;
        cout << "Last Name: "; cin >> lastName;
        cout << "Position: "; cin >> position;
        cout << "Birthdate (dd.mm.yyyy): "; cin >> birthdate;
        cout << "Short Code: "; cin >> shortCode;
        cout << "Salary: "; cin >> salary;
        cout << "Remarks: "; cin.ignore(); getline(cin, remarks);

        Employee emp(firstName, lastName, email, password, position, birthdate, shortCode, salary, remarks);
        if (!emp.isValidSalary() || !emp.isValidAge()) {
            cout << "Invalid employee data.\n";
        } else {
            employeeRepo.addEmployee(emp);
            cout << "Employee registered successfully!\n";
        }

    } else if (role == "customer") {
        string firstName, lastName, phoneNumber, remarks,address ;
        bool gdpr;

        cout << "First Name: "; cin >> firstName;
        cout << "Last Name: "; cin >> lastName;
        cout << "Phone Number: "; cin >> phoneNumber;
        cout << "Address: "; cin >> address;
        cout << "Remarks: "; cin >> remarks;

        Customer customer(firstName, lastName, email, password, phoneNumber, address, remarks, gdpr);
        customerRepo.addCustomer(customer);
        cout << "Customer registered successfully!\n";
    }
}


void LoginUI::showEmployeeMenu() const {
    const EmployeeMenu menu(customerRepo, productRepo, employeeRepo, orderRepo);
    menu.show();
}

void LoginUI::showCustomerMenu() const {
    CustomerMenu menu(customerRepo, productRepo,orderRepo);
    menu.show();
}

void LoginUI::showMenuBasedOnRole(const std::string& role) const {
    if (role == "employee") {
        showEmployeeMenu();
    } else if (role == "customer") {
        showCustomerMenu();
    } else {
        cout << "Unknown user role: " << role << ". Cannot proceed.\n";
    }
}
