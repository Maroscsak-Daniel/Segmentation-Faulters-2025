//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "Product.h"

Product::Product(string& id, string& name, double price, int stock)
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