cmake_minimum_required(VERSION 3.10)

project(freq)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-O3 -Wall -Wextra)

SET(FREQ_SOURCES "src/main.cpp"
                 "src/utils.cpp")
SET(FREQ_HEADERS "include")

add_executable(freq ${FREQ_SOURCES})

target_include_directories(freq PUBLIC ${FREQ_HEADERS})