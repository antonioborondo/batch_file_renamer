using System;
using System.Runtime.InteropServices;
using System.Text;

namespace BatchFileRenamerCsharp
{
    public class BatchFileRenamer
    {
        [DllImport("batch_file_renamer_c.dll", EntryPoint = "rename_files_from_directory")]
        public static extern bool RenameFilesFromDirectory([MarshalAs(UnmanagedType.LPWStr)] string directory);
    }
}
