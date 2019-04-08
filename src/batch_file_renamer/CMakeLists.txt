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
