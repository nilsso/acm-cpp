cmake_minimum_required(VERSION 3.2)
project(acm-main)

add_subdirectory(acm)
set(SOURCE_FILES main.cpp)

add_executable(acm-main ${SOURCE_FILES})
target_link_libraries(acm-main acm)
install(TARGETS acm-main DESTINATION ${ACM_MAIN_INSTALL_BIN_DIR})
