/// Модуль для вычислений
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Csharp_async
{   
   /// <summary>
   /// Вычисляет число Пи методом Монте-Карло
   /// </summary>
    class PiCalc
    {
        double pi;
        /// <summary>
        /// количество итераций для вычислений
        /// </summary>
        ulong n;

        public ulong N { get => n;
                         set { if (value > 0) n = value; } }

        /// <summary> Вычисляет и возвращает число Пи </summary>
        /// <returns> Вычисленное число Пи</returns>
        public double calc() { pi = 0; 
            // todo: пояснить
            Random rnd = new Random();
            ulong inside_sector = 0;
            for (ulong i = 0; i<n; i++)
            {
                double x = rnd.NextDouble();
                double y = rnd.NextDouble();

                if (x*x + y*y <= 1.0)
                    inside_sector++;
            }
            pi = Convert.ToDouble(inside_sector)/ Convert.ToDouble(n) * 4;
            return pi; }

        /// <returns> ранее вычисленное число Пи </returns>
        public double get_pi() { return pi; }
    }
}

/* Этот класс занимается только вычислениями и не управляет потоками */
