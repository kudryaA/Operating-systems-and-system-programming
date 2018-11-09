using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Server
{
    class ClientObject
    {
        public TcpClient client;

        public ClientObject(TcpClient tcpClient)
        {
            client = tcpClient;
        }

        public void Process()
        {
            NetworkStream stream = null;
            try
            {
                stream = client.GetStream();

                byte[] data = new byte[1024];
                while (true)
                {
                    StringBuilder builder = new StringBuilder();
                    int bytes = 0;
                    string message = "";
                    do
                    {
                        bytes = stream.Read(data, 0, data.Length);
                        builder.Append(Encoding.UTF8.GetString(data, 0, bytes));
                    }
                    while (stream.DataAvailable);
                    message = builder.ToString();
                    double[][] res = JsonConvert.DeserializeObject<double[][]>(message);
                    data = Encoding.UTF8.GetBytes(Convert.ToString(new Result(res).ResultValue));
                    stream.Write(data, 0, data.Length);
                }
            }
            catch (Exception ex)
            { }
            finally
            {
                if (stream != null)
                    stream.Close();
                if (client != null)
                    client.Close();
            }
        }
    }
}
