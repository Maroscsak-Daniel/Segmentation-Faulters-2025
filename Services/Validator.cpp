//
// Created by Maroscsak Daniel on 5/3/2025.
//

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
}