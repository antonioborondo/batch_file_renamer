#include "batch_file_renamer/batch_file_renamer.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace batch_file_renamer
{
    std::vector<fs::path> rename_files(const std::vector<fs::path>& filenames)
    {
        std::vector<fs::path> new_filenames;

        for (auto i = 0; i < filenames.size(); i++)
        {
            const auto filename = filenames.at(i);
            const auto new_filename = filename.parent_path() / fs::path{std::to_wstring(i + 1) + filename.extension().wstring()};
            
            fs::rename(filename, new_filename);

            new_filenames.push_back(new_filename);
        }

        return new_filenames;
    }
}
