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
	const vector<Product>& getAllProducts() const;
	bool productExists(const string& id) const;

	vector<Product> getAvailableProductsSortedByPrice() const;
};



#endif //PRODUCTREPO_H
