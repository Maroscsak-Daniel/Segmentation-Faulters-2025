
//
// Created by Maroscsak Daniel on 5/3/2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H


#include <iostream>
using namespace std;


class Product {
private:
	string id;
	string name;
	double price;
	int stock;
public:
	Product(const string& id, const string& name, double price, int stock);

	string getId() const;
	string getName() const;
	double getPrice() const;
	int getStock() const;

	void setName(const string& newName);
	void setPrice(double newPrice);
	void setStock(int newStock);
	int getQuantity() const { return stock; }


	bool isValidProductID() const;
	bool isValidStock() const;
	bool isValidPrice() const;
};



#endif //PRODUCT_H
