// Created by Ingrid on 16.05.2025.

#include <iostream>
#include "../Domain/Employee.h"
#include "../Repo/EmployeeRepo.h"

void runEmployeeTests() {
    EmployeeRepo repo;

    Employee valid("Maria", "Popescu", "maria@email.com", "Parola123", "Manager", "01.01.1990", "EMP001", 1500, "Angajat model");

    std::cout << "[TEST 1] Adaugare angajat valid: ";
    repo.addEmployee(valid);
    try {
        Employee found = repo.findByEmail("maria@email.com");
        std::cout << "PASSED\n";
    } catch (...) {
        std::cout << "FAILED\n";
    }

    std::cout << "[TEST 2] Adaugare duplicat dupa email: ";
    try {
        repo.addEmployee(valid);
        std::cout << "FAILED\n";
    } catch (...) {
        std::cout << "PASSED\n";
    }

    std::cout << "[TEST 3] Cautare dupa cod scurt: ";
    try {
        Employee found = repo.findByShortCode("EMP001");
        std::cout << "PASSED\n";
    } catch (...) {
        std::cout << "FAILED\n";
    }

    std::cout << "[TEST 4] Filtrare dupa nume complet: ";
    auto results = repo.findByName("Popescu", "Maria");
    if (!results.empty())
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 5] Filtrare dupa data nastere: ";
    auto bd = repo.findByBirthdateRange("01.01.1980", "01.01.2000");
    if (!bd.empty())
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 6] Sortare dupa nume: ";
    auto sorted = repo.getAllSorted();
    if (!sorted.empty() && sorted[0].getLastName() == "Popescu")
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";
}
