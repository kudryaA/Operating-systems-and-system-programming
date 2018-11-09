using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Server
{
    class ServerWork
    {
        const int port = 1488;
        static TcpListener listener;
        private bool isWork = true;

        public ServerWork()
        {

        }

        public bool IsWork { get => isWork; set => isWork = value; }

        public void Process()
        {
            try
            {
                listener = new TcpListener(port);
                listener.Start();

                while (IsWork)
                {
                    TcpClient client = listener.AcceptTcpClient();
                    ClientObject clientObject = new ClientObject(client);
                    Thread clientThread = new Thread(new ThreadStart(clientObject.Process));
                    clientThread.SetApartmentState(ApartmentState.STA);
                    clientThread.Start();

                }
            }
            catch (Exception ex)
            {
            }
            finally
            {
                if (listener != null)
                    listener.Stop();
            }
        }
    }
}

