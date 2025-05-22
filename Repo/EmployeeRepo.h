//
// Created by Cezara on 03.05.2025.
//

#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H



#ifndef EMPLOYEE_REPOSITORY_H
#define EMPLOYEE_REPOSITORY_H

#include "../Domain/Employee.h"
#include <vector>

using namespace std;

class Employeerepo {
private:
	vector<Employee> employees;

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

};

#endif




#endif //EMPLOYEEREPO_H
