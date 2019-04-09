project(filesystem_utils_c)

set(PUBLIC_HEADER_FILES_FOLDER include)
set(SOURCE_FILES_FOLDER src)

set(HEADER_FILES
    ${PUBLIC_HEADER_FILES_FOLDER}/filesystem_utils_c/filesystem_utils.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_FOLDER}/filesystem_utils.cpp
)

add_library(filesystem_utils_c SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_include_directories(filesystem_utils_c
    PRIVATE
    ${PUBLIC_HEADER_FILES_FOLDER}
)

target_link_libraries(filesystem_utils_c
    PRIVATE
    filesystem_utils_cxx
)

set_target_properties(filesystem_utils_c PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/${PUBLIC_HEADER_FILES_FOLDER}
    FOLDER filesystem_utils/c
)
