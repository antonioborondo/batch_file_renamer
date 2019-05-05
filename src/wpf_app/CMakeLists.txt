project(wpf_app LANGUAGES CSharp)

include(CSharpUtilities)

set(PROPERTY_FILES
    Properties/AssemblyInfo.cs
)

set(XAML_FILES
    App.xaml
    App.xaml.cs
    MainWindow.xaml
    MainWindow.xaml.cs
)

set(SOURCE_FILES
    ${PROPERTY_FILES}
    ${XAML_FILES}
    App.config
    MainWindowModel.cs
)

add_executable(wpf_app ${SOURCE_FILES})

csharp_set_designer_cs_properties(${PROPERTY_FILES})

csharp_set_xaml_cs_properties(${XAML_FILES})

set_property(SOURCE App.xaml PROPERTY VS_XAML_TYPE "ApplicationDefinition")

set_property(TARGET wpf_app PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "v4.5")

set_property(TARGET wpf_app PROPERTY WIN32_EXECUTABLE TRUE)

target_link_libraries(wpf_app
    PRIVATE
    filesystem_utils_csharp
)

set_property(TARGET wpf_app PROPERTY VS_DOTNET_REFERENCES
    PresentationCore
    PresentationFramework
    System
    System.Windows.Forms
    System.Xaml
    WindowsBase
    "packages/NaturalSort.Extension.2.0.0/lib/net40/NaturalSort.Extension.dll"
)

nuget(wpf_app)
