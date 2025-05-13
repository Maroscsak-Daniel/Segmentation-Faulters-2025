//
// Created by Maroscsak Daniel on 5/8/2025.
//
#include <iostream>

#include "Product/Product.h"
#include "Product/ProductRepo.h"
#include "Product/Validator.h"
#include "Customer/Customer.h"
#include "Employee/employee.h"
#include "Employee/EmployeeRepo.h"
#include "User/UserRepo.h"
#include "User/UserServices.h"
#include "Tests/UserTests.h"



using namespace std;
void testsUser();


int main() {
	// cout << "End my suffering" << endl;
 //    return 0;


	ProductRepo repo2; //															|
	//																				|
	string id = "A123"; //															|
	string name = "Apfel"; //														|
	double price = 1.5; //															| P1, P2, P3, P4 is done.
	int stock = 10; //																| Product Class done.
	//																				| Product Repo Class done.
	if (Validator::validateId(id) && Validator::validateName(name) //				| Created a Validator class for P4.
		&& Validator::validatePrice(price) && Validator::validateStock(stock)) { //	| You can now add Products to Repo.
		Product p(id, name, price, stock); //									|
		if (repo2.addProduct(p)) { //												| Feel free to delete or comment
			cout << "Produkt hinzugefugt.\n"; //									| this part of the code, it's here
		} else { //																	| just or debugging purposes to
			cout << "Produkt-ID bereits vorhanden.\n"; //							| check if everything works as
		} //																		| it should.
		} //																			|
	else { //																		|
		cout << "Ungultige Produktdaten.\n"; //										|
	} //																			|
	vector<Product> allProducts = repo2.getAvailableProductsSortedByPrice(); //		| P3, no print function yet tho.
  cout << endl;
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
		testsUser();
		return 0;
	}

	UserRepo repos;
	repos.addUser(User("admin@store.com", "parola123", "employee"));

	std::string email, password;
	std::cout << "Email: ";
	std::cin >> email;
	std::cout << "Password: ";
	std::cin >> password;

	if (AuthService::login(repos, email, password)) {
		std::cout << "Login successful!\n";
	} else {
		std::cout << "Invalid credentials.\n";
	}

	return 0;
}