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

        Domain/Customer.cpp
        Repo/CustomerRepo.cpp
        Domain/Employee.cpp
        Repo/EmployeeRepo.cpp

        Domain/Product.cpp
        Repo/ProductRepo.cpp
        Services/Validator.cpp

        Domain/Order.cpp
        Repo/Order_repo.cpp

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

# Create an executable for running tests
add_executable(run_tests tests_main.cpp
        Tests/UserTests.cpp
        Tests/ProductTests.cpp
        Tests/ClientTests.cpp
        Tests/OrderTests.cpp
        Tests/EmployeeTests.cpp
)
# Link the tests executable with the app_lib library
target_link_libraries(run_tests app_lib)

