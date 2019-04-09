#ifndef BATCH_FILE_RENAMER_C_BATCH_FILE_RENAMER_H
#define BATCH_FILE_RENAMER_C_BATCH_FILE_RENAMER_H

#include <batch_file_renamer/batch_file_renamer.h>

extern "C" __declspec(dllexport) bool rename_files_from_directory(const wchar_t* directory);

#endif
