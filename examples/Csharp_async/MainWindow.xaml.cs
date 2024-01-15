using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;                       // Для запуска новых потоков
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Csharp_async
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        PiCalc pi_calc = new PiCalc();

        public MainWindow()
        {
            InitializeComponent();
            // получим количество ядер (sic) процессора
            label_cores_n.Content = Environment.ProcessorCount.ToString();
        }

        /// <summary> Метод обновления полосы прогресса </summary>
        private void update()        {
           // этот метод будет вызываться из другого потока (у которого нет доступа к данному объекту (окну)
           // поэтому обратися к Диспетчеру, и поместим анонимную функцию в очередь обработки текущим для окна потоком 
            Dispatcher.BeginInvoke(new Action(() => { progressBar.Value = progressBar.Value + 10; }));
        }

        /// <summary> Запуск вычислений в текущем потоке. Блокирует цикл обработки событий -> взаимодейтсвие с окном будет недоступно до завершения метода. </summary>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            pi_calc.N = Convert.ToUInt64(Convert.ToDouble(textbox_n.Text))*1000_000;   // todo: сделать проверку

            pi_calc.calc( update );

            textbox_result.Text = pi_calc.get_pi().ToString();
        }

        /// <summary> Запуск вычислений в отдельном, новом потоке. Не блокирует цикл обработки событий</summary>
        private async void btn_run_sep_thread_Click(object sender, RoutedEventArgs e){
            pi_calc.N = Convert.ToUInt64(Convert.ToDouble(textbox_n.Text)) * 1000_000;   // todo: сделать проверку

            // async позволяет приостановить выполнение метода, сохранить его состояние,
            // до тех пор пока операция await запущенная в параллельном потоке, не завершится
            btn_run_sep_thread.IsEnabled = false;
            progressBar.Value = 0;

            var result = await Task.Run( () => pi_calc.calc(update) );
            // var вместо типа - сообщение компилятору самостоятельно вывести тип
            // await неблокирующее ожидание завершения операции 
            // () => pi_calc.calc() -- анонимная функция без параметров, тело функции приведено после =>
            // update -- специальная callback функция, которая безопасно может быть вызвана из не основного потока
            // по логике calc эта функция будет вызываться каждые 10% прогресса вычислений

            textbox_result.Text = pi_calc.get_pi().ToString();
            btn_run_sep_thread.IsEnabled = true;
        }

        private void btn_stop_Click(object sender, RoutedEventArgs e)
        {
            pi_calc.stop = true;
        }
    }
}

// todo: остановка задачи
// todo: замер времени выполнения
