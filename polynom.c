#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 100
void read(int *n, int a[MAX_DEGREE]);
double calculate(int n, int *a, double x);
void derivate(int *n, int *a);
void write(int *n, int a[]);

void read(int *n, int a[MAX_DEGREE]) {
    printf("Grad des Polynoms: ");
    scanf("%d", n);
    printf("Gib die Koeffizienten ein:\n");
    for (int i = 0; i <= *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

double calculate(int n, int *a, double x) {
    double result = 0.0;
    for (int i = n; i >= 0; i--) {
        result = result * x + a[i];
    }
    return result;
}

void derivate(int *n, int *a) {
    if (*n == 0) {
        *n = 0;
        a[0] = 0;
    } else {
        for (int i = 0; i < *n; i++) {
            a[i] = (i + 1) * a[i + 1];
        }
        *n = *n - 1;
    }
}

void write(int *n, int a[]) {
    for (int i = *n; i >= 0; i--) {
        printf("%d", a[i]);
        if (i > 0) {
            printf("*x^%d + ", i);
        } else {
            printf("\n");
        }
    }
}

int main(void) {
    int n, p[MAX_DEGREE];
    float x;
    read(&n, p);
    printf("Zahl fuer die Berechnung der Ableitung: ");
    scanf("%f", &x);
    printf("\nAUSGABE\n");
    derivate(&n, p);
    printf("P'(x) = ");
    write(&n, p);
    printf("Funktionswert des abgeleiteten Polynoms:\n");
    printf("P'(%0.3f) = %0.3f\n", x, calculate(n, p, x));
    return 0;
}
