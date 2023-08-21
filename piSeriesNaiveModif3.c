#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000000; // Ajustar N segun lo necesitemos
    n = n *10;
    int thread_count = omp_get_max_threads();
    thread_count = thread_count;
    double pi_approx = 0.0;
    double sum = 0.0;

    double start_time = omp_get_wtime();

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

    double end_time = omp_get_wtime();
    double time = end_time - start_time;

    printf("Aprox de PI en version PARALELA con %d threads: %lf\n", thread_count, pi_approx);
    printf("Tiempo de ejecucion: %lf\n", time);

    // Realice el cálculo de speedup, eficiencia, escalabilidad fuerte y escalabilidad débil 

    return 0;
}

