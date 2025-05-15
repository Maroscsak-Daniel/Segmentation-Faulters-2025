//
// Created by Cezara on 03.05.2025.
//
#ifndef CUSTOMER_REPO_H
#define CUSTOMER_REPO_H

#include "Customer.h"
#include <vector>

using namespace std;

class CustomerRepo {
private:
	vector<Customer> customers;


public:
	bool emailExists(const string& email) const;
	void addCustomer(const Customer& c);
	void updateCustomer(const string& email, const Customer& updated);
	void deleteCustomer(const string& email); // doar dacă nu a comandat
	void anonymizeCustomer(const string& email, int id);

	Customer findByEmail(const string& email) const;
	Customer findByPhone(const string& phone) const;
	vector<Customer> findByName(const string& lastName, const string& firstName) const;
	const vector<Customer>& getAllCustomers() const;
};

#endif
