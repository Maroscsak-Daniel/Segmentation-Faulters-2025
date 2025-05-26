//
// Created by Cezara on 03.05.2025.
//

#include "Employee.h"
#include <sstream>
#include <ctime>
#include "../Services/Validator.h"

//din email("") am schimbat in email(email);
Employee::Employee()
    : User("", "", "employee"),
      firstName(""), lastName(""), email(email), position(""),
      birthDate("01.01.1970"), shortCode(""), salary(100), remarks("") {}


// Parametrized constructor
Employee::Employee(const string& firstName,
                   const string& lastName,
                   const string& email,
                   const string& password,
                   const string& position,
                   const string& birthDate,
                   const string& shortCode,
                   double salary,
                   const string& remarks)
    : User(email, password, "employee"),
      firstName(firstName), lastName(lastName),
      position(position), birthDate(birthDate),
      shortCode(shortCode), salary(salary), remarks(remarks) {}


// Getters
string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }
string Employee::getEmail() const { return User::email; } //din return email am schimbat in return User::email
string Employee::getPosition() const { return position; }
string Employee::getBirthDate() const { return birthDate; }
string Employee::getShortCode() const { return shortCode; }
double Employee::getSalary() const { return salary; }
string Employee::getRemarks() const { return remarks; }

// Setters
void Employee::setFirstName(const string& fn) { firstName = fn; }
void Employee::setLastName(const string& ln) { lastName = ln; }
void Employee::setEmail(const string& em) { email = em; }
void Employee::setPosition(const string& pos) { position = pos; }
void Employee::setBirthDate(const string& bd) { birthDate = bd; }
void Employee::setShortCode(const string& sc) { shortCode = sc; }
void Employee::setSalary(double s) { salary = s; }
void Employee::setRemarks(const string& rm) { remarks = rm; }

// Validation: salary ≥ 100



bool Employee::is_employee_valid() const {
    int age = getAge();
    if (! Validate::isValidAge(age))
        return false;

    double salary = getSalary();
    if (! Validate::isValidSalary(salary))
        return false;

    return true;
}




// Calculate age based on birthDate (format: dd.mm.yyyy)
int Employee::getAge() const {
    int day, month, year;
    if (sscanf(birthDate.c_str(), "%d.%d.%d", &day, &month, &year) != 3) {
        return -1; // invalid format
    }

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int age = currentYear - year;
    if (month > currentMonth || (month == currentMonth && day > currentDay)) {
        age--;
    }

    return age;
}

// Convert to string
string Employee::toString() const {
    stringstream ss;
    ss << "Name: " << firstName << " " << lastName << "\n"
       << "Email: " << email << "\n"
       << "Position: " << position << "\n"
       << "Birth Date: " << birthDate << "\n"
       << "Short Code: " << shortCode << "\n"
       << "Salary: " << salary << " EUR\n"
       << "Remarks: " << remarks << "\n";
    return ss.str();
}

// Overload operator<<
ostream& operator<<(ostream& os, const Employee& e) {
    os << e.toString();
    return os;
}
