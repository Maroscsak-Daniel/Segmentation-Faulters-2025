//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "ProductRepo.h"
#include <algorithm>

bool ProductRepo::productExists(const string& id) const {
	for (const auto& p : products) {
		if (p.getId() == id) return true;
	}
	return false;
}

bool ProductRepo::addProduct(const Product& product) {
	if (productExists(product.getId()))
		return false;  // ID must be unique
	products.push_back(product);
	return true;
}

const vector<Product>& ProductRepo::getAllProducts() const {
	return products;
}

vector<Product> ProductRepo::getAvailableProductsSortedByPrice() const {
	vector<Product> result;
	for (const auto& p : products) {
		if (p.getStock() > 0) {
			result.push_back(p);
		}
	}
	sort(result.begin(), result.end(),
			  [](const Product& a, const Product& b) {
				  return a.getPrice() < b.getPrice();
			  });
	return result;
}