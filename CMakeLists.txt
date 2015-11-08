cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(GURPSChase)


add_subdirectory(gtest)
INCLUDE_DIRECTORIES("${gtest_SOURCE_DIR}/include")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

# Project config information, principally version number
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

set(APP_SOURCE
        driver.cpp
        driver.h
	jsoncpp.cpp
        serializable.h
        skill.cpp
        skill.h
        vehicle.cpp
        vehicle.h
	)

set(TEST_SOURCE
    test_driver.cpp
    test_skill.cpp
    test_vehicle.cpp
    )

add_executable(${PROJECT_NAME}
	${APP_SOURCE}
        main.cpp
	)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_override)

set(TEST_NAME ${PROJECT_NAME}-test)
add_executable(${TEST_NAME}
    ${APP_SOURCE}
    ${TEST_SOURCE}
    )
target_link_libraries(${TEST_NAME} Qt5::Widgets Qt5::Core
    gtest
    gtest_main
)
target_compile_features(${TEST_NAME} PUBLIC cxx_override)
add_test(UnitTest  ${TEST_NAME})
