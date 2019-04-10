using FilesystemUtilsCsharp;
using NaturalSort.Extension;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;

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
                return this.directory;
            }
            set
            {
                this.directory = value;
                this.PropertyChanged(this, new PropertyChangedEventArgs("Directory"));
            }
        }

        private IOrderedEnumerable<string> filenames;

        public IOrderedEnumerable<string> Filenames
        {
            get
            {
                return this.filenames;
            }
            set
            {
                this.filenames = value;
                this.PropertyChanged(this, new PropertyChangedEventArgs("Filenames"));
            }
        }

        public void OpenDirectory()
        {
            this.GetFilenamesFromDirectory();
        }

        public void RenameFiles()
        {
            FilesystemUtils.RenameFilesFromDirectory(this.Directory);

            this.GetFilenamesFromDirectory();
        }

        private void GetFilenamesFromDirectory()
        {
            var filenamesFromDirectory = new List<string>();

            var directoryInfo = new DirectoryInfo(this.Directory);
            var files = directoryInfo.GetFiles();
            foreach (FileInfo file in files)
            {
                filenamesFromDirectory.Add(file.Name);
            }

            this.Filenames = filenamesFromDirectory.OrderBy(x => x, StringComparer.OrdinalIgnoreCase.WithNaturalSort());
        }
    }
}
