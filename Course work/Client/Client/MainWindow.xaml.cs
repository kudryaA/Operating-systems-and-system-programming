using Newtonsoft.Json;
using System;
using System.Net.Sockets;
using System.Text;
using System.Windows;

namespace Client
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

        const int port = 1488;

        private void ButtonSend_Click(object sender, RoutedEventArgs e)
        {
            string address = "127.0.0.1";
            if (!tIP.Text.Equals(""))
            {
                address = tIP.Text;
            }
            double[][] mas = new double[3][];
            for (int i = 0; i < 3; i++)
            {
                mas[i] = new double[3];
            }
            mas[0][0] = Convert.ToDouble(t00.Text);
            mas[0][1] = Convert.ToDouble(t01.Text);
            mas[0][2] = Convert.ToDouble(t02.Text);

            mas[1][0] = Convert.ToDouble(t10.Text);
            mas[1][1] = Convert.ToDouble(t11.Text);
            mas[1][2] = Convert.ToDouble(t12.Text);

            mas[2][0] = Convert.ToDouble(t20.Text);
            mas[2][1] = Convert.ToDouble(t21.Text);
            mas[2][2] = Convert.ToDouble(t22.Text);
            TcpClient client = null;
            try
            {
                client = new TcpClient(address, port);
                NetworkStream stream = client.GetStream();

                string message = JsonConvert.SerializeObject(mas);
                Console.WriteLine(message);

                byte[] data = Encoding.UTF8.GetBytes(message);
                stream.Write(data, 0, data.Length);

                data = new byte[64]; 
                StringBuilder builder = new StringBuilder();
                int bytes = 0;
                do
                {
                    bytes = stream.Read(data, 0, data.Length);
                    builder.Append(Encoding.UTF8.GetString(data, 0, bytes));
                }
                while (stream.DataAvailable);

                message = builder.ToString();
                MessageBox.Show("Сума по диагонале = " + message);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка");
            }
            finally
            {
                client.Close();
            }
        }
    }
}
