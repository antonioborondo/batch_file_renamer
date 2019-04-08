project(batch_file_renamer)

set(PUBLIC_HEADER_FILES_FOLDER include)
set(SOURCE_FILES_FOLDER src)
set(TEST_FILES_FOLDER test)

set(HEADER_FILES
    ${PUBLIC_HEADER_FILES_FOLDER}/batch_file_renamer/batch_file_renamer.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_FOLDER}/batch_file_renamer.cpp
)

add_library(batch_file_renamer
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_include_directories(batch_file_renamer
    PRIVATE
    ${PUBLIC_HEADER_FILES_FOLDER}
    ${SOURCE_FILES_FOLDER}
)

target_link_libraries(batch_file_renamer
    PUBLIC
    CONAN_PKG::boost_filesystem
)

set_target_properties(batch_file_renamer PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/${PUBLIC_HEADER_FILES_FOLDER}
)

set(TEST_FILES
    ${TEST_FILES_FOLDER}/batch_file_renamer_test.cpp
)

add_executable(batch_file_renamer_test
    ${TEST_FILES}
)

target_link_libraries(batch_file_renamer_test
    PRIVATE
    batch_file_renamer
    CONAN_PKG::gtest
)
