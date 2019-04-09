project(filesystem_utils_csharp LANGUAGES CSharp)

include(CSharpUtilities)

set(PROPERTY_FILES
    Properties/AssemblyInfo.cs
)

set(SOURCE_FILES
    ${PROPERTY_FILES}
    FilesystemUtils.cs
)

add_library(filesystem_utils_csharp SHARED ${SOURCE_FILES})

add_dependencies(filesystem_utils_csharp
    filesystem_utils_c
)

csharp_set_designer_cs_properties(${PROPERTY_FILES})

set_target_properties(filesystem_utils_csharp PROPERTIES
    FOLDER filesystem_utils/csharp
)
