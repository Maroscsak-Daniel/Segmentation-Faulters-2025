//
// Created by Maroscsak Daniel on 5/8/2025.
//
#include <iostream>
#include "User/UserRepo.h"
#include "User/UserServices.h"
using namespace std;
void teste();
int main() {
	// cout << "End my suffering" << endl;
 //    return 0;

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