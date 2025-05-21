//
// Created by Maroscsak Daniel on 5/3/2025.
//

#include "ProductRepo.h"
#include "../Domain/Product.h"
#include <algorithm>

bool ProductRepo::productExists(const string& id) const {
	for (const auto& p : products) {
		if (p.getId() == id) return true;
	}
	return false;
}

void ProductRepo::load_sample_data() const {
	vector<Product> products;
	products.emplace_back("Whole Wheat Bread", 6.50, 100, "2025-05-10");
	products.emplace_back("Feta Cheese", 12.30, 50, "2025-05-15");
	products.emplace_back("Electric Toothbrush", 79.99, 25, "2025-04-20");
	products.emplace_back("Ariel Liquid Detergent", 38.75, 40, "2025-04-30");
	products.emplace_back("Olive Oil 500ml", 22.40, 35, "2025-04-25");
	products.emplace_back("Vacuum Cleaner Bosch", 499.99, 10, "2025-04-10");

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

Product ProductRepo::getProductById(const string& id) const {
	for (const auto& p : products) {
		if (p.getId() == id)
			return p;
	}
	throw runtime_error("Product with ID " + id + " not found.");
}

bool ProductRepo::updateProduct(const string& id, const Product& updatedProduct) {
	for (auto& p : products) {
		if (p.getId() == id) {
			p.setName(updatedProduct.getName());
			p.setPrice(updatedProduct.getPrice());
			p.setStock(updatedProduct.getStock());
			p.setDate(updatedProduct.getDate());
			return true;
		}
	}
	return false;
}

bool ProductRepo::productIdExists(const std::string& id) const {
	for (const auto& p : products) {
		if (p.getId() == id)
			return true;
	}
	return false;
}

bool ProductRepo::deleteProduct(const string& id) {
	for (auto it = products.begin(); it != products.end(); ++it) {
		if (it->getId() == id) {
			products.erase(it);
			return true;
		}
	}
	return false;
}