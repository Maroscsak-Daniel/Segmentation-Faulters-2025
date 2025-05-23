//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "Product.h"
#include <string>

int Product::nextID = 1;

Product::Product(const string& name, double price, int stock, const string& date)
	: name(name), price(price), stock(stock), date(date) {
	id = 'P' + to_string(nextID++);
}

// Getters
string Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
int Product::getStock() const { return stock; }
string Product::getDate() const { return date; }

// Setters
void Product::setName(const string& newName) { name = newName; }
void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setStock(int newStock) { stock = newStock; }
void Product::setDate(const string& newDate) { date = newDate; }

string Product::toString() const {
	return "ID: " + id + " | Name: " + name + " | Price: " + to_string(price) +
		   " | Stock: " + to_string(stock) + " | Date: " + date;
}