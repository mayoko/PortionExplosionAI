cmake_minimum_required(VERSION 3.1)

add_library(TestUtil STATIC
    TestUtil.cpp
)

add_executable(TestMain
    TestMarbleStorage.cpp
    TestMarbleColor.cpp
    TestPortion.cpp
    TestState.cpp)
target_link_libraries(TestMain State Action TestUtil
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/googletest-release-1.8.1/build/googlemock/gtest/libgtest.a
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/googletest-release-1.8.1/build/googlemock/gtest/libgtest_main.a
    pthread)
target_include_directories(TestMain PUBLIC
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/googletest-release-1.8.1/googletest/include)
