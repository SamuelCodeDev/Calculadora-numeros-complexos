add_library(complexlib STATIC src/complexo/complexo.cpp)
target_include_directories(complexlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/complexo/include)