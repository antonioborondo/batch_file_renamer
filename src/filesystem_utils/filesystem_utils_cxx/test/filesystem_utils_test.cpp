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
    TEST(GetTemporaryDirectoryTest, TemporaryDirectoryWithinSystemTemporaryDirectory)
    {
        const auto system_temporary_directory = fs::temp_directory_path();

        const auto temporary_directory = filesystem_utils_cxx::get_temporary_directory();

        ASSERT_TRUE(temporary_directory.string().find(system_temporary_directory.string()) != std::string::npos);
    }

    TEST(GetTemporaryDirectoryTest, GetMultipleTemporaryDirectoriesReturnsDifferentPaths)
    {
        const auto temporary_directory_1 = filesystem_utils_cxx::get_temporary_directory();

        const auto temporary_directory_2 = filesystem_utils_cxx::get_temporary_directory();

        ASSERT_NE(temporary_directory_1, temporary_directory_2);
    }

    class FileSystemUtilsTest : public testing::Test
    {
    public:
        static void SetUpTestCase()
        {
            temporary_test_files_directory = filesystem_utils_cxx::get_temporary_directory();

            filesystem_utils_cxx::copy_directory(test_files_directory, temporary_test_files_directory);
        }

        static void TearDownTestCase()
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

    class GetFilenamesFromDirectoryTest : public FileSystemUtilsTest
    {
    };

    TEST_F(GetFilenamesFromDirectoryTest, NumbersWithoutLeadingZeros)
    {
        const auto directory = temporary_test_files_directory / "numbers_without_leading_zeros";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "1.txt",
            directory / "2.txt",
            directory / "11.txt",
            directory / "22.txt"
        };

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    TEST_F(GetFilenamesFromDirectoryTest, NumbersWithLeadingZeros)
    {
        const auto directory = temporary_test_files_directory / "numbers_with_leading_zeros";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "01.txt",
            directory / "02.txt",
            directory / "11.txt",
            directory / "22.txt"
        };

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    TEST_F(GetFilenamesFromDirectoryTest, Alphanumeric)
    {
        const auto directory = temporary_test_files_directory / "alphanumeric";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "1.txt",
            directory / "1a.txt",
            directory / "2.txt",
            directory / "11.txt",
            directory / "a.txt",
            directory / "a1.txt",
            directory / "a2.txt",
            directory / "a11.txt",
            directory / "aa.txt",
            directory / "b.txt",
            directory / "ba.txt",
            directory / "bb.txt"
        };

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    class RenameFilesTest : public FileSystemUtilsTest
    {
    };

    TEST_F(RenameFilesTest, LessThanTen)
    {
        const auto directory = temporary_test_files_directory / "less_than_ten";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "1.txt",
            directory / "2.txt",
            directory / "3.txt",
            directory / "4.txt",
            directory / "5.txt",
            directory / "6.txt",
            directory / "7.txt",
            directory / "8.txt",
            directory / "9.txt"
        };

        const auto filenames = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(filesystem_utils_cxx::rename_files(filenames));

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    TEST_F(RenameFilesTest, Ten)
    {
        const auto directory = temporary_test_files_directory / "ten";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "01.txt",
            directory / "02.txt",
            directory / "03.txt",
            directory / "04.txt",
            directory / "05.txt",
            directory / "06.txt",
            directory / "07.txt",
            directory / "08.txt",
            directory / "09.txt",
            directory / "10.txt"
        };

        const auto filenames = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(filesystem_utils_cxx::rename_files(filenames));

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    TEST_F(RenameFilesTest, MoreThanTen)
    {
        const auto directory = temporary_test_files_directory / "more_than_ten";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "01.txt",
            directory / "02.txt",
            directory / "03.txt",
            directory / "04.txt",
            directory / "05.txt",
            directory / "06.txt",
            directory / "07.txt",
            directory / "08.txt",
            directory / "09.txt",
            directory / "10.txt",
            directory / "11.txt"
        };

        const auto filenames = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(filesystem_utils_cxx::rename_files(filenames));

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    class RenameFilesFromDirectoryTest : public FileSystemUtilsTest
    {
    };

    TEST_F(RenameFilesFromDirectoryTest, LessThanTen)
    {
        const auto directory = temporary_test_files_directory / "less_than_ten";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "1.txt",
            directory / "2.txt",
            directory / "3.txt",
            directory / "4.txt",
            directory / "5.txt",
            directory / "6.txt",
            directory / "7.txt",
            directory / "8.txt",
            directory / "9.txt"
        };
        
        ASSERT_TRUE(filesystem_utils_cxx::rename_files_from_directory(directory));

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    TEST_F(RenameFilesFromDirectoryTest, Ten)
    {
        const auto directory = temporary_test_files_directory / "ten";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "01.txt",
            directory / "02.txt",
            directory / "03.txt",
            directory / "04.txt",
            directory / "05.txt",
            directory / "06.txt",
            directory / "07.txt",
            directory / "08.txt",
            directory / "09.txt",
            directory / "10.txt"
        };

        ASSERT_TRUE(filesystem_utils_cxx::rename_files_from_directory(directory));

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }

    TEST_F(RenameFilesFromDirectoryTest, MoreThanTen)
    {
        const auto directory = temporary_test_files_directory / "more_than_ten";

        const std::vector<fs::path> filenames_expected =
        {
            directory / "01.txt",
            directory / "02.txt",
            directory / "03.txt",
            directory / "04.txt",
            directory / "05.txt",
            directory / "06.txt",
            directory / "07.txt",
            directory / "08.txt",
            directory / "09.txt",
            directory / "10.txt",
            directory / "11.txt"
        };

        ASSERT_TRUE(filesystem_utils_cxx::rename_files_from_directory(directory));

        const auto filenames_actual = filesystem_utils_cxx::get_filenames_from_directory(directory);

        ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
    }
}
