add_library(LinkedList LinkedList.cpp )
target_include_directories(LinkedList PUBLIC "${PROJECT_SOURCE_DIR}/LinkedList")
target_link_libraries(LinkedList)