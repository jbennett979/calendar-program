cmake_minimum_required(VERSION 3.15)
project(M2OEP)

set(CMAKE_CXX_STANDARD 17)

add_executable(M2OEP main.cpp
        Calendar.cpp
        Month.cpp
        DayOfWeek.cpp
        Date.cpp
        Login.cpp)
add_executable(TESTING_SUITE testing.cpp
        Calendar.cpp
        Month.cpp
        DayOfWeek.cpp
        Date.cpp
        Login.cpp)
