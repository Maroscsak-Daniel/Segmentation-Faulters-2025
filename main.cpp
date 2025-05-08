//
// Created by Maroscsak Daniel on 5/8/2025.
//
#include <iostream>
#include "Product/Product.h"
#include "Product/ProductRepo.h"
#include "Product/Validator.h"
using namespace std;

int main() {
	// cout << "End my suffering" << endl;
 //    return 0;


	ProductRepo repo; //															|
	//																				|
	string id = "A123"; //															|
	string name = "Apfel"; //														|
	double price = 1.5; //															| P1, P2, P3, P4 is done.
	int stock = 10; //																| Product Class done.
	//																				| Product Repo Class done.
	if (Validator::validateId(id) && Validator::validateName(name) //				| Created a Validator class for P4.
		&& Validator::validatePrice(price) && Validator::validateStock(stock)) { //	| You can now add Products to Repo.
		Product p(id, name, price, stock); //									|
		if (repo.addProduct(p)) { //												| Feel free to delete or comment
			cout << "Produkt hinzugefugt.\n"; //									| this part of the code, it's here
		} else { //																	| just or debugging purposes to
			cout << "Produkt-ID bereits vorhanden.\n"; //							| check if everything works as
		} //																		| it should.
		} //																			|
	else { //																		|
		cout << "Ungultige Produktdaten.\n"; //										|
	} //																			|
	vector<Product> allProducts = repo.getAvailableProductsSortedByPrice(); //		| P3, no print function yet tho.
	return 0;
}