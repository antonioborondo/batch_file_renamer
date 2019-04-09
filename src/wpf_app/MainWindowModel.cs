using BatchFileRenamerCsharp;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;

namespace WpfApp
{
    public class MainWindowModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private string directory;

        public string Directory
        {
            get
            {
                return directory;
            }
            set
            {
                directory = value;
                PropertyChanged(this, new PropertyChangedEventArgs("Directory"));
            }
        }

        private List<string> filenames;

        public List<string> Filenames
        {
            get
            {
                return filenames;
            }
            set
            {
                filenames = value;
                PropertyChanged(this, new PropertyChangedEventArgs("Filenames"));
            }
        }

        public void OpenDirectory()
        {
            GetFilenamesFromDirectory();
        }

        public void RenameFiles()
        {
            BatchFileRenamer.RenameFilesFromDirectory(Directory);

            GetFilenamesFromDirectory();
        }

        private void GetFilenamesFromDirectory()
        {
            var filenamesFromDirectory = new List<string>();

            DirectoryInfo directoryInfo = new DirectoryInfo(Directory);
            FileInfo[] Files = directoryInfo.GetFiles();
            foreach (FileInfo file in Files)
            {
                filenamesFromDirectory.Add(file.Name);
            }

            Filenames = filenamesFromDirectory;
        }
    }
}
