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
#include "Domain/Order.h"
#include "Repo/Order_repo.h"

using namespace std;
using namespace Validate;

vector<Customer> testCustomers = {
	Customer("Alice", "Smith", "alice1@test.com", "Pass123", "+40712345678", "Strada A 1", "VIP", false),
	Customer("Bob", "Johnson", "bob2@test.com", "Secure9", "+40712345679", "Strada B 2", "Returning", false),
	Customer("Carol", "Williams", "carol3@test.com", "PassWord1", "+40712345680", "Strada C 3", "Frequent buyer", false),
	Customer("David", "Brown", "david4@test.com", "David22", "+40712345681", "Strada D 4", "", true),
	Customer("Eva", "Jones", "eva5@test.com", "Ev@Jones5", "+40712345682", "Strada E 5", "Newsletter", false),
	Customer("Frank", "Garcia", "frank6@test.com", "Frnk!234", "+40712345683", "Strada F 6", "", true),
	Customer("Grace", "Miller", "grace7@test.com", "Gra12345", "+40712345684", "Strada G 7", "Old customer", false),
	Customer("Henry", "Martinez", "henry8@test.com", "Henpass8", "+40712345685", "Strada H 8", "", true),
	Customer("Ivy", "Rodriguez", "ivy9@test.com", "IvyPwd9", "+40712345686", "Strada I 9", "New signup", false),
	Customer("Jack", "Lee", "jack10@test.com", "JLee2025", "+40712345687", "Strada J 10", "", true)
};

vector<Employee> testEmployees = {
	Employee("Elena", "Popescu", "elena1@firm.ro", "Admin123", "Manager", "15.05.1990", "E001", 3000, "Reliable"),
	Employee("Vlad", "Ionescu", "vlad2@firm.ro", "Secr3t", "Sales", "20.04.1985", "E002", 2200, ""),
	Employee("Mihai", "Georgescu", "mihai3@firm.ro", "Pass1234", "Developer", "10.12.1992", "E003", 2800, "Remote"),
	Employee("Ioana", "Stan", "ioana4@firm.ro", "Pwd2025", "HR", "05.11.1988", "E004", 2500, ""),
	Employee("Ana", "Iliescu", "ana5@firm.ro", "AnaIl1", "Support", "30.03.1993", "E005", 2100, ""),
	Employee("George", "Pop", "george6@firm.ro", "Geo_2025", "Logistics", "22.08.1980", "E006", 2700, ""),
	Employee("Cristina", "Dinu", "cristina7@firm.ro", "Cr1sT1na", "Manager", "18.06.1987", "E007", 3100, "New team"),
	Employee("Paul", "Tudor", "paul8@firm.ro", "Tudor#123", "Warehouse", "01.01.1990", "E008", 2000, ""),
	Employee("Roxana", "Muresan", "roxana9@firm.ro", "Roxie2025", "Finance", "14.07.1991", "E009", 2600, "Detail-oriented"),
	Employee("Alex", "Voicu", "alex10@firm.ro", "AlexP@ss", "Intern", "09.09.2000", "E010", 100, "Starter")
};

vector<User> testUsers = {
	// Customers
	User("alice1@test.com", "Pass123", "customer"),
	User("bob2@test.com", "Secure9", "customer"),
	User("carol3@test.com", "PassWord1", "customer"),
	User("david4@test.com", "David22", "customer"),
	User("eva5@test.com", "Ev@Jones5", "customer"),
	User("frank6@test.com", "Frnk!234", "customer"),
	User("grace7@test.com", "Gra12345", "customer"),
	User("henry8@test.com", "Henpass8", "customer"),
	User("ivy9@test.com", "IvyPwd9", "customer"),
	User("jack10@test.com", "JLee2025", "customer"),

	// Employees
	User("elena1@firm.ro", "Admin123", "employee"),
	User("vlad2@firm.ro", "Secr3t", "employee"),
	User("mihai3@firm.ro", "Pass1234", "employee"),
	User("ioana4@firm.ro", "Pwd2025", "employee"),
	User("ana5@firm.ro", "AnaIl1", "employee"),
	User("george6@firm.ro", "Geo_2025", "employee"),
	User("cristina7@firm.ro", "Cr1sT1na", "employee"),
	User("paul8@firm.ro", "Tudor#123", "employee"),
	User("roxana9@firm.ro", "Roxie2025", "employee"),
	User("alex10@firm.ro", "AlexP@ss", "employee")
};

