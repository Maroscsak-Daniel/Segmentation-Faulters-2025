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

        Order/Order.cpp
        Order/Order.h

        Customer/Customer.cpp
        Customer/CustomerRepo.cpp
        Employee/Employee.cpp
        Employee/EmployeeRepo.cpp

        Product/Product.cpp
        Product/ProductRepo.cpp
        Product/Validator.cpp
        UI_USER/LoginUI.cpp
        UI_USER/LoginUI.h
        UI_USER/CustomerMenu.cpp
        UI_USER/CustomerMenu.h
        UI_USER/EmployeeMenu.cpp
        UI_USER/EmployeeMenu.h
        Order/Order_repo.cpp
        Order/Order_repo.h)

