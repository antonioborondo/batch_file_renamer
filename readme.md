# Batch file renamer
[![Build status](https://ci.appveyor.com/api/projects/status/7o2oy4ajr4r5tpcu?svg=true)](https://ci.appveyor.com/project/antonioborondo/batch-file-renamer)

![Screenshot](screenshot.png?raw=true)

## Description
Application to batch rename all the files contained in a selected folder using numbers with dynamically generated leading zeros to keep the same filename length.

## Features
- Project generated with CMake that combines C++ and C#.
- Batch file renaming library implemented with C++.
- UI implemented with C#.
- C++ library consumed by C# using P/Invoke.
- C++ packages managed with Conan.
- C# packages managed with NuGet.
- C++ unit tests implemented with Google Test.
- CI implemented with AppVeyor.

## Libraries
C++:
- boost: https://www.boost.org
- fmt: https://www.github.com/fmtlib/fmt
- Google Test: https://www.github.com/google/googletest
- NaturalSort: https://www.github.com/scopeInfinity/NaturalSort

C#:
- NaturalSort.Extension: https://www.nuget.org/packages/NaturalSort.Extension
- WPF: https://docs.microsoft.com/en-us/dotnet/framework/wpf

## Tools
- AppVeyor: https://www.appveyor.com
- CMake: https://www.cmake.org
- Conan: https://www.conan.io
- NuGet: https://www.nuget.org
- nuget_cmake: https://www.github.com/antonioborondo/nuget_cmake
