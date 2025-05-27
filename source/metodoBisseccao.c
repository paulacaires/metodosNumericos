#include "../include/metodoBisseccao.h"
#include <math.h>
#include <stdio.h>

Resultado metodo_bisseccao(Funcao f, double a, double b, double precisao) {
    int MAX_ITER = 1000;
    double fa = f(a);
    double fb = f(b);

    Resultado resultado;

    if (fa * fb >= 0) {
        resultado.numIteracoes = 0;
        resultado.raiz = NAN;
        resultado.seConvergiu = false;
        return resultado;
    }

    if ((b - a) < precisao) {
        resultado.numIteracoes = 0;
        resultado.raiz = (a + b) / 2; // Qualquer x pertencente à [a, b]
        resultado.seConvergiu = true;
        return resultado;
    }

    double k = 1;
    double M = fa;

    resultado.numIteracoes = 0;

    for (k; k < MAX_ITER; k++) {
        resultado.numIteracoes += 1;

        // Pseudocódigo Passo 5: x = (a + b) / 2
        double x = (a + b) / 2;
        double fx = f(x);

        // Checagens iniciais
        if ((b - a) < precisao) {
            resultado.raiz = (a + b) / 2;
            resultado.seConvergiu = true;
            return resultado;
        }

        // Pseudocódigo Passo 6: Se Mf(x) > 0, faça a = x.
        if (M * fx > 0) {
            a = x;            
        }
        // Pseudocódigo Passo 7: b = x
        else {
            b = x;
        }
    }

    resultado.seConvergiu = false;
    resultado.raiz = NAN;
    return resultado;
}