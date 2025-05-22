//
// Created by user on 20.05.2025.
//
//
// Created by user on 20.05.2025.
//

#include <iostream>
#include "../Domain/Customer.h"
#include "../Repo/CustomerRepo.h"

void runCustomerTests() {
    CustomerRepo repo;

    Customer validCustomer("Ion", "Popescu", "ion@email.com", "Parola1", "+40712345678", "Str. Lalelelor", "client fidel", false);

    std::cout << "[TEST 1] Adăugare client valid: ";
    repo.addCustomer(validCustomer);
    try {
        Customer found = repo.findCustomer("ion@email.com");
        std::cout << "PASSED\n";
    } catch (...) {
        std::cout << "FAILED\n";
    }

    std::cout << "[TEST 2] Adăugare client duplicat (email deja folosit): ";
    repo.addCustomer(validCustomer); // nu ar trebui să adauge din nou
    int count = repo.getAllSorted().size();
    if (count == 1)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 3] Validare email incorect: ";
    Customer invalidEmail("Ana", "Ionescu", "emailInvalid", "Parola1", "+40712345678", "Str. Rozelor", "", false);
    if (!invalidEmail.isValid())
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 4] Validare telefon incorect: ";
    Customer invalidPhone("Ana", "Ionescu", "ana@email.com", "Parola1", "abc123", "Str. Rozelor", "", false);
    if (!invalidPhone.isValid())
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 5] Căutare client după telefon: ";
    try {
        Customer byPhone = repo.findByPhone("+40712345678");
        std::cout << "PASSED\n";
    } catch (...) {
        std::cout << "FAILED\n";
    }

    std::cout << "[TEST 6] Căutare client inexistent: ";
    try {
        repo.findCustomer("alt@email.com");
        std::cout << "FAILED\n";
    } catch (...) {
        std::cout << "PASSED\n";
    }

    std::cout << "[TEST 7] Anonimizare client: ";
    repo.anonymizeCustomer("ion@email.com", 101);
    try {
        Customer anon = repo.findCustomer("ion@email.com");
        std::cout << "FAILED\n";
    } catch (...) {
        std::cout << "PASSED\n";
    }

    std::cout << "[TEST 8] Validare generală client anonim: ";
    if (repo.getAllSorted()[0].isValid())
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";
}
