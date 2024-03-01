cmake_minimum_required(VERSION 3.5)
project(CalculadoraComplexos)

# A biblioteca complexo
include(src/complexo/complexo.cmake)

set(SOURCE_FILES src/main.cpp src/menu.cpp)

add_executable(calculadora ${SOURCE_FILES})
target_include_directories(calculadora PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(calculadora PUBLIC cxx_std_11)
target_link_libraries(calculadora PUBLIC complexlib)