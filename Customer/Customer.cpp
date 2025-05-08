//
// Created by Cezara on 03.05.2025.
//

#include "Customer.h"
#include <sstream>
#include<iostream>
#include<regex>

// Default constructor
Customer::Customer()
    : firstName(""), lastName(""), email(""),
      phone(""), address(""), remarks(""), gdprDeleted(false) {}

// Parametrized constructor
Customer::Customer(const string& firstName,
                   const string& lastName,
                   const string& email,
                   const string& phone,
                   const string& address,
                   const string& remarks,
                   bool gdprDeleted)
    : firstName(firstName), lastName(lastName), email(email),
      phone(phone), address(address), remarks(remarks), gdprDeleted(gdprDeleted) {}

// Getters
string Customer::getFirstName() const { return firstName; }
string Customer::getLastName() const { return lastName; }
string Customer::getEmail() const { return email; }
string Customer::getPhone() const { return phone; }
string Customer::getAddress() const { return address; }
string Customer::getRemarks() const { return remarks; }
bool Customer::isGdprDeleted() const { return gdprDeleted; }

// Setters
void Customer::setFirstName(const string& fn) { firstName = fn; }
void Customer::setLastName(const string& ln) { lastName = ln; }
void Customer::setEmail(const string& em) { email = em; }
void Customer::setPhone(const string& ph) { phone = ph; }
void Customer::setAddress(const string& addr) { address = addr; }
void Customer::setRemarks(const string& rm) { remarks = rm; }
void Customer::setGdprDeleted(bool deleted) { gdprDeleted = deleted; }

// Anonimizare conform GDPR
void Customer::anonymize(int id) {
    lastName = "Kunde-" + to_string(id);
    firstName = "Unbekannt";
    email = "";
    phone = "";
    address = "";
    remarks = "";
    gdprDeleted = true;
}

// Validare email (format simplificat)
bool Customer::isValidEmail() const {
    const regex pattern(R"(^[\w\.-]+@[\w\.-]+\.\w{2,4}$)");
    return regex_match(email, pattern);
}

// Validare telefon
bool Customer::isValidPhone() const {
    const regex pattern(R"(^\+?[0-9 ]*$)");
    return regex_match(phone, pattern);
}

// Validare generală (K5)
bool Customer::isValid() const {
    if (gdprDeleted) {
        return !firstName.empty() && !lastName.empty();
    } else {
        return !firstName.empty() &&
               !lastName.empty() &&
               isValidEmail() &&
               isValidPhone() &&
               !phone.empty() &&
               !email.empty() &&
               !address.empty();
        // remarks poate fi gol
    }
}

// Afișare text
string Customer::toString() const {
    stringstream ss;
    ss << "Name: " << firstName << " " << lastName << "\n"
       << "Email: " << email << "\n"
       << "Phone: " << phone << "\n"
       << "Address: " << address << "\n"
       << "Remarks: " << remarks << "\n"
       << "GDPR Deleted: " << (gdprDeleted ? "true" : "false") << "\n";
    return ss.str();
}

// Supraincarcare operator <<
ostream& operator<<(ostream& os, const Customer& c) {
    os << c.toString();
    return os;
}
