//
// Created by Maroscsak Daniel on 5/3/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
using namespace std;


class Validator {
public:
	static bool validateId(const string& id);
	static bool validateName(const string& name);
	static bool validatePrice(double price);
	static bool validateStock(int stock);
};



#endif //VALIDATOR_H
