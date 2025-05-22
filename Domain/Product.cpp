//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "Product.h"

Product::Product(const string& id, const string& name, double price, int stock)
	: id(id), name(name), price(price), stock(stock) {}

string Product::getId() const {
	return id;
}

string Product::getName() const {
	return name;
}

double Product::getPrice() const {
	return price;
}

int Product::getStock() const {
	return stock;
}

void Product::setName(const string& newName) { name = newName; }
void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setStock(int newStock) { stock = newStock; }

bool Product::isValidProductID() const {
	if (id.empty())
		return false;

	for (char c : id) {
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
			return false;
	}

	return true;
}
bool Product::isValidStock() const {
	if (stock < 0)
		return false;
	return true;
}
bool Product::isValidPrice() const {
	if (price < 0)
		return false;
	return true;

}

