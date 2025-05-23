#include "CustomerMenu.h"
#include "../Domain/Order.h"
#include <iostream>
#include <limits>

using namespace std;

CustomerMenu::CustomerMenu(CustomerRepo customer_repo, ProductRepo& product_repo, OrderRepository& order_repo)
    : customer_repo(customer_repo), product_repo(product_repo), order_repo(order_repo) {}

void CustomerMenu::show() {
    string customerName;
    cout << "Enter your customer name: ";
    getline(cin, customerName);

    int option;
    do {
        cout << "\nCustomer Menu:\n";
        cout << "1. View all products\n";
        cout << "2. View available products\n";
        cout << "3. View products sorted by price\n";
        cout << "4. Create a new order\n";
        cout << "5. View your orders\n";
        cout << "6. Track an order by ID\n";
        cout << "7. Show order status.\n";
        cout << "0. Logout\n";
        cout << "Choose option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (option == 1) {
            for (const auto& p : product_repo.getAllProducts()) {
                cout << p.toString() << "\n";
            }
        }
        else if (option == 2) {
            for (const auto& p : product_repo.getAllProducts()) {
                if (p.getStock() > 0) {
                    cout << p.toString() << "\n";
                }
            }
        }
        else if (option == 3) {
            for (const auto& p : product_repo.getAvailableProductsSortedByPrice()) {
                cout << p.toString() << "\n";
            }
        }
        else if (option == 4) {
            vector<Product> cart;
            string productId;
            while (true) {
                cout << "Enter product ID to add (or 'done' to finish): ";
                getline(cin, productId);
                if (productId == "done") break;

                try {
                    Product product = product_repo.getProductById(productId);
                    if (product.getStock() == 0) {
                        cout << "Product out of stock.\n";
                    } else {
                        cart.push_back(product);
                        cout << "Product added to cart.\n";
                    }
                } catch (const exception& e) {
                    cout << "Error: " << e.what() << "\n";
                }
            }

            if (!cart.empty()) {
                Date date;
                Status status = Status::Confirmed;
                string employee;

                order_repo.createOrder(date, cart, customerName, employee, status);
                cout << "Order created successfully!\n";
            } else {
                cout << "No products selected.\n";
            }
        }
        else if (option == 5) {
            vector<Order> orders = order_repo.findOrdersByCustomer(customerName);
            for (const auto& order : orders) {
                cout << "Order ID: " << order.getId() << ", Status: " << (int)order.getStatus()
                     << ", Total: " << order.getTotalAmount() << "\n";
            }
        }
        else if (option == 6) {
            string orderId;
            cout << "Enter order ID to track: ";
            getline(cin, orderId);
            const Order* order = order_repo.findOrderById(orderId);
            if (order && order->getCustomer() == customerName) {
                cout << "Status of order " << orderId << ": " << (int)order->getStatus() << "\n";
            } else {
                cout << "Order not found.\n";
            }
        }
        else if (option == 7) {
            string customer;
            cout << "Enter your name: ";
            getline(cin, customerName);

            auto orders = order_repo.findOrdersByCustomer(customer);
            if (orders.empty()) {
                cout << "No orders found.\n";
            } else {
                for (const auto& order : orders) {
                    cout << "Order ID: " << order.getId() << "\n";
                    cout << "Status: ";
                    switch (order.getStatus()) {
                        case Status::Confirmed: cout << "Confirmed."; break;
                        case Status::Reservation: cout << "Order reserved."; break;
                        case Status::Completed: cout << "Completed."; break;
                    }
                    cout << "\nTotal: " << order.getTotalAmount() << "\n\n";
                }
            }
        }

        else if (option != 0) {
            cout << "Invalid option. Try again.\n";
        }

    } while (option != 0);
}
