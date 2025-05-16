cmake_minimum_required(VERSION 3.30)
project(Segmentation_Faulters_2025)

set(CMAKE_CXX_STANDARD 14)

# create a library with the code required by the app, except for main.cpp
add_library(app_lib
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

# Specify the main app executable, built from the main.cpp file
add_executable(Segmentation_Faulters_2025 main.cpp)

# The main app executable is to be linked with the app_lib library
target_link_libraries(Segmentation_Faulters_2025 app_lib)

