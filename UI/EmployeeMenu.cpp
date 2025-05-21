#include "EmployeeMenu.h"
#include "../Repo/EmployeeRepo.h"
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

                Employee emp(fn, ln, email, password, pos, bd, code, sal, remarks);

            //     if (!emp.isValidSalary() || !emp.isValidAge()) {
            //         cout << "Invalid employee data.\n";
            //     } else {
            //         try {
            //             // employeeRepo.addEmployee(emp);
            //             cout << "Employee added successfully.\n";
            //         } catch (const std::exception& ex) {
            //             cout << "Error adding employee: " << ex.what() << "\n";
            //         }
            //     }
            //     break;
            // }
            //
            // case 2: {
            //     // vector<Employee> employees = employeeRepo.getAllSorted();
            //     if (employees.empty()) {
            //         cout << "No employees found.\n";
            //     } else {
            //         for (const auto& e : employees) {
            //             cout << e.toString() << "\n";
            //         }
            //     }
            //     break;
            // }

            case 0:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (option != 0);
}
