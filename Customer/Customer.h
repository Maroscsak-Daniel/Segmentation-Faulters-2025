#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Customer {
private:
	static vector<Customer> customers;
	string firstName;
	string lastName;
	string email;        // must be unique, valid format
	string phone;        // format: + optional, digits, spaces
	string address;
	string remarks;      // optional if gdprDeleted == false
	bool gdprDeleted;

public:
	// Constructors
	Customer();
	Customer(const string& firstName,
			 const string& lastName,
			 const string& email,
			 const string& phone,
			 const string& address,
			 const string& remarks,
			 bool gdprDeleted = false);

	// Getters
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	string getPhone() const;
	string getAddress() const;
	string getRemarks() const;
	bool isGdprDeleted() const;

	// Setters
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setEmail(const string& email);
	void setPhone(const string& phone);
	void setAddress(const string& address);
	void setRemarks(const string& remarks);
	void setGdprDeleted(bool deleted);

	// GDPR anonymization (K2)
	void anonymize(int id); // sets fields as specified in K2

	// Validations (K5)
	bool isValidEmail() const;
	bool isValidPhone() const;
	bool isValid() const; // logic depending on gdprDeleted

	// Utilities
	string toString() const;
	friend ostream& operator<<(ostream& os, const Customer& c);


};

#endif
