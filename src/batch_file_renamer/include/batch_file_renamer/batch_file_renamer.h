#ifndef BATCH_FILE_RENAMER_H
#define BATCH_FILE_RENAMER_H

#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem/path.hpp>

#include <vector>

namespace batch_file_renamer
{
    bool rename_files(std::vector<boost::filesystem::path> files);
}

#endif
