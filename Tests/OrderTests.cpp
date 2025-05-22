#include <iostream>
#include "../Domain/Order.h"
#include "../Domain/Product.h"
#include "../Repo/Order_repo.h"

using namespace std;

void runOrderTests() {
    Date date{21, 5, 2025};
    Product p1("Milk", 5.0, 2, "2025-09-09");     // total = 10
    Product p2("Bread", 3.0, 3, "2024-08-08");    // total = 9

    vector<Product> products = {p1, p2};

    Order order(date, Status::Reservation, products, "client@test.com", "employee1");

    cout << "[TEST 1] Total calculated correctly: ";
    if (order.getTotalAmount() == 19.0)
        cout << "PASSED\n";
    else
        cout << "FAILED (" << order.getTotalAmount() << ")\n";

    cout << "[TEST 2] Initial status: ";
    if (order.getStatus() == Status::Reservation)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

    cout << "[TEST 3] ID generation check: ";
    if (!order.getId().empty() && order.getId().length() == 10)
        cout << "PASSED (" << order.getId() << ")\n";
    else
        cout << "FAILED\n";


    //Create Order with Repo
    OrderRepository repo;
    repo.createOrder(date, products, "client1@gmail.com", "", Status::Reservation);
    string id = repo.getOrders().at(0).getId();

    cout << "[TEST 4] Order created and stored: ";
    if (!id.empty() && repo.getOrders().size() == 1)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

    // Confirm the order
    bool confirmed = repo.confirmOrder(id, "emp1");
    cout << "[TEST 5] Confirm taken order: ";
    if (confirmed && repo.findOrderById(id)->getStatus() == Status::Confirmed)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

    // Complete the order
    bool completed = repo.completeOrder(id, "emp1");
    cout << "[TEST 6] Complete order: ";
    if (completed && repo.findOrderById(id)->getStatus() == Status::Completed)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

    // Try to update a completed order
    bool failedUpdate = repo.updateProducts(id, "emp1", products);
    cout << "[TEST 7] Update products on completed order (should fail): ";
    if (!failedUpdate)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

    cout << "[TEST 8] Find by customer (client1@mail.com): ";
    auto byCustomer = repo.findOrdersByCustomer("client1@mail.com");
    cout << (byCustomer.size() == 1 ? "PASSED\n" : "FAILED\n");


    cout << "[TEST 9] Find by customer (client1@mail.com): ";
    auto customer = repo.findOrdersByCustomer("client1@mail.com");
    cout << (customer.size() == 1 ? "PASSED\n" : "FAILED\n");

}

