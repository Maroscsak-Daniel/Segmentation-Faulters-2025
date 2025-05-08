cmake_minimum_required(VERSION 3.30)
project(Segmentation_Faulters_2025)

set(CMAKE_CXX_STANDARD 14)

add_executable(Segmentation_Faulters_2025
    main.cpp
        Product/Product.cpp
        Product/ProductRepo.cpp
        Product/Validator.cpp)
