#include "Order.h"
#include <random>
#include <ctime>

Order::Order(const string &date, Status status, const vector<Product>& products,
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
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> dist(0, characters.size() - 1);

    string result;
    for (int i = 0; i < length; ++i) {
        result += characters[dist(generator)];
    }
    return result;
}

double Order::calculateTotalAmount(const vector<Product>& products) {
    double sum = 0.0;
    for (const auto& product : products) {
        sum += product.getPrice() * product.getStock();
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

string Order::getorderDate() const {
    return orderDate;
}


void Order::setorderdata(const string& ymd) {
    orderDate = ymd;
}

const vector<Product>& Order::getProducts() const {
    return products;
}

double Order::getTotalAmount() const {
    return totalAmount;
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

std::string statusToString(Status status) {
    if (status == Status::Reservation) {
        return "Reservation";
    }
    if (status == Status::Confirmed) {
        return "Confirmed";
    }
    if (status == Status::Completed) {
        return "Completed";
    }
    return "Unknown";
}

