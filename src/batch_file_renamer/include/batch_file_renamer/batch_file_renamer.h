#ifndef BATCH_FILE_RENAMER_BATCH_FILE_RENAMER_H
#define BATCH_FILE_RENAMER_BATCH_FILE_RENAMER_H

#include <boost/filesystem/path.hpp>

namespace batch_file_renamer
{
    bool rename_files_from_directory(const boost::filesystem::path& directory);
}

#endif
