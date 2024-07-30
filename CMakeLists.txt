cmake_minimum_required(VERSION 3.20)
project(third)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(bisection bisection.cpp)
add_executable(bisectionPlus bisectionPlus.cpp)
add_executable(secant secant.cpp)
add_executable(fx f.cpp)
add_executable(newtonRaphson newtonRaphson.cpp)
add_executable(newtonRaphsonPluss newtonRaphsonPluss.cpp)
add_executable(secantPlus secantPlus.cpp)
add_executable(gauss gauss.cpp)
add_executable(cholesky cholesky.cpp)
add_executable(gauss_seidel gauss_seidel.cpp)
add_executable(google googleArray.cpp)
add_executable(googlepluss googleArraypluss.cpp)