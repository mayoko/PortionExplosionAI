cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestMarbleStorage TestMarbleStorage.cpp)
target_link_libraries(TestMarbleStorage State GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

# For each Google Test, add CTest
gtest_add_tests(TARGET TestMarbleStorage)