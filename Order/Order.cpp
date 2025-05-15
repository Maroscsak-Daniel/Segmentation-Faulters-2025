#include <cstdlib>
#include <ctime>
#include "Order.h"

string Order::generiereID(int laenge) {
    const string zeichen = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string id;
    srand(time(0));
    for (int i = 0; i < laenge; ++i) {
        id += zeichen[rand() % zeichen.size()];
    }
    return id;
}
