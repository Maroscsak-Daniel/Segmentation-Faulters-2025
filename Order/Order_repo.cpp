#include "../Order/Order_repo.h"

vector<Order> OrderRepo::getAllOrders() const {
    return orders;
}

void OrderRepo::make_order(
    const Datum& datum,
    const vector<Product>& produkte,
    const string& kunde,
    const string& mitarbeiter,
    Status status
) {
    if (status != Status::Confirmed && status != Status::Reservation) return;
    Order o(datum, status, produkte, kunde, mitarbeiter, 0.0);
    orders.push_back(o);
}


Order* OrderRepo::findOrderById(const string& id) {
    for (auto& order : orders) {
        if (order.getId() == id) {
            return &order;
        }
    }
    return nullptr;
}

const Order* OrderRepo::findOrderById(const string& id) const {
    for (const auto& order : orders) {
        if (order.getId() == id) {
            return &order;
        }
    }
    return nullptr;
}

bool OrderRepo::StatusConfirmed(const string& ID, const string& employee) {
    Order* order = findOrderById(ID);
    if (!order) return false;
    if (order->getStatus() != Status::Reservation) return false;
    if (order->getemployee() != employee) return false;

    order->setStatus(Status::Confirmed);
    return true;
}

bool OrderRepo::StatusCompleted(const string& ID, const string& employee) {
    Order* order = findOrderById(ID);
    if (!order) return false;
    if (order->getStatus() != Status::Confirmed) return false;
    if (order->getemployee() != employee) return false;

    order->setStatus(Status::Completed);
    return true;
}

bool OrderRepo::change_products(const string& ID, const string& employee, const vector<Product>& neueProdukte) {
    Order* order = findOrderById(ID);
    if (!order) return false;
    if (order->getStatus() == Status::Completed) return false;
    if (order->getemployee() != employee) return false;

    order->setProducts(neueProdukte);
    return true;
}

bool OrderRepo::takeoverorder(const string& ID, const string& employee) {
    Order* order = findOrderById(ID);
    if (!order) return false;

    if (order->getemployee().empty()) {
        order->setemployee(employee);
        return true;
    }

    return false;
}


