// Created by Cezara on 03.05.2025.
#include "EmployeeRepo.h"
#include<sstream>
#include<iostream>
#include <algorithm>
#include "../Services/Validator.h"

using namespace std;

bool Employeerepo::emailExists(const string& email) const {
      for( auto& e:employees){
        if(e.getEmail()==email)
              return true;

      }
      return false;
};

bool Employeerepo::codeExists(const string& shortCode) const {
    for( auto& e:employees){
        if(e.getShortCode()==shortCode)
            return true;

    }
    return false;
};

void Employeerepo::addEmployee(const Employee& e){
    if (emailExists(e.getEmail()))
        throw runtime_error("Email already exists.");
    if (codeExists(e.getShortCode()))
        throw runtime_error("Short code already exists.");
    if (! Validate::isValidSalary(e.getSalary()))
        throw runtime_error("Salary must be at least 100.");
    if (! Validate::isValidAge(e.getAge()))
        throw runtime_error("Age must be between 0 and 80.");

    employees.push_back(e);
};

void Employeerepo::updateEmployee(const string& email, const Employee& updated) {
    for (auto& e : employees) {
        if (e.getEmail() == email) {
            e = updated;
            return;
        }
    }
    throw runtime_error("Employee not found.");
}

Employee Employeerepo::findByEmail(const string& email) const {
    for(auto& e:employees){
        if(e.getEmail()==email)
            return e;
    }
}

Employee Employeerepo::findByShortCode(const string& ShortCode) const{
    for(auto& e:employees){
        if(e.getShortCode()==ShortCode)
            return e;
    }
}

vector<Employee> Employeerepo::findByName(const string& lastName, const string& firstName) const{
  vector<Employee> result;
  for(auto& e:employees){
    if(e.getLastName()==lastName && e.getFirstName()==firstName){
            result.push_back(e);
    }
  }
     return result;
}

vector<Employee> Employeerepo::findByBirthdateRange(const string& from, const string& to) const {
    vector<Employee> result;
    for (const auto& e : employees) {
        if (e.getBirthDate() >= from && e.getBirthDate() <= to)
            result.push_back(e);
    }
    return result;
}




