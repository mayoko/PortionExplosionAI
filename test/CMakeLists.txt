cmake_minimum_required(VERSION 3.1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include(GoogleTest)

add_library(TestUtil STATIC
    TestUtil.cpp
)

add_executable(TestMain
    TestMarbleStorage.cpp
    TestMarbleColor.cpp
    TestPortion.cpp
    TestState.cpp
)
target_link_libraries(TestMain State Action TestUtil GTest::GTest GTest::Main)
include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

# For each Google Test, add CTest
gtest_add_tests(TARGET TestMain)