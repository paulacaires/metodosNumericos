#include <stdio.h>
#include <math.h>
#include "../include/metodoBisseccao.h"

// f(x) = x^3 - x - 2
double f(double x) {
    return (x * x * x) - 9 * x + 3;
}

int main() {
    double a = 0;
    double b = 1;
    double precisao = 0.001;

    // Chamando a função implementada
    Resultado resultado = metodo_bisseccao(f, a, b, precisao);
    printf("O valor de f(2) é: %lf\n", resultado); // Imprime o resultado

    return 0;
}