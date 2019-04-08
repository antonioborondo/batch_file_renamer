#ifndef BATCH_FILE_RENAMER_H
#define BATCH_FILE_RENAMER_H

#include <boost/filesystem/path.hpp>

#include <vector>

namespace batch_file_renamer
{
    std::vector<boost::filesystem::path> rename_files(const std::vector<boost::filesystem::path>& filenames);
}

#endif
