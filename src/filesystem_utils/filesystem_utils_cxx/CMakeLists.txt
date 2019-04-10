project(filesystem_utils_cxx)

set(PUBLIC_HEADER_FILES_FOLDER include)
set(SOURCE_FILES_FOLDER src)
set(TEST_FILES_FOLDER test)

set(HEADER_FILES
    ${PUBLIC_HEADER_FILES_FOLDER}/filesystem_utils_cxx/filesystem_utils.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_FOLDER}/filesystem_utils.cpp
)

add_library(filesystem_utils_cxx
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_include_directories(filesystem_utils_cxx
    PRIVATE
    ${PUBLIC_HEADER_FILES_FOLDER}
)

target_link_libraries(filesystem_utils_cxx
    PRIVATE
    CONAN_PKG::fmt
    natural_sort
    PUBLIC
    CONAN_PKG::boost_filesystem
)

set_target_properties(filesystem_utils_cxx PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/${PUBLIC_HEADER_FILES_FOLDER}
    FOLDER filesystem_utils/cxx
)

set(TEST_FILES
    ${TEST_FILES_FOLDER}/filesystem_utils_test.cpp
    ${TEST_FILES_FOLDER}/main.cpp
)

add_executable(filesystem_utils_cxx_test
    ${TEST_FILES}
)

target_link_libraries(filesystem_utils_cxx_test
    PRIVATE
    filesystem_utils_cxx
    CONAN_PKG::gtest
)

set_target_properties(filesystem_utils_cxx_test PROPERTIES
    FOLDER filesystem_utils/cxx
)
