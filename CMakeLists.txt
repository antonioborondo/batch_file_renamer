cmake_minimum_required(VERSION 3.10)

project(batch_file_renamer)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(BINARY_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIRECTORY})

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
    fmt/5.3.0@bincrafters/stable
    gtest/1.8.0@bincrafters/stable
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

# NuGet
SET(nuget_cmake ${CMAKE_BINARY_DIR}/nuget.cmake)

if(NOT EXISTS ${nuget_cmake})
    message(STATUS "Downloading nuget.cmake from https://github.com/antonioborondo/cmake_nuget")
    file(DOWNLOAD "https://raw.githubusercontent.com/antonioborondo/cmake_nuget/master/nuget.cmake" ${nuget_cmake})
endif()

include(${nuget_cmake})

# NaturalSort library
SET(natural_sort_single_include ${CMAKE_CURRENT_BINARY_DIR}/natural_sort/include/natural_sort/natural_sort.hpp)

if(NOT EXISTS ${natural_sort_single_include})
    message(STATUS "Downloading NaturalSort from https://github.com/scopeInfinity/NaturalSort")
    file(DOWNLOAD "https://raw.githubusercontent.com/scopeInfinity/NaturalSort/master/natural_sort.hpp" ${natural_sort_single_include})
endif()

add_library(natural_sort INTERFACE)

target_include_directories(natural_sort INTERFACE ${CMAKE_CURRENT_BINARY_DIR}/natural_sort/include)

add_subdirectory(src/filesystem_utils)
add_subdirectory(src/wpf_app)

# CTest
enable_testing()

set(TEST_FILES_DIRECTORY ${CMAKE_SOURCE_DIR}/test_files)

add_test(NAME filesystem_utils_cxx_test COMMAND filesystem_utils_cxx_test ${TEST_FILES_DIRECTORY})
