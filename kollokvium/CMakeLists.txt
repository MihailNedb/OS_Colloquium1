cmake_minimum_required(VERSION 3.15)
project(FactorialAndList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    Array_func/array_func.cpp
    LinkedList/LinkedList.cpp
    Math_func/Math_func.cpp
)

set(HEADERS
    Array_func/array_func.h
    LinkedList/LinkedList.h
    Math_func/Math_func.h
    common/Node.h
)

add_executable(main ${SOURCES} ${HEADERS})


target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Array_func
    ${CMAKE_CURRENT_SOURCE_DIR}/LinkedList
    ${CMAKE_CURRENT_SOURCE_DIR}/Math_func
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()


add_executable(tests 
    tests.cpp
    Array_func/array_func.cpp
    LinkedList/LinkedList.cpp
    Math_func/Math_func.cpp
)


target_include_directories(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Array_func
    ${CMAKE_CURRENT_SOURCE_DIR}/LinkedList
    ${CMAKE_CURRENT_SOURCE_DIR}/Math_func
    ${CMAKE_CURRENT_SOURCE_DIR}/common
)

target_link_libraries(tests 
    gtest 
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)