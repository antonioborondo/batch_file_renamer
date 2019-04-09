#include "utils.h"

#include <batch_file_renamer/batch_file_renamer.h>

#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

namespace fs = boost::filesystem;

extern fs::path test_files_directory;

namespace
{
    fs::path temporary_test_files_directory;
}

namespace batch_file_renamer_test
{
    class BatchFileRenamerTest : public testing::Test
    {
    public:
        virtual void SetUp()
        {
            temporary_test_files_directory = create_temporary_test_files_directory(test_files_directory);
        }

        virtual void TearDown()
        {
            try
            {
                fs::remove_all(temporary_test_files_directory);
            }
            catch (const fs::filesystem_error&)
            {
            }
        }
    };

    TEST_F(BatchFileRenamerTest, RenameFiles)
    {
        const auto directory = temporary_test_files_directory / "five_files_ordered_alphabetically";

        const auto filenames = get_filenames_from_directory(directory);

        const auto filenames_expected = batch_file_renamer::rename_files(filenames);

        const auto filenames_actual = get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }
}
