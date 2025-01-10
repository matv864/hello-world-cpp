cmake_minimum_required(VERSION 3.13)

project(hello-world-cpp-logger)


add_library(log_writer STATIC log_writer.cpp)
add_library(process_launcher STATIC process_launcher.cpp)
add_library(counter_manager STATIC counter_manager.cpp)

add_executable(main main.cpp)

target_link_libraries(main log_writer process_launcher counter_manager)