
#include "EmployeeMenu.h"
#include <iostream>

using namespace std;

EmployeeMenu::EmployeeMenu(CustomerRepo& customer_repo, ProductRepo& product_repo, EmployeeRepo& employeeRepo, OrderRepository& order_repo)
    : customer_repo(customer_repo), product_repo(product_repo), employeeRepo(employeeRepo), order_repo(order_repo) {}


void EmployeeMenu::show() const {
    int option;
    do {
        cout << "\nEmployee Menu:\n";
        cout << "\nOptions regarding products.\n";

        cout << "1. Add product.\n";
        cout << "2. Get all products.\n";
        cout << "3. Get available products (sorted by price).\n";
        cout << "4. Get product by ID.\n";
        cout << "5. Update Product.\n";
        cout << "6. Delete Product.\n";
        cout << "7. Verify that the ID exists.\n";

        cout<<"\nOptions regarding orders.\n";

        cout << "9. Confirm order.\n";
        cout << "10.Complete order.\n";
        cout << "11.Get all orders.\n";
        cout << "12.Update order.\n";
        cout << "13.Find order by customer.\n";
        cout << "14.Find order by ID.\n";
        cout << "15.Take over order.\n";
        cout << "16.Find order by status\n";
        cout << "17.Find order by employee.\n";
        cout << "0. Logout\n";
        cout << "Choose option: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            string name, date;
            double price;
            int stock;

            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter stock quantity: ";
            cin >> stock;
            cin.ignore();
            cout << "Enter date (YYYY-MM-DD): ";
            getline(cin, date);

            Product product(name, price, stock, date);
            if (product_repo.addProduct(product)) {
                cout << "Product added successfully.\n";
            } else {
                cout << "Product with this ID already exists.\n";
            }
        }
        else if (option == 2) {
            const auto& all = product_repo.getAllProducts();
            for (const auto& product : all) {
                cout << product.toString() << "\n";
            }
        }
        else if (option == 3) {
            auto sorted = product_repo.getAvailableProductsSortedByPrice();
            for (const auto& product : sorted) {
                cout << product.toString() << "\n";
            }
        }
        else if (option == 4) {
            string id;
            cout << "Enter product ID: ";
            getline(cin, id);
            try {
                Product p = product_repo.getProductById(id);
                cout << p.toString() << "\n";
            } catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }
        }
        else if (option == 5) {
            string id, name, date;
            double price;
            int stock;

            cout << "Enter product ID to update: ";
            getline(cin, id);
            cout << "Enter new name: ";
            getline(cin, name);
            cout << "Enter new price: ";
            cin >> price;
            cout << "Enter new stock quantity: ";
            cin >> stock;
            cin.ignore();
            cout << "Enter new date: ";
            getline(cin, date);

            Product updated(name, price, stock, date);
            if (product_repo.updateProduct(id, updated)) {
                cout << "Product updated successfully.\n";
            } else {
                cout << "Product ID not found.\n";
            }
        }
        else if (option == 6) {
            string id;
            cout << "Enter product ID to delete: ";
            getline(cin, id);
            if (product_repo.deleteProduct(id)) {
                cout << "Product deleted.\n";
            } else {
                cout << "Product ID not found.\n";
            }
        }
        else if (option == 7) {
            string id;
            cout << "Enter product ID to verify: ";
            getline(cin, id);
            if (product_repo.productExists(id)) {
                cout << "Product exists.\n";
            } else {
                cout << "Product does not exist.\n";
            }
        }
        else if (option == 9) {
            string id, employee;
            cout << "Enter order ID to confirm: ";
            getline(cin, id);
            cout << "Enter your employee name: ";
            getline(cin, employee);
            if (order_repo.confirmOrder(id, employee)) {
                cout << "Order confirmed.\n";
            } else {
                cout << "Order not found or already confirmed.\n";
            }
        }
        else if (option == 10) {
            string id, employee;
            cout << "Enter order ID to complete: ";
            getline(cin, id);
            cout << "Enter your employee name: ";
            getline(cin, employee);
            if (order_repo.completeOrder(id, employee)) {
                cout << "Order completed.\n";
            } else {
                cout << "Order not found or cannot be completed.\n";
            }
        }
        else if (option == 11) {
            auto orders = order_repo.getAllOrders();
            for (const auto& o : orders) {
                cout << "Order ID: " << o.getId() << " | Customer: " << o.getCustomer()
                     << " | Status: " << static_cast<int>(o.getStatus())
                     << " | Total: " << o.getTotalAmount() << "\n";
            }
        }
        else if (option == 12) {
            string id, employee;
            cout << "Enter order ID to update: ";
            getline(cin, id);
            cout << "Enter your employee name: ";
            getline(cin, employee);
            vector<Product> updatedProducts;
            int count;
            cout << "Enter number of new products: ";
            cin >> count;
            cin.ignore();
            for (int i = 0; i < count; ++i) {
                string name, date;
                double price;
                int stock;
                cout << "Product " << i + 1 << " name: ";
                getline(cin, name);
                cout << "Price: ";
                cin >> price;
                cout << "Stock: ";
                cin >> stock;
                cin.ignore();
                cout << "Date: ";
                getline(cin, date);
                updatedProducts.emplace_back(name, price, stock, date);
            }
            if (order_repo.updateProducts(id, employee, updatedProducts)) {
                cout << "Products updated.\n";
            } else {
                cout << "Update failed. Check order ID or employee name.\n";
            }
        }
        else if (option == 13) {
            string customer;
            cout << "Enter customer name: ";
            getline(cin, customer);
            auto orders = order_repo.findOrdersByCustomer(customer);
            for (const auto& o : orders) {
                cout << "Order ID: " << o.getId() << " | Total: " << o.getTotalAmount() << "\n";
            }
        }
        else if (option == 14) {
            string id;
            cout << "Enter order ID: ";
            getline(cin, id);
            const auto* order = order_repo.findOrderById(id);
            if (order) {
                cout << "Order found. Total: " << order->getTotalAmount() << "\n";
            } else {
                cout << "Order not found.\n";
            }
        }
        else if (option == 15) {
            string id, employee;
            cout << "Enter order ID: ";
            getline(cin, id);
            cout << "Enter your employee name: ";
            getline(cin, employee);
            if (order_repo.takeOverOrder(id, employee)) {
                cout << "Order taken over successfully.\n";
            } else {
                cout << "Could not take over order.\n";
            }
        }
        else if (option == 16) {
            int statusInt;
            cout << "Enter status (0: Placed, 1: Confirmed, 2: Completed): ";
            cin >> statusInt;
            cin.ignore();
            auto orders = order_repo.findOrdersByStatus(static_cast<Status>(statusInt));
            for (const auto& o : orders) {
                cout << "Order ID: " << o.getId() << " | Status: " << statusInt
                     << " | Total: " << o.getTotalAmount() << "\n";
            }
        }
        else if (option == 17) {
            string employee;
            cout << "Enter employee name: ";
            getline(cin, employee);
            auto orders = order_repo.findOrdersByEmployee(employee);
            for (const auto& o : orders) {
                cout << "Order ID: " << o.getId() << " | Customer: " << o.getCustomer()
                     << " | Total: " << o.getTotalAmount() << "\n";
            }
        }
        else if (option != 0) {
            cout << "Invalid option. Try again.\n";
        }

    } while (option != 0);
}


