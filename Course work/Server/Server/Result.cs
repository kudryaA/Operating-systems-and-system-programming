using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Server
{
    class Result
    {
        private double result = 0;
        public Result(double[][] mas)
        {
            double summ = 0;
            for (int i = 0; i < mas.Length; i++)
            {
                for (int j = 0; j < mas.Length; j++)
                {
                    if (i == j)
                        summ += mas[i][j];
                }
            }
            result = summ;
        }

        public double ResultValue { get => result; }
    }
}
