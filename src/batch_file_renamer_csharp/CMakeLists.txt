project(batch_file_renamer_csharp LANGUAGES CSharp)

include(CSharpUtilities)

set(PROPERTY_FILES
    Properties/AssemblyInfo.cs
)

set(SOURCE_FILES
    ${PROPERTY_FILES}
    BatchFileRenamer.cs
)

add_library(batch_file_renamer_csharp SHARED ${SOURCE_FILES})

add_dependencies(batch_file_renamer_csharp
    batch_file_renamer_c
)

csharp_set_designer_cs_properties(${PROPERTY_FILES})

set_target_properties(batch_file_renamer_csharp PROPERTIES
    FOLDER batch_file_renamer
)
