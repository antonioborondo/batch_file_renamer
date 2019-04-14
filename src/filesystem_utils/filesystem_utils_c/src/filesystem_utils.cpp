#include "filesystem_utils.h"

#include <filesystem_utils_cxx/filesystem_utils.h>

bool rename_files_from_directory(const wchar_t* directory)
{
    return filesystem_utils_cxx::rename_files_from_directory(directory);
}
