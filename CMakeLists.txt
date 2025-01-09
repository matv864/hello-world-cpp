cmake_minimum_required(VERSION 3.13)  # Проверка версии CMake.
									  # Если версия установленной программы
									  # старее указаной, произойдёт аварийный выход.

project(hello-world-cpp)              # Название проекта


add_library(process_launcher STATIC process_launcher.cpp)	# Создание статической библиотеки с именем process_launcher

add_executable(main test.cpp)	  # Создает исполняемый файл с именем main

target_link_libraries(main process_launcher)  # Линковка программы с библиотекой