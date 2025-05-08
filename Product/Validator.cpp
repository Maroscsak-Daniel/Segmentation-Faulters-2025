//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "Validator.h"
#include <cctype>

bool Validator::validateId(const string& id) {
	if (id.empty()) return false;
	for (char ch : id) {
		if (!isalnum(ch)) return false;
	}
	return true;
}

bool Validator::validateName(const string& name) {
	return !name.empty();
}

bool Validator::validatePrice(double price) {
	return price >= 0;
}

bool Validator::validateStock(int stock) {
	return stock >= 0;
}