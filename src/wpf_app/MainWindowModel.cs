using System.Collections.Generic;
using System.ComponentModel;

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
            Filenames = new List<string> { "a.jpg", "b.jpg", "c.jpg", "d.jpg", "e.jpg" };
        }
    }
}
