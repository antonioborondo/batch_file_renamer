#include "filesystem_utils/filesystem_utils.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace filesystem_utils
{
    std::vector<fs::path> get_filenames_from_directory(const fs::path& directory)
    {
        std::vector<fs::path> filenames;

        if (fs::exists(directory) && fs::is_directory(directory))
        {
            for (fs::directory_iterator directory_iterator{ directory }; fs::directory_iterator{} != directory_iterator; directory_iterator++)
            {
                if (fs::is_regular_file(directory_iterator->status()))
                {
                    filenames.push_back(directory_iterator->path());
                }
            }
        }

        return filenames;
    }

    bool copy_directory(const fs::path& source_directory, const fs::path& destination_directory)
    {
        try
        {
            if (!fs::exists(source_directory) || !fs::is_directory(source_directory))
            {
                return false;
            }
            if (fs::exists(destination_directory))
            {
                return false;
            }
            if (!fs::create_directory(destination_directory))
            {
                return false;
            }
        }
        catch (const fs::filesystem_error&)
        {
            return false;
        }

        for (fs::directory_iterator directory_iterator{ source_directory }; fs::directory_iterator{} != directory_iterator; directory_iterator++)
        {
            try
            {
                const auto source_current = directory_iterator->path();
                const auto destination_current = destination_directory / source_current.filename();

                if (fs::is_directory(source_current))
                {
                    if (!filesystem_utils::copy_directory(source_current, destination_current))
                    {
                        return false;
                    }
                }
                else
                {
                    fs::copy_file(source_current, destination_current);
                }
            }
            catch (const fs::filesystem_error&)
            {
            }
        }

        return true;
    }
}
