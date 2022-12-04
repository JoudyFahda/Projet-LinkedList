project(ProjetLinkedList)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(LinkedListProject main.cpp)
add_subdirectory(LinkedList)
target_include_directories(LinkedListProject PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/LinkedList")
target_link_libraries(LinkedListProject PUBLIC LinkedList)