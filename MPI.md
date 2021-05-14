# MPI
Системы с общей памятью трудно масштабировать: например чтобы увеличить количество || выполняющихся потоков нужно увеличить число ядер процессора или число процессоров. Такой способ масштабирования по техническим причинам сильно ограничен.

Системы с распределённой памятью масштабировать проще, нужно только добавить новое устройство в сеть. 

## Системы с распределённой памятью
- Массивно-параллельные системы (MPP)\
  состоит из однородных вычислительных узлов: процессор + локальная память + сетевой адаптер.

- кластер\
  Набор рабочих станций (или даже ПК) общего назначения, используется в качестве дешевого варианта массивно-параллельного компьютера. Для связи узлов используется одна из стандартных сетевых технологий (Fast/Gigabit Ethernet, Myrinet) на базе шинной архитектуры или коммутатора
- ...

## MPI


Message Passing Interface (MPI, интерфейс передачи сообщений) — программный интерфейс (API) для передачи информации, который позволяет обмениваться сообщениями между процессами, выполняющими одну задачу.

- Используется в || алгоритмах с распределённой памятью.

- Основным средством коммуникации между процессами в MPI является передача сообщений друг другу.

- Существуют реализации для языков Фортран 77/90, Java, Си и C++

- Первая версия MPI разрабатывалась в 1993—1994 году, и MPI 1 вышла в 1994.

- Версия MPI 3.1 вышла в 2015 году.

- MPI 4.0 должен появится в 2021 году.

- существует большое число реализаций, как бесплатных (MPICH) так и коммерческих (Intel MPI)

- MPICH разрабатывается в Аргоннской национальной лаборатории США, с участием компаний IBM, Cray, SiCortex, Microsoft, Intel, ...

- можно запускать в локальной сети или даже на локальном компьютере

- https://www.mpi-forum.org/

### Скачать
https://www.mpich.org/downloads/

Установка в Ubuntu:
`apt install mpich`

### API

- Коды ошибок https://www.mpi-forum.org/docs/mpi-2.2/mpi22-report/node192.htm#Table6

Любая     программа должна в начале содержать вызов `MPI_Init(int* argc,     char*** argv)` -- инициализация. Все последующие функции MPI могут быть вызваны только после MPI_Init.

После инициализации MPI все активные процессы объединяются в общую группу с единым коммуникатором MPI_COMM_WORLD (коммуникатор создаваемый по умолчанию).
Под коммуникатором в MPI принято понимать специально создаваемый служебный объект,
который объединяет в своем составе группу процессоров и ряд дополнительных
параметров, которые необходимы для организации обменов внутри этой группы.

`int MPI_Comm_size( MPI_Comm comm, int *size )` -- определяет общее количество процессов в группе.
`comm` -- коммуникатор (например MPI_COMM_WORLD).
`size` -- после вызова будет содержать количество процессов.

`int MPI_Comm_rank(MPI_Comm comm, int *rank)` --  Determines the rank of the calling process in the communicator.
`rank` -- после вызова будет содержать номер процесса, вызвавшую данную функцию. Нумерация начинается с 0.

`int MPI_Finalize(void)` -- должна быть в конце каждой MPI программы. После неё нельзя вызывать MPI функции.


### Hello, World!
```C++
#include <mpi/mpi.h>

using namespace std;

int main()
{
    MPI_Init(nullptr, nullptr);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
               processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
}
```

### Компиляция и запуск
Далее будет рассмотрена реализация MPICH.

mpicc\mpic++ -- обёртки над компиляторами C и C++.

Показать подробности\
`mpi++ -compile_info`

Коспиляция программы\
`mpic++ main.cpp -o main`\
`-o main` -- указание имени выходного файла


Запуск MPI программы\
`mpirun -np 5 ./main`\
`-np 5` -- указание числа процессов (5)


Вывод программны
```
Hello world from processor s-pc, rank 1 out of 5 processors
Hello world from processor s-pc, rank 3 out of 5 processors
Hello world from processor s-pc, rank 0 out of 5 processors
Hello world from processor s-pc, rank 4 out of 5 processors
Hello world from processor s-pc, rank 2 out of 5 processors
```

### Передача сообщений

Сообщение - некоторые данные.

Сообщения передаются через специальные буферы: буфер обмена, приёма, передачи.

**Буфер**:
- адрес начала буфера
- число передаваемых элементов
- тип пересылаемых элементов


Типы данных в MPI:
https://www.mcs.anl.gov/research/projects/mpi/mpi-standard/mpi-report-2.0/node229.htm
```
MPI datatype    C datatype    C++ datatype
MPI::INT        signed int    signed int
MPI::DOUBLE     double        double
...
```

```C++
MPI_Send(
    void* data,
    int count,
    MPI_Datatype datatype,
    int destination,
    int tag,
    MPI_Comm communicator)
```


- `buf`
    initial address of send buffer (choice)
- `count`
    number of elements in send buffer (nonnegative integer)
- `datatype`
    datatype of each send buffer element (handle)
- `dest`
    rank of destination (integer)
- `tag`
    message tag (integer)
- `comm`
    communicator (handle)

```C++
MPI_Recv(
    void* data,
    int count,
    MPI_Datatype datatype,
    int source,
    int tag,
    MPI_Comm communicator,
    MPI_Status* status)
```



- `count`
    maximum number of elements in receive buffer (integer)
- `datatype`
    datatype of each receive buffer element (handle)
- `source`
    rank of source (integer); MPI_ANY_SOURCE -- принимать от всех.
- `tag`
    message tag (integer); MPI_ANY_TAG -- принимать сообщения с любым идентификатором.
- `comm`
    communicator (handle)

Вызов функций -- блокирующий. Принимать сообщения можно от любого процесса, но отправлять только на конкретный.

**Пример**
```C++
// Find out rank, size
int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);

int number;
if (world_rank == 0) {
    number = -1;
    MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
} else if (world_rank == 1) {
    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("Process 1 received number %d from process 0\n",
           number);
}
```

### Измерение времени
`double MPI_Wtime()` -- возвращает время в секундах, прошедшее с некоторого момента в прошлом.
