cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(TestMarbleStorage TestMarbleStorage.cpp)
target_link_libraries(TestMarbleStorage State GTest::GTest GTest::Main)
add_executable(TestMarbleColor TestMarbleColor.cpp)
target_link_libraries(TestMarbleColor State GTest::GTest GTest::Main)
add_executable(TestPortion TestPortion.cpp)
target_link_libraries(TestPortion State GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

# For each Google Test, add CTest
gtest_add_tests(TARGET TestMarbleStorage)
gtest_add_tests(TARGET TestMarbleColor)
gtest_add_tests(TARGET TestPortion)