#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// Функция выделения памяти под 2-ный массив
double** malloc_array(long int n)
{
	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}

// Функция освобождения памяти 
void free_array(double** matrix,long int n)
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

// Функция инициализации матрицы случайными числами из [0,1]
void rand_init_matrix(double** matrix,long int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand() / RAND_MAX;
}

// Функция обнуления матрицы
void zero_init_matrix(double** matrix, long int n)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0.0 ;
}

int main()
{
	const long int N = 1000;
	double** A, **B, **C;

// Выделение памяти под матрицы A,B,C
	A = malloc_array(N);
	B = malloc_array(N);
	C = malloc_array(N);

// Инициализация матриц
	rand_init_matrix(A, N);
	rand_init_matrix(B, N);
	zero_init_matrix(C, N);
	clock_t t;

// 1
// Перемножение матриц с порядком циклов jki
	t = clock();
	for (int j = 0; j < N; j++)
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				C[i][j] += A[i][k] * B[k][j];
	t = clock() - t;
	cout << "Time jki loops is " << t / CLOCKS_PER_SEC << " seconds" <<  endl;
// 2
// Перемножение матриц с порядком циклов ikj
	zero_init_matrix(C, N);
	t = clock();
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			for (int j = 0; j < N; j++)
				C[i][j] += A[i][k] * B[k][j];
	t = clock() - t;
	cout << "Time ikj loops is " << t / CLOCKS_PER_SEC << " seconds" << endl;
	
// Какой из вариантов перемножения матриц работает быстрее?
// Почему?


// Освобождение памяти занимаемой матрицами A,B,C
	free_array(A, N);
	free_array(B, N);
	free_array(C, N);

	return 0;
}



// См. время выполнения различных операций, включая доступ к разным видам памяти (регистры, кэш, RAM): https://docs.google.com/presentation/d/1ofbDxk9cbT4ABdCmGFqftz3u166DV1KkrJGU_Z7E6Kg/edit#slide=id.g2bac33147ba_0_6