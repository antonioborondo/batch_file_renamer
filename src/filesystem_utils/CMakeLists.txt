project(filesystem_utils)

set(PUBLIC_HEADER_FILES_FOLDER include)
set(SOURCE_FILES_FOLDER src)

set(HEADER_FILES
    ${PUBLIC_HEADER_FILES_FOLDER}/filesystem_utils/filesystem_utils.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_FOLDER}/filesystem_utils.cpp
)

add_library(filesystem_utils
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_include_directories(filesystem_utils
    PRIVATE
    ${PUBLIC_HEADER_FILES_FOLDER}
    ${SOURCE_FILES_FOLDER}
)

target_link_libraries(filesystem_utils
    PUBLIC
    CONAN_PKG::boost_filesystem
)

set_target_properties(filesystem_utils PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/${PUBLIC_HEADER_FILES_FOLDER}
)
