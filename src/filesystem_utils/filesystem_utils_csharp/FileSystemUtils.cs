using System;
using System.Runtime.InteropServices;
using System.Text;

namespace FilesystemUtilsCsharp
{
    public class FilesystemUtils
    {
        [DllImport("filesystem_utils_c.dll", EntryPoint = "rename_files_from_directory")]
        public static extern bool RenameFilesFromDirectory([MarshalAs(UnmanagedType.LPWStr)] string directory);
    }
}
