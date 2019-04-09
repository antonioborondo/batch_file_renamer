#include <boost/filesystem/path.hpp>
#include <gtest/gtest.h>

namespace fs = boost::filesystem;

fs::path test_files_directory;

int main(int argc, char** argv)
{
    if (2 != argc)
    {
        return 1;
    }

    test_files_directory = argv[1];

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
