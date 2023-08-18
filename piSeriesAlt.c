#include <stdio.h>
#include <omp.h>

#define PI 3.14159265358979323846

double calculate_pi(long long n);

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Uso: %s <threads> <n>\n", argv[0]);
        return 1;
    }

    int threads = atoi(argv[1]);
    long long n = atoll(argv[2]);

    omp_set_num_threads(threads);

    double start_time = omp_get_wtime();
    double pi = calculate_pi(n);
    double end_time = omp_get_wtime();

    printf("PI estimado: %.20f\n", pi);
    printf("Error: %.20f\n", PI - pi);
    printf("Tiempo: %f segundos\n", end_time - start_time);

    return 0;
}

double calculate_pi(long long n)
{
    double sum_even = 0.0;
    double sum_odd = 0.0;
    long long i;

#pragma omp parallel for reduction(+ : sum_even) private(i)
    for (i = 0; i <= n; i += 2)
    {
        sum_even += 1.0 / (2.0 * i + 1);
    }

#pragma omp parallel for reduction(+ : sum_odd) private(i)
    for (i = 1; i <= n; i += 2)
    {
        sum_odd += 1.0 / (2.0 * i + 1);
    }

    return 4.0 * (sum_even - sum_odd);
}
