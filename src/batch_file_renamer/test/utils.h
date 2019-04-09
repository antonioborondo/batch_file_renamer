#ifndef BATCH_FILE_RENAMER_TEST_H
#define BATCH_FILE_RENAMER_TEST_H

#include <boost/filesystem/path.hpp>

namespace batch_file_renamer_test
{
    boost::filesystem::path create_temporary_test_files_directory(const boost::filesystem::path& test_files_directory);
}

#endif
