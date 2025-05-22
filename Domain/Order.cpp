#include "Order.h"
#include <cstdlib>

Order::Order(Date date, Status status, const vector<Product>& products,
             const string& customer, const string& employee)
    : orderDate(date),
      status(status),
      products(products),
      customer(customer),
      employee(employee)
{
    id = generateId();
    totalAmount = calculateTotalAmount(products);
}

string Order::generateId(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;
    for( int i = 0; i < length; i++){
      int index = rand() % characters.size();
      result += characters[index];
      }
      return result;
}

double Order::calculateTotalAmount(const vector<Product>& products) {
    double sum = 0.0;
    for (const auto& product : products) {
        sum += product.getPrice() * product.getQuantity();
    }
    return sum;
}

Status Order::getStatus() const {
    return status;
}

string Order::getEmployee() const {
    return employee;
}

string Order::getCustomer() const {
    return customer;
}

string Order::getId() const {
    return id;
}

const vector<Product>& Order::getProducts() const {
    return products;
}

double Order::getTotalAmount() const {
    return totalAmount;
}

Date Order::getDate() const {
    return orderDate;
}

void Order::setStatus(Status s) {
    status = s;
}

void Order::setEmployee(const string& e) {
    employee = e;
}

void Order::setProducts(const vector<Product>& newProducts) {
    products = newProducts;
    totalAmount = calculateTotalAmount(newProducts);
}
