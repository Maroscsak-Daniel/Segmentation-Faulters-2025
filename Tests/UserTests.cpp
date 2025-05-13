#include <cassert>
#include <iostream>
#include "../Customer/Customer.h"
#include "../Customer/CustomerRepo.h"
#include "../User/User.h"
#include "../User/UserRepo.h"
#include "../User/UserServices.h"
#include "../Employee/Employee.h"
#include "../Employee/EmployeeRepo.h"


void testCustomer(){
    Customer customer("Maria", "Popa", "maria.popa@gmail.com", "0711222333", "Muresului, 23", "remarksMaria", true );

    //Getters tests
    assert(customer.getEmail() == "maria.popa@gmail.com");
    assert(customer.isGdprDeleted() == true);

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
    Employee employee("Andrei", "Popa", "andrei.popa@gmail.com", "manager", "14.06.2000", "1234", 900, "remarksAndrei");

    //Getters tests
    assert(employee.getEmail() == "andrei.popa@gmail.com");
    assert(employee.getShortCode() == "1234");

    //Setters tests
    employee.setPosition("director");
    assert(employee.getPosition() == "director");
    employee.setFirstName("David");
    assert(employee.getFirstName() == "David");

    //Validation tests
    assert(employee.isValidSalary() == true);
    assert(employee.getAge() == 24);
    assert(employee.isValidAge() == true);

    //EmployeeRepo tests
    Employeerepo repo;
    repo.addEmployee({"Marius", "Toma", "marius.toma@gmail.com", "manager", "01.01.2001", "0001", 800, "remarksMarius"});
    repo.updateEmployee("marius.toma@gmail.com", {"Ana", "Serea", "ana.serea@gmail.com", "assistant","02.02.2002", "0002", 700, "remarksAna"});
    Employee e = repo.findByShortCode("0002");
    assert(e.getFirstName() == "Ana");

}



void testUser() {
    UserRepo repo;

    //Add tests
    repo.addUser(User("test@gmail.com", "parola123", "customer"));

    //Login tests
    AuthService authservice;
    assert(authservice.login(repo, "test@gmail.com", "parola123") == true);
    assert(authservice.login(repo, "alt@gmail.com", "parola123") == false);

}


void testsUser() {
    testCustomer();
    testEmployee();
    testUser();
    cout<<"User tests: PASSED"<<endl;
}