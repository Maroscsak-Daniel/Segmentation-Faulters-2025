//
// Created by Maroscsak Daniel on 5/3/2025.
//

#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#include "../Domain/Product.h"
#include <iostream>
#include <vector>
using namespace std;


class ProductRepo {
private:
	vector<Product> products;

public:
	bool addProduct(const Product& product);  // returns false if duplicate
	void load_sample_data() const;
	const vector<Product>& getAllProducts() const;
	bool productExists(const string& id) const;
	bool productIdExists(const string& id) const;

	bool updateProduct(const string& id, const Product& updatedProduct);

	bool deleteProduct(const string& id);

	vector<Product> getAvailableProductsSortedByPrice() const;

	Product getProductById(const string& id) const;
};



#endif //PRODUCTREPO_H
