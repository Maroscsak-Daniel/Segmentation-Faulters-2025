#include <iostream>
#include "../Domain/User.h"
#include "../Repo/UserRepo.h"
#include "../Services/UserServices.h"

void runUserTests() {
    UserRepo repo;
    repo.addUser(User("test@email.com", "Parola1", "customer"));

    std::cout << "[TEST 1] Login corect: ";
    if (AuthService::login(repo, "test@email.com", "Parola1"))
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 2] Login greșit (email incorect): ";
    if (!AuthService::login(repo, "alt@email.com", "Parola1"))
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 3] Login greșit (parolă incorectă): ";
    if (!AuthService::login(repo, "test@email.com", "parola123"))
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    AuthService authService;  // instanță pentru metode non-statice-am avut problema ca nu le-am declarat toate static initial

    std::cout << "[TEST 4] Înregistrare utilizator valid: ";
    bool regResult = authService.registerUser(repo, "newuser@email.com", "Pass2", "employee");
    if (regResult)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED (" << authService.getLastError() << ")\n";

    std::cout << "[TEST 5] Înregistrare cu email deja folosit: ";
    regResult = authService.registerUser(repo, "test@email.com", "Pass2", "customer");
    if (!regResult)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 6] Înregistrare cu parolă invalidă: ";
    regResult = authService.registerUser(repo, "another@email.com", "pass", "customer");
    if (!regResult)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 7] Înregistrare cu email invalid: ";
    regResult = authService.registerUser(repo, "invalidemail", "Pass1", "customer");
    if (!regResult)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 8] Înregistrare cu rol invalid: ";
    regResult = authService.registerUser(repo, "valid@email.com", "Pass1", "manager");
    if (!regResult)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";
    std::cout << "[TEST 9] Email cu '@' la început: ";
    bool result = authService.registerUser(repo, "@invalid.com", "Pass1", "customer");
    if (!result)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 10] Email cu mai multe '@': ";
    result = authService.registerUser(repo, "a@@b.com", "Pass1", "customer");
    if (!result)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST Edge 11] Email fără '.' după '@': ";
    result = authService.registerUser(repo, "a@bcom", "Pass1", "customer");
    if (!result)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 12] Parolă minimă validă (4 caractere): ";
    result = authService.registerUser(repo, "minpass@email.com", "A1bc", "customer");
    if (result)
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED (" << authService.getLastError() << ")\n";

    std::cout << "[TEST Edge 13] Parolă 4 caractere fără cifră: ";
    result = authService.registerUser(repo, "nopassdigit@email.com", "Abcd", "customer");
    if (!result)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 14] Parolă 4 caractere fără majusculă: ";
    result = authService.registerUser(repo, "nopassupper@email.com", "a1bc", "customer");
    if (!result)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST Edge 15] Rol gol: ";
    result = authService.registerUser(repo, "rolgol@email.com", "Pass1", "");
    if (!result)
        std::cout << "PASSED (" << authService.getLastError() << ")\n";
    else
        std::cout << "FAILED\n";

    std::cout << "[TEST 16] Login pe repo gol: ";
    UserRepo emptyRepo;
    if (!AuthService::login(emptyRepo, "nou@email.com", "Pass1"))
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";

    repo.addUser(User("case@test.com", "Pass1", "customer"));
    std::cout << "[TEST 17] Login cu parolă case-sensitive (majuscule diferite): ";
    if (!AuthService::login(repo, "case@test.com", "pass1")) // parola corecta e Pass1, dar încercam pass1
        std::cout << "PASSED\n";
    else
        std::cout << "FAILED\n";
}
