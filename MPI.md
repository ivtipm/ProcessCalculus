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

- Существуют реализации для языков Фортран 77/90, Java, C, C++

- Первая версия MPI разрабатывалась в 1993—1994 году, и MPI 1 вышла в 1994.

- Версия MPI 3.1 вышла в 2015 году.

- MPI 4.0 должен появится в 2021 году.

- существует большое число реализаций, как бесплатных (MPICH, OpenMP) так и коммерческих (Intel MPI)

- MPICH разрабатывается в Аргоннской национальной лаборатории США, с участием компаний IBM, Cray, SiCortex, Microsoft, Intel, ...

- можно запускать в локальной сети или даже на локальном компьютере.

- https://www.mpi-forum.org/
  - новые версии MPICH доступны только для Linux.

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


Запуск MPI программ на локальной машине\
`mpiexec -np 5 ./main`\
`-np 5` -- указание числа процессов (5)


После имени программы можно указать её параметры
`mpiexec -np 5 ./main 99999999`

Возможен одновременный запуск нескольких различныйх программ
`mpiexec -np 4 ./app1 : -np 4 ./app2`

Вывод программны
```
Hello world from processor s-pc, rank 1 out of 5 processors
Hello world from processor s-pc, rank 3 out of 5 processors
Hello world from processor s-pc, rank 0 out of 5 processors
Hello world from processor s-pc, rank 4 out of 5 processors
Hello world from processor s-pc, rank 2 out of 5 processors
```

После указания имени исполняемого файла для mpiexec можно передать параметры коммандной строки MPI программе.

см. также [mpiexec vs mpirun](https://stackoverflow.com/questions/25287981/mpiexec-vs-mpirun)

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
MPI datatype          C datatype      C++ datatype
MPI::INT              signed int      signed int
MPI::UNSIGNED_LONG    unsigned long   unsigned long int
MPI::DOUBLE           double          double
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

Если буфер приёма не способен вместить сообщение, то программа аварийно завершится.

Отправляемое сообщение может быть меньше буфера приёма.

Сообщения отправляются и принимаются через сетевое соединение.

**Пример 1**
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

**Пример 2**\
Какое число будет выведено на экран?
```C++
#include <iostream>
#include "mpi.h"
int main (int argc, char **argv)
{
 int rank;
 MPI_Status status;
 MPI_Init( &argc, &argv );
 MPI_Comm_rank( MPI_COMM_WORLD, &rank );

 int a[5];
 a[0] = 10;
 a[1] = rank;
 if (rank == 1)  
    MPI_Send (&a[1], 1, MPI_INT, 0, 99, MPI_COMM_WORLD);
  else   {
    MPI_Recv(&a[0], 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &status);
    std::cout << a[0];
 }
 MPI_Finalize();
}
```

### Измерение времени
`double MPI_Wtime()` -- возвращает время в секундах, прошедшее с некоторого момента в прошлом.


### Запуск на нескольких узлах в сети
Подготовка кластера: https://mpitutorial.com/tutorials/running-an-mpi-cluster-within-a-lan/#step-4-setting-up-nfs
- один из компьютеров кластера должен быть главным -- на нём запускается программа (и заодно MPI сервер)
```
mpiexec -np <number of processes> -hosts ip_host1, ip_host2 ./your_program
```

- запускаемая программа должна находится по одинаковому пути на всех узлах кластера (поэтому рекомендуется настроить NFS, создавать одинаковых пользователей). Иначе ошибка `unable to change wdir to ...`

- главный узел управляет подчинёнными по ssh (но допускаются и другие способы), поэтому нужно:  
  - установить ssh сервер на всех подчинённых узлах: `sudo apt install openssh`,
  - организовать доступ к ним по ключу (а не паролю)
  ```bash
  # создать пару криптографических ключей для подключения к узлам
  ssh-keygen
  # скопировать открытый (.pub) ключ на все подчинённые узлы
  ssh-copy-id -i файл-ключа.pub username@remote-node-ip
  # протестировать ssh подключение
  ssh username@remote-node-ip
  ```

<!-- - *подчинённые узлы должны уметь найти главный узел по его имени (имени компьютера), поэтому нужно записать IP главного узла и его имя в hosts файл каждого подчинённого узла. Иначе ошибка: `unable to get host address for computer-name`. -->

- на всех узлах кластера должна быть установлена одна и та же версия MPICH. Проверить версию: `mpichversion`


Ручное указание IP адресов кластера можно заменить на текстовый файл, содержащий перечень этих адресов (https://wiki.mpich.org/mpich/index.php/Using_the_Hydra_Process_Manager#Quick_Start):

`mpiexec -n 7  -f cluster-nodes.list ./main 5000000000`

Файл со списком узлов cluster-nodes.list:
```
ip_host1
ip_host2
```

Дополнительно в файле можно указать количество процессов, которое запустится на каждом узле
```
ip_host1:3  # число процессов указывается после :
ip_host2:4
```

**Запуск кластера на узлах вне одной локальной сети**

1. Организовать VPN (https://averagelinuxuser.com/linux-vpn-server/)
  1. Установить OpenVPN на один из узлов\
    - установка в Ubuntu\
    `sudo apt install openvpn curl`
    - скачать скрипт для быстрой установки и настройки VPN сервера
    ```bash
    curl -O https://raw.githubusercontent.com/Angristan/openvpn-install/master/openvpn-install.sh
    chmod +x openvpn-install.sh
    ```
    - запустить скрипт установки и настройки: `sudo ./openvpn-install.sh`. Почти все настройки (будет запущен текстовый мастер установки) можно оставить неизменными.
    - в процессе установки указать (client name) имя конфигурационного файла. Этот файл с расширением .ovpn будет использоваться для подключения клиентов к VPN серверу.
    - скопировать .ovpn файл на остальные узлы кластера

  1. Подключить клиентские VPN приложения к этому серверу
  - подключить каждый узел кластера к VPN:\
  `sudo openvpn my-config-client.ovpn`

1. Запустить распределённые вычисления, указав в параметре `-hosts` IP адреса узлов виртуальной сети (VPN)


## Дополнительные материалы:
https://anl.app.box.com/v/2019-06-21-basic-mpi


# ***
```bash
sudo apt update
sudo apt upgrade
sudo apt install mpich openssh-server zsh nano

```


# Ссылки
  - https://mpitutorial.com/tutorials/
  - https://wiki.mpich.org/mpich/index.php/Category:Design_Documents
