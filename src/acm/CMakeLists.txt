cmake_minimum_required(VERSION 3.2)
project(acm C CXX)

set(SOURCE_FILES
    acm.h
    acm.cpp
)

include_directories(${HEADERS_DIR})

add_library(acm SHARED STATIC ${SOURCE_FILES})

install(TARGETS acm DESTINATION ${ACM_MAIN_INSTALL_LIB_DIR})
install(FILES acm.h DESTINATION ${ACM_MAIN_INSTALL_INCLUDE_DIR})
