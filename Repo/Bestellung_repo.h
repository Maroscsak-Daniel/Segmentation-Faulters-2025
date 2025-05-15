//
// Created by Laura Muresan on 08.05.2025.
//

#ifndef BESTELLUNG_REPO_H
#define BESTELLUNG_REPO_H
//
// Created by Laura Muresan on 08.05.2025.

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Datum {
    int tag;
    int monat;
    int jahr;
};

struct Produkt {
    string name;
    int menge;
};
enum class Status { Reservation,
    Confirmed,
    Completed };

class Bestellung {
private:
    string bestellnummer;
    Status status;
    Datum bestelldatum;
    vector<Produkt> produkte;
    string kunde;
    string mitarbeiter;
    double gesamtsumme;

    string generiereID(int laenge = 10);

public:
    Bestellung(Datum datum, Status status, const vector<Produkt>& produkte,
               const string& kunde, const string& mitarbeiter, double gesamtsumme)
        : bestelldatum(datum),
    status(status),
    produkte(produkte),
    kunde(kunde),
    mitarbeiter(mitarbeiter),
    gesamtsumme(gesamtsumme)
    {
        bestellnummer = generiereID();
    }

};

#endif //BESTELLUNG_REPO_H

