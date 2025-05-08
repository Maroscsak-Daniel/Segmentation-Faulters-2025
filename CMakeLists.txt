cmake_minimum_required(VERSION 3.31)
project(ProjectOOP2025)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectOOP2025
        main.cpp
        User/User.cpp
        User/User.h
        User/UserRepo.cpp
        User/UserRepo.h
        User/UserServices.cpp
        User/UserServices.h
        User/UserTests.cpp)
