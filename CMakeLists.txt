project(Checkout)
cmake_minimum_required(VERSION 3.14.7) # Second most recent Cmake version for compatibility

include_directories(../include ../src)
add_executable (Checkout
                src/main.cpp
                src/Calculator.cpp
                include/Calculator.h
                src/Checkout.cpp
                include/Checkout.h
                src/Ruleset.cpp
                include/Ruleset.h) 

