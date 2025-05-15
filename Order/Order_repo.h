#ifndef ORDER_REPO_H
#define ORDER_REPO_H

#include "../Order/Order.h"
#include <vector>
#include <string>
using namespace std;

class OrderRepo {
private:
    vector<Order> orders;

public:
    vector<Order> getAllOrders() const;
    void make_order(const Datum& datum,
                const vector<Product>& produkte,
                const string& kunde,
                const string& mitarbeiter,
                Status status);
    bool StatusConfirmed(const string& ID, const string& employee);
    bool StatusCompleted(const string& ID, const string& employee);
    bool change_products(const string& ID, const string& employee, const vector<Product>& neueProdukte);
    bool takeoverorder(const string& ID, const string& employee);
    const vector<Order>& getBestellungen() const;

    Order* findOrderById(const string& id);
    const Order* findOrderById(const string& id) const;
};

#endif // ORDER_REPO_H
