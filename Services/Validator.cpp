#include "Validator.h"
#include <cctype>

namespace Validate {

	bool validateID(const string& id) {
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

		return day <= daysInMonth[month - 1];
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
}