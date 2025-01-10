cmake_minimum_required(VERSION 3.13)  # Проверка версии CMake.
									  # Если версия установленной программы
									  # старее указаной, произойдёт аварийный выход.

project(hello-world-cpp-logger)              # Название проекта


add_library(log_writer STATIC log_writer.cpp)	# Создание статической библиотеки с именем process_launcher

add_executable(main main.cpp)	  # Создает исполняемый файл с именем main

target_link_libraries(main log_writer)  # Линковка программы с библиотекой