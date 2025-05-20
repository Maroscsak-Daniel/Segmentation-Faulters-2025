//
// Created by Maroscsak Daniel on 5/20/2025.
//
#include <iostream>
#include "../Domain/Product.h"
#include "../Repo/ProductRepo.h"

void runProductTests() {
	Product prod1("001", "Tennis racket", 49.99, 9);
    Product prod2("002", "Footballs", 29.99, 5);

    cout << "\nTesting product setters..." << endl;
    prod1.setName("Tennis rackets");
    prod1.setPrice(59.99);
    prod1.setStock(10);
    if ((prod1.getName() == "Tennis rackets") && (prod1.getPrice() == 59.99) && (prod1.getStock() == 10))
    	cout << "Setter tests passed!\n" << endl;
    else {
    	cout << "Failure by editing product data: PRODUCT SETTERS TEST FAILED" << endl;
        exit(-1);
    }

    cout << "Testing Products..." << endl;
    if (prod1.getId() == "001" && prod1.getName() == "Tennis rackets" && prod1.getPrice() == 59.99 && prod1.getStock() == 10)
   		cout << "All product details are in order\n" << endl;
    else {
    	cout << "Failure by retrieving product data: PRODUCT TEST FAILED" << endl;
        exit(-1);
    }

    ProductRepo repo;
    cout << "Testing Product adding Repo..." << endl;
    if (repo.addProduct(prod1) == true && repo.addProduct(prod2) == true)
    	cout << "Products successfully added to repo\n" << endl;
    else {
    	cout << "Failure by adding products to repo: REPO ADD FAILED" << endl;
        exit(-1);
    }

    cout << "Testing Product existance in Repo... " << endl;
    if (repo.productExists("001") == true)
    	cout << "Product \"" << prod1.getName() << "\" already is in repo, all good\n" << endl;
    else {
    	cout << "Failure by checking product existance: REPO PRODUCTEXISTS FAILED" << endl;
        exit(-1);
    }

    const vector<Product>& products = repo.getAllProducts();
	cout << "Testing Product data fetching in Repo..." << endl;
    if ((products.size() == 2) &&
    	(products[0].getId() == "001") &&
    	(products[0].getName() == "Tennis rackets") &&
    	(products[0].getPrice() == 59.99) &&
    	(products[0].getStock() == 10) &&
    	(products[1].getId() == "002") &&
    	(products[1].getName() == "Footballs") &&
    	(products[1].getPrice() == 29.99) &&
    	(products[1].getStock() == 5))
    	cout << "Product data fetching successful\n" << endl;
    else {
    	cout << "Product data fetching failed: REPO TEST FAILED" << endl;
        exit(-1);
    }

    const vector<Product>& sortedProducts = repo.getAvailableProductsSortedByPrice();
	cout << "Testing Product sorting in Repo..." << endl;
    if ((sortedProducts[0].getId() == "002") && (sortedProducts[1].getId() == "001"))
    	cout << "Product data sorting successful\n" << endl;
    else {
    	cout << "Product data sorting failed: REPO TEST FAILED" << endl;
        exit(-1);
    }

    cout << "PRODUCT AND REPO TESTS PASSED" << endl;

}
