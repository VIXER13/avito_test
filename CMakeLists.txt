cmake_minimum_required(VERSION 3.10)

project(freq)

SET(FREQ_SOURCES "src/main.cpp"
                 "src/utils.cpp")
SET(FREQ_HEADERS "include")

add_executable(freq ${FREQ_SOURCES})

target_include_directories(freq PUBLIC ${FREQ_HEADERS})