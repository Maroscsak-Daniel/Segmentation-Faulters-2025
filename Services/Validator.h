//
// Created by Maroscsak Daniel on 5/3/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
using namespace std;


namespace Validate {
	bool validateID(const string& id);
	bool validateName(const string& name);
	bool validatePrice(double price);
	bool validateStock(int stock);
}



#endif //VALIDATOR_H
