//
// Created by Maroscsak Daniel on 5/3/2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H


#include <iostream>
using namespace std;


class Product {

private:
	static int nextID;
	string id;
	string name;
	double price;
	int stock;
	string date;

public:
	Product(const string& name, double price, int stock, const string& date);

	string getId() const;
	string getName() const;
	double getPrice() const;
	int getStock() const;
	string getDate() const;

	void setName(const string& newName);
	void setPrice(double newPrice);
	void setStock(int newStock);
	void setDate(const string& newDate);

};



#endif //PRODUCT_H
