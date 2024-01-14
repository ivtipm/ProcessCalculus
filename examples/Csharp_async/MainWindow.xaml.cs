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


        /// <summary> Запуск вычислений в текущем потоке. Блокирует цикл обработки событий -> взаимодейтсвие с окном будет недоступно до завершения метода. </summary>
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            pi_calc.N = Convert.ToUInt64(Convert.ToDouble(textbox_n.Text))*1000_000;   // todo: сделать проверку

            pi_calc.calc();

            textbox_result.Text = pi_calc.get_pi().ToString();
        }

        /// <summary> Запуск вычислений в отдельном, новом потоке. Не блокирует цикл обработки событий</summary>
        private async void btn_run_sep_thread_Click(object sender, RoutedEventArgs e){
            pi_calc.N = Convert.ToUInt64(Convert.ToDouble(textbox_n.Text)) * 1000_000;   // todo: сделать проверку

            // async позволяет приостановить выполнение метода, сохранить его состояние,
            // до тех пор пока операция await запущенная в параллельном потоке, не завершится
            btn_run_sep_thread.IsEnabled = false;
            var result = await Task.Run( () => pi_calc.calc() );
            // var вместо типа - сообщение компилятору самостоятельно вывести тип
            // await неблокирующее ожидание завершения операции 
            // () => pi_calc.calc() -- анонимная функция без параметров, тело функции приведено после =>

            textbox_result.Text = pi_calc.get_pi().ToString();
            btn_run_sep_thread.IsEnabled = true;
        }
    }
}

// todo: остановка задачи
// todo: замер времени выполнения
