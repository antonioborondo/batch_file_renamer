using System.Collections.Generic;

namespace WpfApp
{
    public class MainWindowModel
    {
        public List<string> Filenames
        {
            get
            {
                return new List<string>{"a.jpg", "b.jpg", "c.jpg", "d.jpg", "e.jpg"};
            }
        }
    }
}
