#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "../Product/Product.h"

using namespace std;

struct Datum {
    int tag;
    int monat;
    int jahr;
};

enum class Status { Reservation, Confirmed, Completed };

class Order {
private:
    string ID;
    Status status;
    Datum bestelldatum;
    vector<Product> produkte;
    string kunde;
    string mitarbeiter;
    double gesamtsumme;

    string generiereID(int laenge = 10); // Private helper

public:
    Order(Datum datum, Status status, const vector<Product>& produkte,
          const string& kunde, const string& mitarbeiter, double gesamtsumme)
        : bestelldatum(datum),
          status(status),
          produkte(produkte),
          kunde(kunde),
          mitarbeiter(mitarbeiter),
          gesamtsumme(gesamtsumme)
    {
        ID = generiereID();
    }

    Status getStatus() const { return status; }
    string getemployee() const { return mitarbeiter; }
    void setStatus(Status s) { status = s; }
    void setemployee(const string& m) { mitarbeiter = m; }
    void setProducts(const vector<Product>& neueProdukte) { produkte = neueProdukte; }
    const vector<Product>& getProducts() const { return produkte; }
    string getId() const { return ID; }
    string getCustomer() const { return kunde; }

};

#endif // ORDER_H
