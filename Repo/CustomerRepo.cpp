//
// Created by Cezara on 03.05.2025.
//
#include "../Repo/CustomerRepo.h"
#include "../Domain/Customer.h"
#include "../Domain/Order.h"
#include "Order_repo.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>

using namespace std;


vector<Customer> CustomerRepo::customers;


bool CustomerRepo::emailExists(const string& email) const {
    for (const auto& c : customers) {
        if (c.getEmail() == email)
            return true;
    }
    return false;
}


void CustomerRepo::anonymizeCustomer(const string& email, int id) {
    for (auto& c : customers) {
        if (c.getEmail() == email) {
            c.anonymize(id);
            return;
        }
    }
    throw runtime_error("Customer not found for anonymization.");
}


Customer CustomerRepo::findByEmail(const string& email) const {
    for (const auto& c : customers) {
        if (c.getEmail() == email)
            return c;
    }
    throw runtime_error("Customer not found by email.");
}


Customer CustomerRepo::findByPhone(const string& phone) const {
    for (const auto& c : customers) {
        if (c.getPhone() == phone)
            return c;
    }
    throw runtime_error("Customer not found by phone.");
}


vector<Customer> CustomerRepo::findByName(const string& lastName, const string& firstName) const {
    vector<Customer> result;
    for (const auto& c : customers) {
        if (c.getLastName() == lastName && c.getFirstName() == firstName)
            result.push_back(c);
    }
    return result;
}

struct Date {
    int day;
    int month;
    int year;
};

Date parseDate(const string& date_input) {
    return{
        stoi(date_input.substr(0,4)),
        stoi(date_input.substr(5,2)),
        stoi(date_input.substr(7,2))
    };
}

bool comparDates(const Date& d1, const Date& d2) {
    if (d1.year != d2.year) return d1.year > d2.year;
    if (d1.month!= d2.month) return d1.month > d2.month;
    return d1.day > d2.day;
}

struct CustomerOrderInfo {
    Customer customer;
    Date mostRecentOrder;
};

vector <Customer> CustomerRepo::findByProduct(const string& productName, const OrderRepository& orderRepo) const {

    vector <CustomerOrderInfo> result;
    for (const auto& customer  : customers) {
        Date lastDate{0,0,0};
        bool found = false;

        for (const auto& order : orderRepo.getAllOrders()) {
            if (order.getCustomer() != customer.getEmail())
                continue;

            for (const auto& product : order.getProducts()) {
                if (product.getName() == productName) {
                    Date orderDate = parseDate(order.getorderDate());
                    if (! found || comparDates(orderDate, lastDate)) {
                        lastDate = orderDate;
                        found = true;
                    }
                    break;
                }
            }
        }
        if (found == true) {
            result.push_back({customer, lastDate});
        }
    }

   sort(result.begin(), result.end(), [](const CustomerOrderInfo a, const CustomerOrderInfo b) {
       return comparDates(a.mostRecentOrder, b.mostRecentOrder);
   });

    vector<Customer> SortedCustomers;
    for (const auto& cust : result) {
        SortedCustomers.push_back(cust.customer);
    }
    return SortedCustomers;
}



vector<Customer> CustomerRepo::getAllSorted() const {
    vector<Customer> sorted = customers;
    sort(sorted.begin(), sorted.end(), [](const Customer& a, const Customer& b) {
        if (a.getLastName() == b.getLastName())
            return a.getFirstName() < b.getFirstName();
        return a.getLastName() < b.getLastName();
    });
    return sorted;
}



void CustomerRepo::addCustomer(const Customer& customer) {
    for (const auto& c: customers) {
        if (c.getEmail() == customer.getEmail()) {
            cout<<"Customer already exists.";
            return;
        }

    }
    customers.push_back(customer);


}
Customer CustomerRepo::findCustomer(const string& email) {
    for (const auto& c : customers) {
        if (c.getEmail() == email) {
            cout << "Customer was found." << endl;
            return c;
        }
    }
    throw runtime_error("Customer does not exist.");


}
void CustomerRepo::updateCustomer(const Customer& customer) {
    for (auto& c : customers) {
        if (c.getEmail() == customer.getEmail()) {
            c = customer;
            cout << "Customer updated." << endl;
            return;
        }
    }
    cout << "Customer not found for update." << endl;

}
void CustomerRepo::deleteCustomer(const Customer& customer) {
    auto it = remove_if(customers.begin(), customers.end(),
        [&](const Customer& c) {
            return c.getEmail() == customer.getEmail();
        });
    if (it != customers.end()) {
        customers.erase(it, customers.end());
        cout << "Customer deleted." << endl;
    } else {
        cout << "Customer not found for deletion." << endl;
    }
}
 const vector<Customer>& CustomerRepo::getAllCustomers(){
    return customers;
}


vector<Customer> CustomerRepo::show_all_customers() const {
    vector<Customer> customers = getAllCustomers();

    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b) {
        if (a.getLastName() == b.getLastName())
            return a.getFirstName() < b.getFirstName();
        return a.getLastName() < b.getLastName();
    });

    return customers;
}