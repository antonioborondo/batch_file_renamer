#include <batch_file_renamer/batch_file_renamer.h>

#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem/path.hpp>
#include <gtest/gtest.h>

#include <vector>

TEST(BatchFileRenamer, RenameFilesTest)
{
    std::vector<boost::filesystem::path> files{"a.jpg", "b.jpg"};

    const auto result = batch_file_renamer::rename_files(files);

    ASSERT_TRUE(result);
}
