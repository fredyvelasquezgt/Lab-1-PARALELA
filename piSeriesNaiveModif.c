#include <stdio.h>

int main() {
    int n = 1000; // Ajustar N segun lo necesitemos
    double pi_approx = 0.0;
    double factor = 1.0;
    double sum = 0.0;

    for (int k = 0; k < n; k++) {
        sum += factor / (2 * k + 1);
        factor = (k % 2 == 0) ? 1.0 : -1.0;

    }

    pi_approx = 4.0 * sum;

    printf("Aprox de PI: %lf\n", pi_approx);

    return 0;
}

