#include "batch_file_renamer/batch_file_renamer.h"

#include <filesystem_utils/filesystem_utils.h>

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace
{
    bool rename_files(const std::vector<fs::path>& filenames)
    {
        auto result = true;

        for (auto i = 0; i < filenames.size(); i++)
        {
            const auto filename = filenames.at(i);
            const auto new_filename = filename.parent_path() / fs::path{ std::to_wstring(i + 1) + filename.extension().wstring() };

            try
            {
                fs::rename(filename, new_filename);
            }
            catch (const fs::filesystem_error&)
            {
                result = false;
            }
        }

        return result;
    }
}

namespace batch_file_renamer
{
    bool rename_files_from_directory(const fs::path& directory)
    {
        const auto filenames = filesystem_utils::get_filenames_from_directory(directory);

        return rename_files(filenames);
    }
}
