//
// Created by Cezara on 03.05.2025.
//

#include "Customer.h"
#include <sstream>
#include<iostream>
#include<regex>
#include<vector>

// Default constructor
#include "Customer.h"
#include <sstream>
#include <iostream>
#include <regex>
#include "../Services/Validator.h"


// Default constructor
Customer::Customer()
    : User("", "", "customer"),  // Inițializare de bază
      firstName(""), lastName(""), email(""),
      phone(""), address(""), remarks(""), gdprDeleted(false) {}

// Constructor complet (cu parolă)
Customer::Customer(const string& firstName,
                   const string& lastName,
                   const string& email,
                   const string& password,
                   const string& phone,
                   const string& address,
                   const string& remarks,
                   bool gdprDeleted)
    : User(email, password, "customer"),  // trimitem parola reală
      firstName(firstName), lastName(lastName),
      phone(phone), address(address),
      remarks(remarks), gdprDeleted(gdprDeleted) {
    this->email = email;  // deja inițializat în User, dar îl păstrezi și aici
}


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


bool Customer::isValid() const {
    if (gdprDeleted) {
        return Validate::isNonEmpty(firstName) &&
               Validate::isNonEmpty(lastName);
    }

    return Validate::isNonEmpty(firstName) &&
           Validate::isNonEmpty(lastName) &&
           Validate::isValidEmail(email) &&
           Validate::isValidPhone(phone) &&
           Validate::isValidAddress(address);
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


