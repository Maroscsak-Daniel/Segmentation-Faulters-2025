//
// Created by Maroscsak Daniel on 5/8/2025.
//
#include <iostream>

#include "Domain/Product.h"
#include "Repo/ProductRepo.h"
#include "Services/Validator.h"
#include "Domain/Customer.h"
#include "Domain/Employee.h"
#include "Repo/EmployeeRepo.h"
#include "Repo/UserRepo.h"
#include "Services/UserServices.h"
#include "UI/CustomerMenu.h"
#include "UI/EmployeeMenu.h"
#include "UI/LoginUI.h"


using namespace std;
using namespace Validate;

int main() {
	// cout << "End my suffering" << endl;
 //    return 0;

	Product p("Apfel", 1.5, 10, "2023-02-28");
	ProductRepo repo2; //															|
	//																				|
	string date = "2025-05-26"; //															|
	string name = "Apfel"; //														|
	double price = 1.5; //															| P1, P2, P3, P4 is done.
	int stock = 10; //																| Product Class done.
	//																				| Product Repo Class done.
	if (validateID(p.getId()) && validateName(p.getName()) //					| Created a Validator class for P4.
		&& validatePrice(p.getPrice()) && validateStock(p.getStock()) && validateDate(p.getDate())) { //	| You can now add Products to Repo.
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
	// cout << "=== TEST START ===" << endl;
	//
	// // Test Customer
	// Customer c("John", "Doe", "john.doe@example.com", "+123456789", "Main Street 1", "Important client", false);
	// cout << c << endl;
	//
	// // Anonymize and print again
	// c.anonymize(42);
	// cout << "After anonymization:\n" << c << endl;
	//
	// // Test Employee and EmployeeRepo
	// Employeerepo repo;
	// Employee e("Jane", "Smith", "jane.smith@example.com", "Developer", "15.06.1995", "JS95", 1500, "Senior dev");
	// try {
	// 	repo.addEmployee(e);
	// 	cout << "Added employee:\n" << e << endl;
	// } catch (const exception& ex) {
	// 	cerr << "Error adding employee: " << ex.what() << endl;
	// }
	//
	// cout << "=== TEST END ===" << endl;

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