#include "utils.h"

#include <filesystem_utils/filesystem_utils.h>

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace batch_file_renamer_test
{
    fs::path create_temporary_test_files_directory(const fs::path& test_files_directory)
    {
        const auto temporary_test_files_directory = fs::temp_directory_path() / fs::unique_path();

        filesystem_utils::copy_directory(test_files_directory, temporary_test_files_directory);

        return temporary_test_files_directory;
    }
}