vector<Product> testProducts = {
	Product("Paracetamol", 12.5, 100, "2025-06-01"),
	Product("Ibuprofen", 15.0, 80, "2025-06-15"),
	Product("Vitamin C", 8.9, 150, "2025-07-10"),
	Product("Antibiotic A", 25.5, 50, "2025-08-01"),
	Product("Cough Syrup", 18.75, 60, "2025-07-05"),
	Product("Nasal Spray", 9.5, 90, "2025-06-20"),
	Product("Bandages", 5.0, 200, "2026-01-01"),
	Product("Hand Sanitizer", 7.3, 120, "2025-12-12"),
	Product("Thermometer", 35.0, 30, "2027-03-01"),
	Product("Antiseptic Cream", 11.0, 75, "2026-09-25")
};

vector<Order> generateTestOrders(
	const vector<Product>& products,
	const vector<Customer>& customers,
	const vector<Employee>& employees
) {
	vector<Order> orders;

	vector<Product> p1 = { products[0], products[1] };
	vector<Product> p2 = { products[2] };
	vector<Product> p3 = { products[3], products[4] };
	vector<Product> p4 = { products[5], products[6] };
	vector<Product> p5 = { products[7] };
	vector<Product> p6 = { products[8], products[9] };
	vector<Product> p7 = { products[0] };
	vector<Product> p8 = { products[1], products[2] };
	vector<Product> p9 = { products[3] };
	vector<Product> p10 = { products[4], products[5] };

	orders.emplace_back("2025-05-25", Status::Confirmed, p1, customers[0].getEmail(), employees[0].getEmail());
	orders.emplace_back("2025-05-26", Status::Reservation, p2, customers[1].getEmail(), employees[1].getEmail());
	orders.emplace_back("2025-05-27", Status::Completed, p3, customers[2].getEmail(), employees[2].getEmail());
	orders.emplace_back("2025-05-28", Status::Confirmed, p4, customers[3].getEmail(), employees[3].getEmail());
	orders.emplace_back("2025-05-29", Status::Reservation, p5, customers[4].getEmail(), employees[4].getEmail());
	orders.emplace_back("2025-05-30", Status::Completed, p6, customers[5].getEmail(), employees[5].getEmail());
	orders.emplace_back("2025-06-01", Status::Reservation, p7, customers[6].getEmail(), employees[6].getEmail());
	orders.emplace_back("2025-06-02", Status::Confirmed, p8, customers[7].getEmail(), employees[7].getEmail());
	orders.emplace_back("2025-06-03", Status::Completed, p9, customers[8].getEmail(), employees[8].getEmail());
	orders.emplace_back("2025-06-04", Status::Confirmed, p10, customers[9].getEmail(), employees[9].getEmail());

	return orders;
}

int main() {
	UserRepo userRepo;
	for (const auto& u : testUsers)
		userRepo.addUser(u);

	CustomerRepo customerRepo;
	ProductRepo productRepo;
	EmployeeRepo employeeRepo;

	OrderRepository orderRepo;
	auto testOrders = generateTestOrders(testProducts, testCustomers, testEmployees);
	for (const auto& order : testOrders)
		orderRepo.createOrder(order.getorderDate(), order.getProducts(), order.getCustomer(), order.getEmployee(), order.getStatus());

	for (const auto& c : testCustomers)
		customerRepo.addCustomer(c);

	for (const auto& e : testEmployees)
		employeeRepo.addEmployee(e);

	for (const auto& p : testProducts)
		productRepo.addProduct(p);

	// Optional: print to check everything loaded
	// for (const auto& u : users) cout << u.getEmail() << endl;

	LoginUI ui(userRepo, customerRepo, productRepo, employeeRepo, orderRepo);
	ui.displayInitialMenu();

	return 0;
}