#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000000; // Ajustar N segun lo necesitemos
    int thread_count = 4; // Ajustar la cantidad de hilos segun necesitemos
    double pi_approx = 0.0;
    double sum = 0.0;

    #pragma omp parallel num_threads(thread_count) private(sum)
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        int chunk_size = n / num_threads;
        int start = thread_id * chunk_size;
        int end = start + chunk_size;

        for (int k = start; k < end; k++) {
            double factor = (k % 2 == 0) ? 1.0 : -1.0;
            sum += factor / (2 * k + 1);
        }

        #pragma omp critical
        pi_approx += sum;
    }

    pi_approx = 4.0 * pi_approx;

    printf("Aprox de PI en version PARALELA: %lf\n", pi_approx);

    return 0;
}

