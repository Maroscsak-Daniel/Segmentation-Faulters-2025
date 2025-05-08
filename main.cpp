//
// Created by Maroscsak Daniel on 5/8/2025.
//
#include <iostream>
#include "Customer/Customer.h"
#include "Employee/employee.h"
#include "Employee/EmployeeRepo.h"
#include "User/UserRepo.h"
#include "User/UserServices.h"

using namespace std;
void teste();
int main() {
	// cout << "End my suffering" << endl;
 //    return 0;

	cout << "=== TEST START ===" << endl;

	// Test Customer
	Customer c("John", "Doe", "john.doe@example.com", "+123456789", "Main Street 1", "Important client", false);
	cout << c << endl;

	// Anonymize and print again
	c.anonymize(42);
	cout << "After anonymization:\n" << c << endl;

	// Test Employee and EmployeeRepo
	Employeerepo repo;
	Employee e("Jane", "Smith", "jane.smith@example.com", "Developer", "15.06.1995", "JS95", 1500, "Senior dev");
	try {
		repo.addEmployee(e);
		cout << "Added employee:\n" << e << endl;
	} catch (const exception& ex) {
		cerr << "Error adding employee: " << ex.what() << endl;
	}

	cout << "=== TEST END ===" << endl;
  
  
	int opt;
	std::cout << "1. Ruleaza aplicatia\n2. Ruleaza teste\nAlege: ";
	std::cin >> opt;

	if (opt == 2) {
		teste();
		return 0;
	}

	UserRepo repo;
	repo.addUser(User("admin@store.com", "parola123", "employee"));

	std::string email, password;
	std::cout << "Email: ";
	std::cin >> email;
	std::cout << "Password: ";
	std::cin >> password;

	if (AuthService::login(repo, email, password)) {
		std::cout << "Login successful!\n";
	} else {
		std::cout << "Invalid credentials.\n";
	}

	return 0;
}