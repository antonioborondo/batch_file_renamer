#ifndef FILESYSTEM_UTILS_CXX_FILESYSTEM_UTILS_H
#define FILESYSTEM_UTILS_CXX_FILESYSTEM_UTILS_H

#include <boost/filesystem/path.hpp>

#include <vector>

namespace filesystem_utils_cxx
{
    std::vector<boost::filesystem::path> get_filenames_from_directory(const boost::filesystem::path& directory);

    bool rename_files(const std::vector<boost::filesystem::path>& filenames);
    
    bool rename_files_from_directory(const boost::filesystem::path& directory);

    bool copy_directory(const boost::filesystem::path& source_directory, const boost::filesystem::path& destination_directory);

    boost::filesystem::path get_temporary_folder();
}

#endif
