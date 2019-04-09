project(batch_file_renamer_c)

set(PUBLIC_HEADER_FILES_FOLDER include)
set(SOURCE_FILES_FOLDER src)

set(HEADER_FILES
    ${PUBLIC_HEADER_FILES_FOLDER}/batch_file_renamer_c/batch_file_renamer.h
)

set(SOURCE_FILES
    ${SOURCE_FILES_FOLDER}/batch_file_renamer.cpp
)

add_library(batch_file_renamer_c SHARED
    ${HEADER_FILES}
    ${SOURCE_FILES}
)

target_include_directories(batch_file_renamer_c
    PRIVATE
    ${PUBLIC_HEADER_FILES_FOLDER}
    ${SOURCE_FILES_FOLDER}
)

target_link_libraries(batch_file_renamer_c
    PRIVATE
    batch_file_renamer
)

set_target_properties(batch_file_renamer_c PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/${PUBLIC_HEADER_FILES_FOLDER}
    FOLDER batch_file_renamer
)
