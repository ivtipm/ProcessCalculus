#include <mpi/mpi.h>

using namespace std;

int main()
{   
    
    // Initialize enviroment
    MPI_Init(nullptr, nullptr);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank (number) of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of td MPIhe processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    
    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
               processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
    
}


// Дополнительные библиотеки указывать вручную не нужно
// Для компиляции использовать отдельный компилятор, например из реализации MPICH

// Установка MPICH в Debian:
// sudo apt install mpich
// может потребоваться перезапуск ОС?

// Проверка:
// mpic++ -v         # информация о версии

// Компиляция:
// mpic++ main.cpp -o main
// -o main — имя выходного (исполняемого) файла

// Запуск:
// mpirun -n 10 ./main


// подробности о MPI см в файле MPI.md