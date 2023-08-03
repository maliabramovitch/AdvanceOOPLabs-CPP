cmake_minimum_required(VERSION 3.25)
project(lab10)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab10 factory_registry.cpp Circle.cpp Rectangle.cpp Shape.cpp Triangle.cpp)
