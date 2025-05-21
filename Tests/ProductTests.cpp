#include <iostream>
#include "../Domain/Product.h"
#include "../Repo/ProductRepo.h"
#include "../Services/Validator.h"

void runProductTests() {
	Product prod1("Tennis racket", 49.99, 9, "2025-03-01");
	Product prod2("Footballs", 29.99, 5, "2026-05-26");

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
	if (prod1.getId() == "P1" && prod1.getName() == "Tennis rackets" && prod1.getPrice() == 59.99 && prod1.getStock() == 10)
		cout << "All product details are in order\n" << endl;
	else {
		cout << "Failure by retrieving product data: PRODUCT TEST FAILED" << endl;
		exit(-1);
	}

	ProductRepo repo;
	cout << "Testing Product adding Repo..." << endl;
	if (repo.addProduct(prod1) && repo.addProduct(prod2))
		cout << "Products successfully added to repo\n" << endl;
	else {
		cout << "Failure by adding products to repo: REPO ADD FAILED" << endl;
		exit(-1);
	}

	cout << "Testing Product existence in Repo... " << endl;
	if (repo.productExists("P1"))
		cout << "Product \"" << prod1.getName() << "\" already is in repo, all good\n" << endl;
	else {
		cout << "Failure by checking product existence: REPO PRODUCT EXISTS FAILED" << endl;
		exit(-1);
	}

	const vector<Product>& products = repo.getAllProducts();
	cout << "Testing Product data fetching in Repo..." << endl;
	if ((products.size() == 2) &&
		(products[0].getId() == "P1") &&
		(products[0].getName() == "Tennis rackets") &&
		(products[0].getPrice() == 59.99) &&
		(products[0].getStock() == 10) &&
		(products[1].getId() == "P2") &&
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
	if ((sortedProducts[0].getId() == "P2") && (sortedProducts[1].getId() == "P1"))
		cout << "Product data sorting successful\n" << endl;
	else {
		cout << "Product data sorting failed: REPO TEST FAILED" << endl;
		exit(-1);
	}

	cout << "Testing Product date setter and getter..." << endl;
	prod1.setDate("2025-05-20");
	if (prod1.getDate() == "2025-05-20")
		cout << "Date set/get passed!\n" << endl;
	else {
		cout << "Date set/get failed: DATE SETTER TEST FAILED" << endl;
		exit(-1);
	}

	cout << "Testing date validity (format + logic)..." << endl;
	Product validDateProd("Shoes", 89.99, 4, "2024-02-29"); // leap year
	Product invalidFormat("Cap", 15.99, 2, "20240529");      // bad format
	Product invalidLogic("Sneakers", 79.99, 3, "2023-02-30");// invalid day

	if (Validate::validateDate(validDateProd.getDate()))
		cout << "Valid date passed!\n";
	else {
		cout << "Valid date failed: DATE VALIDATION FAILED" << endl;
		exit(-1);
	}

	if (!Validate::validateDate(invalidFormat.getDate()))
		cout << "Invalid format correctly rejected\n";
	else {
		cout << "Invalid format passed: DATE FORMAT CHECK FAILED" << endl;
		exit(-1);
	}

	if (!Validate::validateDate(invalidLogic.getDate()))
		cout << "Invalid logic correctly rejected\n" << endl;
	else {
		cout << "Invalid logic passed: DATE LOGIC CHECK FAILED" << endl;
		exit(-1);
	}

	cout << "Testing product value validations..." << endl;
	Product checker("Watch", 129.99, 7, "2025-01-01");

	if (Validate::validatePrice(checker.getPrice()) &&
		Validate::validateStock(checker.getStock()) &&
		Validate::validateProductID(checker.getId()))
		cout << "All value validations passed!\n" << endl;
	else {
		cout << "Failure in one or more field validations: VALIDATION TEST FAILED" << endl;
		exit(-1);
	}

	cout << "Testing productIdExists in repo..." << endl;
	if (repo.productIdExists("P2"))
		cout << "productIdExists() works correctly!\n" << endl;
	else {
		cout << "productIdExists failed: PRODUCT ID EXISTS TEST FAILED" << endl;
		exit(-1);
	}

	cout << "Testing getProductById..." << endl;
	try {
		Product fetched = repo.getProductById("P1");
		if (fetched.getName() == "Tennis rackets" && fetched.getPrice() == 59.99)
			cout << "getProductById() works correctly!\n" << endl;
		else {
			cout << "getProductById returned wrong data\n";
			exit(-1);
		}
	}
	catch (exception& e) {
		cout << "getProductById failed: " << e.what() << endl;
		exit(-1);
	}

	cout << "Testing updateProduct..." << endl;
	Product updatedProd("Updated racket", 109.99, 2, "2026-01-01");
	if (repo.updateProduct("P1", updatedProd)) {
		Product updated = repo.getProductById("P1");
		if (updated.getName() == "Updated racket" && updated.getPrice() == 109.99)
			cout << "updateProduct() works correctly!\n" << endl;
		else {
			cout << "updateProduct failed: fields not updated correctly\n";
			exit(-1);
		}
	} else {
		cout << "updateProduct failed: ID not found\n";
		exit(-1);
	}

	cout << "Testing deleteProduct..." << endl;
	if (repo.deleteProduct("P2")) {
		if (!repo.productExists("P2") && repo.getAllProducts().size() == 1)
			cout << "deleteProduct() works correctly!\n" << endl;
		else {
			cout << "deleteProduct failed: product still exists\n";
			exit(-1);
		}
	} else {
		cout << "deleteProduct failed: ID not found\n";
		exit(-1);
	}

	cout << "PRODUCT AND REPO TESTS PASSED" << endl;
}
