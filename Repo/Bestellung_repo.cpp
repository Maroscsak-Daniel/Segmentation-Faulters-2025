#include <iostream>
#include <cstdlib>
#include <string>
#include "Bestellung_repo.h"
using namespace std;


string generiereID(int laenge = 10) {
    const string zeichen = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string id;
    srand(time(0));
    for (int i = 0; i < laenge; ++i) {
        id += zeichen[rand() % zeichen.size()];
    }
    return id;
}