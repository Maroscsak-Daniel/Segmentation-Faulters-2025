#include <cassert>
#include <iostream>
#include "../Domain/Customer.h"
#include "../Repo/CustomerRepo.h"
#include "../Domain/User.h"
#include "../Repo/UserRepo.h"
#include "../Services/UserServices.h"
#include "../Domain/Employee.h"
#include "../Repo/EmployeeRepo.h"
using namespace std;

void testCustomer(){
    Customer customer("Maria", "Popa", "maria.popa@gmail.com", "parola123", "+40740000000",
               "Str. Oltului 29", "client", false);
    //Getters tests
    assert(customer.getEmail() == "maria.popa@gmail.com");
    assert(customer.isGdprDeleted() == false);

    //Setters tests
    customer.setAddress("Oltului, 30");
    assert(customer.getAddress() == "Oltului, 30");
    customer.setPhone("0722333444");
    assert(customer.getPhone() == "0722333444");

    //Validation tests
    assert(customer.isValidEmail() == true);
    assert(customer.isValidPhone() == true);
    assert(customer.isValid() == true);

}


void testEmployee() {
    Employee employee("Andrei", "Popa", "andrei.popa@gmail.com", "parola456", "director", "22.01.2000", "456", 900, "excellent manager");

    //Getters tests
    assert(employee.getFirstName() == "Andrei");
    assert(employee.getEmail() == "andrei.popa@gmail.com"); // by default from User
    assert(employee.getShortCode() == "456");

    //Setters tests
    employee.setPosition("director");
    assert(employee.getPosition() == "director");
    employee.setFirstName("David");
    assert(employee.getFirstName() == "David");

    //Validation tests
    assert(employee.isValidSalary() == true);
    assert(employee.getAge() == 25);
    assert(employee.isValidAge() == true);

    //EmployeeRepo tests
    Employeerepo repo;

    Employee original("Marius", "Toma", "marius.toma@gmail.com", "parola789", "manager", "09.08.2000", "789", 500, "good manager");
    Employee updatedEmployee("Marius2", "Toma2", "marius.toma@gmail.com", "parola7892", "manager", "09.08.2002", "7892", 502, "bad manager");

    repo.addEmployee(original);
    assert(repo.emailExists("marius.toma@gmail.com") == true);
    repo.updateEmployee("marius.toma@gmail.com", updatedEmployee);
    Employee e = repo.findByShortCode("7892");
    assert(e.getFirstName() == "Marius2");

}



void testUser() {
    UserRepo repo;

    //Add tests
    repo.addUser(User("test@gmail.com", "parola123", "customer"));

    //Login tests
    AuthService authservice;
    assert(authservice.login(repo, "test@gmail.com", "parola123") == true);
    assert(authservice.login(repo, "alt@gmail.com", "parola123") == false);

    //User tests
    User user("john.doe@gmail.com", "password123", "employee");

    assert(user.getEmail() == "john.doe@gmail.com");
    assert(user.getRole() == "employee");
    assert(user.verifyPassword("password123") == true);

}


void UserTests() {
    testCustomer();
    testEmployee();
    testUser();
    cout<<"User tests: PASSED"<<endl;
}