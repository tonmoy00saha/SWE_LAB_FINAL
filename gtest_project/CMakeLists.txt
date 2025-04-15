cmake_minimum_required(VERSION 3.10)
project(GTestExample)

# Enable testing
enable_testing()

# Find Google Test package
find_package(GTest REQUIRED)

# Add the test executable
add_executable(test_example test_example.cpp)

# Link against GTest and pthread
target_link_libraries(test_example GTest::GTest GTest::Main pthread)
