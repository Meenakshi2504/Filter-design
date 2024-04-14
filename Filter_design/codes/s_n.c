#include <stdio.h>
#include <math.h>
#include <complex.h>

#define N 4
#define EPSILON 0.3
#define OMEGA_LP 1
#define PI 3.14159265358979323846

int main() {
    // Calculate B_k coefficient
    double B_k = asinh(1.0 / EPSILON) / N;

    // Initialize an array to store the poles
    double complex poles[2*N+1];

    // Calculate poles
    for (int i = 1; i <= 2*N; ++i) {
        double A_k = ((2 * i) + 1) * PI / (2 * N);
        double real_part = -OMEGA_LP * sin(A_k) * sinh(B_k);
        double imag_part = OMEGA_LP * cos(A_k) * cosh(B_k);
        poles[i] = real_part + imag_part * I;
    }

    // Save poles to a .dat file
    FILE *file = fopen("2.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(file, "Real Part, Imaginary Part\n");
    for (int i = 1; i <= 2*N; ++i) {
        fprintf(file, "%.4f, %.4f\n", creal(poles[i]), cimag(poles[i]));
    }
    fclose(file);

    printf("Poles saved to 2.txt file.\n");

    return 0;
}

