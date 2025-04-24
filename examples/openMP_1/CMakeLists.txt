# стандартный CMakeLists для проекта из одного файла -- main.cpp
cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_STANDARD 20)

# добавить ключ компилятору: -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

project(openmp)

add_executable(main ${CMAKE_SOURCE_DIR}/main.cpp)
