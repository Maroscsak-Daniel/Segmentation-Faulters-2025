#include "Validator.h"
#include <cctype>
#include <ctime>

namespace Validate {

	bool validateProductID(const string& id) {
		if (id.empty()) return false;
		for (char ch : id) {
			if (!isalnum(ch)) return false;
		}
		return true;
	}

	bool validateName(const string& name) {
		return !name.empty();
	}

	bool validatePrice(double price) {
		return price >= 0;
	}

	bool validateStock(int stock) {
		return stock >= 0;
	}

	bool validateDate(const string& date) {
		// Format check: "YYYY-MM-DD"
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

		for (int i = 0; i < date.size(); ++i) {
			if (i == 4 || i == 7) continue;
			if (!isdigit(date[i])) return false;
		}

		// Convert to int
		int year = stoi(date.substr(0, 4));
		int month = stoi(date.substr(5, 2));
		int day = stoi(date.substr(8, 2));

		if (month < 1 || month > 12 || day < 1) return false;

		int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// Leap year adjustment
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			daysInMonth[1] = 29;

		if (day > daysInMonth[month - 1])
			return false;

		time_t t = time(0);
		tm* today = localtime(&t);

		int currentYear = today->tm_year + 1900;
		int currentMonth = today->tm_mon + 1;
		int currentDay = today->tm_mday;

		if (year < currentYear)
			return false;
		if (year == currentYear) {
			if (month < currentMonth)
				return false;
			if (month == currentMonth)
				if (day < currentDay)
					return false;
		}

		return true;
	}

	bool validateStatus(Status status) {
		switch (status) {
			case Status::Reservation:
			case Status::Confirmed:
			case Status::Completed:
				return true;
			default:
				return false;
		}
	}

	bool validateEmployee(const string& employee) {
		return !employee.empty();  // optionally add stricter checks
	}

	bool validateCustomer(const string& customer) {
		return !customer.empty();  // optionally add stricter checks
	}

	bool validateOrderID(const string& orderID) {
		if (orderID.empty()) return false;
		for (char ch : orderID) {
			if (!isalnum(ch)) return false;
		}
		return true;
	}

	bool validateProducts(Product product) {
		return validateName(product.getName()) &&
			   validatePrice(product.getPrice()) &&
			   validateStock(product.getStock()) &&
			   validateDate(product.getDate()) &&
			   validateProductID(product.getId());
	}

	bool validateTotalAmount(double amount) {
		return amount >= 0;
	}

	//Validator Customer:
	bool isValidEmail(const string& email) {
		// one "@" and at least one "."
		size_t at = email.find('@');
		if (at == -1 || at == 0 || at == email.size() - 1)
			return false;

		size_t dot = email.find('.', at);
		return dot != -1 && dot < email.size() - 1;
	}

	bool isValidPassword(const string& password) {
		if (password.length() < 4) return false;

		bool hasDigit = false;
		bool hasUpper = false;

		for (const char ch : password) {
			if (std::isdigit(ch)) hasDigit = true;
			if (std::isupper(ch)) hasUpper = true;
		}

		return hasDigit && hasUpper;
	}

	bool isValidRole(const std::string& role) {
		return role == "employee" ||
			   role == "customer";
	}

	bool isValidPhone(const string& phone) {
		// only numbers allowed, "+" is optional
		if (phone.empty()) return false;

		size_t start = (phone[0] == '+') ? 1 : 0;
		if (phone.length() - start < 6) return false; // ! at least 6 digits

		for (size_t i = start; i < phone.size(); ++i) {
			if (!isdigit(phone[i]) && phone[i] != ' ')
				return false;
		}
		return true;
	}

	bool isValidAddress(const string& address) {
		return !address.empty();
	}



	bool isNonEmpty(const string& field) {
		return !field.empty();
	}

	bool isValidSalary(const double& salary){
		return salary >= 100;
	}

	// Validation: age between 0 and 80
	bool isValidAge(const int& age){
		return age >= 0 && age <= 80;
	}

}