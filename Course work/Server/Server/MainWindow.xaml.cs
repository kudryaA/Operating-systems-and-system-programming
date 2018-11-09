using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Server
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private TcpListener listener;
        private int port = 1488;

        private void ButtonExit_Click(object sender, RoutedEventArgs e)
        {
            Environment.Exit(0);
        }

        private void ButtonStart_Click(object sender, RoutedEventArgs e)
        {
            ButtonStart.IsEnabled = false;
            Thread serverThread = new Thread(new ThreadStart(new ServerWork().Process));
            serverThread.Start();
        }
    }
}
