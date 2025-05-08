//
// Created by Maroscsak Daniel on 5/8/2025.
//
#include <iostream>
#include "Customer/Customer.h"
#include "Employee/employee.h"
#include "Employee/EmployeeRepo.h"
using namespace std;

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
	return 0;
}