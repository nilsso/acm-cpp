cmake_minimum_required(VERSION 3.2)

add_subdirectory(lib/googletest)

# ------------------------------------------------------------------------------
# ACM tests
# ------------------------------------------------------------------------------
project(acm_tests)

include_directories(${ACM_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/acm_tests.cpp)

add_executable(acm_tests ${SOURCE_FILES})
target_link_libraries(acm_tests acm gtest)
install(TARGETS acm_tests DESTINATION bin)

# ------------------------------------------------------------------------------
# Factor tests
# ------------------------------------------------------------------------------
project(factor_tests)

include_directories(${HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/factor_tests.cpp)

add_executable(factor_tests ${SOURCE_FILES})
target_link_libraries(factor_tests gtest)
install(TARGETS factor_tests DESTINATION bin)

# ------------------------------------------------------------------------------
# Divisor tests
# ------------------------------------------------------------------------------
project(divisor_tests)

include_directories(${HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/divisor_tests.cpp)

add_executable(divisor_tests ${SOURCE_FILES})
target_link_libraries(divisor_tests gtest)
install(TARGETS divisor_tests DESTINATION bin)
