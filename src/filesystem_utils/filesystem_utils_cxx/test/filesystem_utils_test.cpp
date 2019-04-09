#include <filesystem_utils_cxx/filesystem_utils.h>

#include <boost/filesystem.hpp>
#include <gtest/gtest.h>

namespace fs = boost::filesystem;

extern fs::path test_files_directory;

namespace
{
    fs::path temporary_test_files_directory;
}

namespace filesystem_utils_cxx_test
{
    class FilesystemUtilsTest : public testing::Test
    {
    public:
        virtual void SetUp()
        {
            temporary_test_files_directory = filesystem_utils_cxx::get_temporary_folder();
            
            filesystem_utils_cxx::copy_directory(test_files_directory, temporary_test_files_directory);
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

    TEST_F(FilesystemUtilsTest, RenameFiles)
    {
        const auto directory = temporary_test_files_directory / "five_files_ordered_alphabetically";

        ASSERT_TRUE(filesystem_utils_cxx::rename_files_from_directory(directory));

        const std::vector<fs::path> filenames_expected = { directory / "1.txt", directory / "2.txt", directory / "3.txt", directory / "4.txt", directory / "5.txt"};

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }
}
