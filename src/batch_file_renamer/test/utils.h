#ifndef BATCH_FILE_RENAMER_TEST_H
#define BATCH_FILE_RENAMER_TEST_H

#include <boost/filesystem/path.hpp>

namespace batch_file_renamer_test
{
    bool copy_directory(const boost::filesystem::path& source_directory, const boost::filesystem::path& destination_directory);

    boost::filesystem::path create_temporary_test_files_directory(const boost::filesystem::path& test_files_directory);

    std::vector<boost::filesystem::path> get_filenames_from_directory(const boost::filesystem::path& directory);
}

#endif
