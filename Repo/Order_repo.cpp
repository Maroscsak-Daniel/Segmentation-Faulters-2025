#include "Order_repo.h"

void OrderRepository::createOrder(
    const string& date,
    const vector<Product>& products,
    const string& customer,
    const string& employee,
    Status status
) {
    if (status != Status::Confirmed && status != Status::Reservation) return;
    Order o(date, status, products, customer, employee);
    orders.push_back(o);
}

Order* OrderRepository::findOrderById(const string& id) {
    for (auto& order : orders) {
        if (order.getId() == id) {
            return &order;
        }
    }
    return nullptr;
}


bool OrderRepository::confirmOrder(const string& id, const string& employee) {
    Order* order = findOrderById(id);
    if (!order || order->getStatus() != Status::Reservation || order->getEmployee() != employee)
        return false;

    order->setStatus(Status::Confirmed);
    return true;
}

bool OrderRepository::completeOrder(const string& id, const string& employee) {
    Order* order = findOrderById(id);
    if (!order || order->getStatus() != Status::Confirmed || order->getEmployee() != employee)
        return false;

    order->setStatus(Status::Completed);
    return true;
}

bool OrderRepository::updateProducts(const string& id, const string& employee, const vector<Product>& newProducts) {
    Order* order = findOrderById(id);
    if (!order || order->getStatus() == Status::Completed || order->getEmployee() != employee)
        return false;

    order->setProducts(newProducts);
    return true;
}

bool OrderRepository::takeOverOrder(const string& id, const string& employee) {
    Order* order = findOrderById(id);
    if (!order) return false;

    if (order->getEmployee().empty()) {
        order->setEmployee(employee);
        return true;
    }

    return false;
}

vector<Order> OrderRepository::getAllOrders() const {
    return orders;
}


vector<Order> OrderRepository::findOrdersByCustomer(const string& customer) const {
    vector<Order> result;
    for (const auto& order : orders) {
        if (order.getCustomer() == customer)
            result.push_back(order);
    }
    return result;
}

vector<Order> OrderRepository::findOrdersByEmployee(const string& employee) const {
    vector<Order> result;
    for (const auto& order : orders) {
        if (order.getEmployee() == employee)
            result.push_back(order);
    }
    return result;
}

vector<Order> OrderRepository::findOrdersByStatus(Status status) const {
    vector<Order> result;
    for (const auto& order : orders) {
        if (order.getStatus() == status)
            result.push_back(order);
    }
    return result;
}



