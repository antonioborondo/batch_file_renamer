cmake_minimum_required(VERSION 3.10)

project(batch_file_renamer)

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

conan_cmake_run(REQUIRES boost_filesystem/1.69.0@bincrafters/stable
    BASIC_SETUP CMAKE_TARGETS
    BUILD missing
)

add_subdirectory(src/batch_file_renamer)
