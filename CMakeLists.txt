cmake_minimum_required(VERSION 3.30)
project(Segmentation_Faulters_2025)

set(CMAKE_CXX_STANDARD 14)
add_executable(Segmentation_Faulters_2025
        main.cpp
        Domain/User.cpp
        Domain/User.h
        Repo/UserRepo.cpp
        Repo/UserRepo.h
        Services/UserServices.cpp
        Services/UserServices.h
        Tests/UserTests.cpp

        Repo/Bestellung_repo.cpp
        Repo/Bestellung_repo.h

        Domain/Customer.cpp
        Repo/CustomerRepo.cpp
        Domain/Employee.cpp
        Repo/EmployeeRepo.cpp

        Domain/Product.cpp
        Repo/ProductRepo.cpp
        Services/Validator.cpp
        Services/Validator.cpp

        UI/LoginUI.cpp
        UI/LoginUI.h
        UI/CustomerMenu.cpp
        UI/CustomerMenu.h
        UI/EmployeeMenu.cpp
        UI/EmployeeMenu.h)

