//
// Created by Cezara on 03.05.2025.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "User.h"
#include <iostream>
#include <string>

using namespace std;

class Employee: public User {
private:
	string firstName;
	string lastName;
	string email;         // must be unique
	string position;      // optional
	string birthDate;     // format: dd.mm.yyyy
	string shortCode;     // must be unique
	double salary;        // ≥ 100 EUR
	string remarks;       // optional

public:
	// Constructors
	Employee();
	Employee(const string& firstName,
		 const string& lastName,
		 const string& email,
		 const string& password,
		 const string& position,
		 const string& birthDate,
		 const string& shortCode,
		 double salary,
		 const string& remarks);



	// Getters
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	string getPosition() const;
	string getBirthDate() const;
	string getShortCode() const;
	double getSalary() const;
	string getRemarks() const;

	// Setters
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setEmail(const string& email);
	void setPosition(const string& position);
	void setBirthDate(const string& birthDate);
	void setShortCode(const string& shortCode);
	void setSalary(double salary);
	void setRemarks(const string& remarks);

	// Validation
	bool is_employee_valid() const;
	int getAge() const;           // calculated from birthDate

	// Utility
	string toString() const;

	// Output stream overload
	friend ostream& operator<<(ostream& os, const Employee& e);
};

#endif // EMPLOYEE_H

