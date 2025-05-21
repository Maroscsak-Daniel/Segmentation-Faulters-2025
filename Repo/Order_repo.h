#ifndef ORDER_REPOSITORY_H
#define ORDER_REPOSITORY_H

#include "../Domain/Order.h"
#include <vector>
#include <string>

using namespace std;

class OrderRepository {
private:
    vector<Order> orders;

public:
    void createOrder(const Date& date,
                     const vector<Product>& products,
                     const string& customer,
                     const string& employee,
                     Status status);

    bool confirmOrder(const string& id, const string& employee);
    bool completeOrder(const string& id, const string& employee);
    bool updateProducts(const string& id, const string& employee, const vector<Product>& newProducts);
    bool takeOverOrder(const string& id, const string& employee);

    vector<Order> getAllOrders() const;
    const vector<Order>& getOrders() const;

    Order* findOrderById(const string& id);
    const Order* findOrderById(const string& id) const;
};

#endif // ORDER_REPOSITORY_H
