cmake_minimum_required(VERSION 3.10)

project(batch_file_renamer)

# Conan
SET(conan_cmake ${CMAKE_BINARY_DIR}/conan.cmake)

if(NOT EXISTS ${conan_cmake})
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/develop/conan.cmake" ${conan_cmake})
endif()

include(${conan_cmake})

conan_cmake_run(
    REQUIRES
    boost_filesystem/1.69.0@bincrafters/stable
    gtest/1.8.0@bincrafters/stable
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

add_subdirectory(src/batch_file_renamer)
add_subdirectory(src/wpf_app)

# CTest
enable_testing()

set(TEST_FILES_DIRECTORY ${CMAKE_SOURCE_DIR}/test_files)

add_test(NAME batch_file_renamer_test COMMAND batch_file_renamer_test ${TEST_FILES_DIRECTORY})
