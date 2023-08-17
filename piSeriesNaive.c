#include <stdio.h>
#include <omp.h>

int main() {
    int n = 1000; // Ajustar N segun lo necesitemos
    int thread_count = 4; // Ajustar la cantidad de hilos segun necesitemos
    double pi_approx = 0.0;
    double factor = 1.0;
    double sum = 0.0;

    #pragma omp parallel for num_threads(thread_count) reduction(+:sum)
    for (int k = 0; k < n; k++) {
        sum += factor / (2 * k + 1);
        factor = -factor;
    }

    pi_approx = 4.0 * sum;

    printf("Aprox de PI en version PARALELA: %lf\n", pi_approx);

    return 0;
}
