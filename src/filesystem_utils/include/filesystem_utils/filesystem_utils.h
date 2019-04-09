#ifndef FILESYSTEM_UTILS_FILESYSTEM_UTILS_H
#define FILESYSTEM_UTILS_FILESYSTEM_UTILS_H

#include <boost/filesystem/path.hpp>

#include <vector>

namespace filesystem_utils
{
    std::vector<boost::filesystem::path> get_filenames_from_directory(const boost::filesystem::path& directory);
    
    bool copy_directory(const boost::filesystem::path& source_directory, const boost::filesystem::path& destination_directory);
}

#endif
