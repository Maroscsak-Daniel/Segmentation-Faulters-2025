#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "../Domain/Product.h"

using namespace std;

enum class Status { Reservation, Confirmed, Completed };

struct OrderedProduct {
    Product product;
    int quantity;

    OrderedProduct(const Product& product, int quantity)
        : product(product), quantity(quantity) {}

    double totalPrice() const {
        return product.getPrice() * quantity;
    }
};

class Order {
private:
    string id;
    Status status;
    string orderDate;
    vector<Product> products;
    string customer;
    string employee;
    double totalAmount;

    string generateId(int length = 10);
    double calculateTotalAmount(const vector<Product>& products);

public:
    Order(const string &date, Status status, const vector<Product>& products,
          const string& customer, const string& employee);

    Status getStatus() const;
    string getEmployee() const;
    string getCustomer() const;
    string getId() const;
    string getorderDate() const;
    const vector<Product>& getProducts() const;
    double getTotalAmount() const;

    void setStatus(Status s);
    void setEmployee(const string& e);
    void setorderdata(const string& ymd);
    void setProducts(const vector<Product>& newProducts);
};

#endif // ORDER_H
