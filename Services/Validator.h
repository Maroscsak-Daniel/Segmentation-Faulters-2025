//
// Created by Maroscsak Daniel on 5/3/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include "../Domain/Order.h"
using namespace std;


namespace Validate {
	bool validateProductID(const string& id);
	bool validateName(const string& name);
	bool validatePrice(double price);
	bool validateStock(int stock);
	bool validateDate(const string& date);

	bool validateStatus(Status status);
	bool validateEmployee(string employee);
	bool validateCustomer(string customer);
	bool validateOrderID(string orderID);
	bool validateProducts(Product product);
	bool validateTotalAmount(double amount);
	// will have to validate order date -> make it so it uses the YYYY-MM-DD string format
}



#endif //VALIDATOR_H
