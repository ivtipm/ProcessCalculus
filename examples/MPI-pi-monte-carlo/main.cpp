#include <iostream>
#include <random>
#include <chrono>
#include <math.h>
#include <mpich/mpi.h>

using namespace std;

// случайно бросает точки на квадрат 1x1, возвращает число попаданий во вписанный круг
ulong circle_square(ulong n){
    std::mt19937_64 rng;
    // initialize the random number generator with time-dependent seed
    uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    // initialize a uniform distribution between 0 and 1
    std::uniform_real_distribution<double> unif(0, 1);

    ulong m = 0;
    double x, y;
    for (ulong i=0; i<n; i++) {
        x = unif(rng);
        y = unif(rng);

        if ( pow(x-0.5,2) + pow(y-0.5,2) < 0.25) m++;
    }
    return m;
}

int main()
{   cout.precision(8);
    ulong N = 1000*1000*100;    // число случайных точек. для вычисления Pi

    MPI_Init(nullptr, nullptr);

    int proc_count;
    MPI_Comm_size(MPI_COMM_WORLD, &proc_count);
    int my_id;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_id);

    double pi;

    if (my_id == 0) {

        ulong M=0;
        double t0 = MPI_Wtime();
        cout << "Waiting for other process" << endl;
        for (unsigned i =0; i<proc_count-1; i++){
            ulong m;
            MPI_Recv(&m, 1, MPI_UNSIGNED_LONG,
                 MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD,
                 MPI_STATUS_IGNORE);
            M += m;}

        pi = 4.*M/N/(proc_count-1);

        cout << "overall Pi    = " << pi << endl;
        cout << "overall error = " << fabs(pi-M_PI) << endl;
        cout << "overall time  = " << MPI_Wtime()-t0 << " s" << endl;

    } else {
        double t0 = MPI_Wtime();
        ulong m = circle_square(N);
        cout << "#" << my_id << " Done: pi=" << 4.*m/N << ";  error " << fabs(4.*m/N-M_PI) << "; time: " << MPI_Wtime()-t0 << " s" << endl;
        MPI_Send(&m, 1, MPI_UNSIGNED_LONG, 0, 0, MPI_COMM_WORLD);
    }


    MPI_Finalize();

    return 0;
}


// apt get install mpich

// Запуск программы:
// mpirun -np 10 ./MPI-pi-monte-carlo
// -np 10 -- 10 процессов
// ./MPI-pi-monte-carlo имя испольняемого файла (включая имя текующего каталога . )

