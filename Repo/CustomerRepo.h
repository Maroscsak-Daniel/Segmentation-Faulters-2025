//
// Created by Cezara on 03.05.2025.
//
#ifndef CUSTOMER_REPO_H
#define CUSTOMER_REPO_H

#include "../Domain/Customer.h"
#include <vector>

using namespace std;

class CustomerRepo {
private:
	static vector<Customer> customers;


public:
	bool emailExists(const string& email) const;
	void anonymizeCustomer(const string& email, int id);

	Customer findByEmail(const string& email) const;
	Customer findByPhone(const string& phone) const;
	vector<Customer> findByName(const string& lastName, const string& firstName) const;
	vector<Customer> getAllSorted() const;

	//CRUD

	void addCustomer(const Customer& customer);
	Customer findCustomer(const string& email);
	void updateCustomer(const Customer& customer);
	void deleteCustomer(const Customer& customer);
};

#endif
