using System.Windows;
using System.Windows.Input;

namespace WpfApp
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            this.InitializeComponent();

            this.DataContext = new MainWindowModel();
        }

        private void OpenDirectory_Click(object sender, MouseButtonEventArgs e)
        {
            using (var folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog())
            {
                if (folderBrowserDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    if (this.DataContext != null)
                    {
                        var mainWindowModel = (this.DataContext as MainWindowModel);
                        mainWindowModel.Directory = folderBrowserDialog.SelectedPath;
                        mainWindowModel.OpenDirectory();
                    }
                }
            }
        }

        private void RenameFiles_Click(object sender, MouseButtonEventArgs e)
        {
            if (this.DataContext != null)
            {
                (this.DataContext as MainWindowModel).RenameFiles();
            }
        }
    }
}
