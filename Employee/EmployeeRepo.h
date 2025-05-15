//
// Created by Cezara on 03.05.2025.
//

#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H



#ifndef EMPLOYEE_REPOSITORY_H
#define EMPLOYEE_REPOSITORY_H

#include "Employee.h"
#include "../Customer/Customer.h"
#include "../Customer/CustomerRepo.h"
#include "../Customer/CustomerRepo.cpp"

#include <vector>

using namespace std;

class Employeerepo {
private:
	vector<Employee> employees;
	CustomerRepo& customerRepo;

public:
	bool emailExists(const string& email) const;
	bool codeExists(const string& shortCode) const;
	void addEmployee(const Employee& e);
	void updateEmployee(const string& email, const Employee& updated);
	void deleteEmployee(const string& email);

	Employee findByEmail(const string& email) const;
	Employee findByShortCode(const string& shortCode) const;
	vector<Employee> findByName(const string& lastName, const string& firstName) const;
	vector<Employee> findByBirthdateRange(const string& from, const string& to) const;
	vector<Customer> show_all_customers() const;

};

#endif




#endif //EMPLOYEEREPO_H
