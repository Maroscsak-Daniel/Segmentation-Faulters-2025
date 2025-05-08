cmake_minimum_required(VERSION 3.30)
project(Segmentation_Faulters_2025)

set(CMAKE_CXX_STANDARD 14)
add_executable(Segmentation_Faulters_2025
        main.cpp
        User/User.cpp
        User/User.h
        User/UserRepo.cpp
        User/UserRepo.h
        User/UserServices.cpp
        User/UserServices.h
        User/UserTests.cpp

        Order/Bestellung_repo.cpp
        Order/Bestellung_repo.h

        Customer/Customer.cpp
        Customer/CustomerRepo.cpp
        Employee/Employee.cpp
        Employee/EmployeeRepo.cpp

        Product/Product.cpp
        Product/ProductRepo.cpp
        Product/Validator.cpp)
