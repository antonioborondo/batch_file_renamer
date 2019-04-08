#include <batch_file_renamer/batch_file_renamer.h>

#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <gtest/gtest.h>

namespace fs = boost::filesystem;

extern fs::path test_files_directory;

namespace
{
    fs::path temporary_test_files_directory;

    bool my_copy_directory(fs::path const & source, fs::path const & destination)
    {
        namespace fs = boost::filesystem;
        try
        {
            // Check whether the function call is valid
            if (
                !fs::exists(source) ||
                !fs::is_directory(source)
                )
            {
                std::cerr << "Source directory " << source.string()
                    << " does not exist or is not a directory." << '\n'
                    ;
                return false;
            }
            if (fs::exists(destination))
            {
                std::cerr << "Destination directory " << destination.string()
                    << " already exists." << '\n'
                    ;
                return false;
            }
            // Create the destination directory
            if (!fs::create_directory(destination))
            {
                std::cerr << "Unable to create destination directory"
                    << destination.string() << '\n'
                    ;
                return false;
            }
        }
        catch (fs::filesystem_error const & e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        // Iterate through the source directory
        for (
            fs::directory_iterator file(source);
            file != fs::directory_iterator(); ++file
            )
        {
            try
            {
                fs::path current(file->path());
                if (fs::is_directory(current))
                {
                    // Found directory: Recursion
                    if (
                        !my_copy_directory(
                            current,
                            destination / current.filename()
                        )
                        )
                    {
                        return false;
                    }
                }
                else
                {
                    // Found file: Copy
                    fs::copy_file(
                        current,
                        destination / current.filename()
                    );
                }
            }
            catch (fs::filesystem_error const & e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        return true;
    }

    fs::path create_temporary_test_files_directory()
    {
        const auto temporary_test_files_directory = fs::temp_directory_path() / fs::unique_path();

        my_copy_directory(test_files_directory, temporary_test_files_directory);
    
        return temporary_test_files_directory;
    }

    std::vector<fs::path> get_filenames_from_directory(fs::path directory)
    {
        std::vector<fs::path> filenames;
        
        if (fs::exists(directory) && fs::is_directory(directory))
        {
            fs::directory_iterator iterator_end;
            for (fs::directory_iterator iterator(directory); iterator != iterator_end; iterator++)
            {
                if (fs::is_regular_file(iterator->status()))
                {
                    filenames.push_back(iterator->path());
                }
            }
        }

        return filenames;
    }
}

class BatchFileRenamerTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        temporary_test_files_directory = create_temporary_test_files_directory();
    }

    virtual void TearDown()
    {
        fs::remove_all(temporary_test_files_directory);
    }
};

TEST_F(BatchFileRenamerTest, RenameFiles)
{
    const auto temporary_test_case_files_directory = temporary_test_files_directory / "five_files_ordered_alphabetically";

    const auto filenames = get_filenames_from_directory(temporary_test_case_files_directory);

    const auto filenames_expected = batch_file_renamer::rename_files(filenames);

    const auto filenames_actual = get_filenames_from_directory(temporary_test_case_files_directory);

    ASSERT_TRUE(std::equal(filenames_expected.begin(), filenames_expected.end(), filenames_actual.begin()));
}
