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
        // Специальный тип, для Callback функции, через вызов которой будет сообщаться прогресс вычислений
        public delegate void StepCallback();

        // проверяемая в цикле вычислений переменная, отвечает за остановку метода вычислений
        public bool stop = false;

        double pi;
        /// <summary> количество итераций для вычислений </summary>
        ulong n;

        public ulong N { get => n;
                         set { if (value > 0) n = value; } }

        /// <summary>
        /// Вычисляет число Пи
        /// </summary>
        /// <param name="upd_progress">Функция обратого вызова (callback), вызывается каждые 10% итераций</param>
        /// <returns>число Пи</returns>
        public double calc(StepCallback upd_progress) {
            stop = false;
            pi = 0; 
            // todo: пояснить
            Random rnd = new Random();
            ulong inside_sector = 0;

            ulong step10 = n / 10;
            for (ulong i = 0; i<n && !stop; i++)
            {
                double x = rnd.NextDouble();
                double y = rnd.NextDouble();

                if (x*x + y*y <= 1.0)
                    inside_sector++;

                if ((i+1) % step10 == 0)
                    upd_progress();
            }
            pi = Convert.ToDouble(inside_sector)/ Convert.ToDouble(n) * 4;
            return pi; }

       
        /// <returns>Ранее вычисленное число Пи</returns>
        public double get_pi() { return pi; }
    }
}

/* Этот класс занимается только вычислениями и не управляет потоками */
