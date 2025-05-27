#include "../include/metodoSecante.h"

Resultado metodo_secante(Funcao f, double x0, double x1, double precisao1, double precisao2) {
  int MAX_ITER = 10000;  
  Resultado resultado;

    double fx0 = f(x0);
    double fx1 = f(x1);

    if (fabs(fx0) < precisao1) {
        resultado.numIteracoes = 1;
        resultado.raiz = x0;
        resultado.seConvergiu = true;
        return resultado;
    }

    if (fabs(fx1) < precisao1 || fabs(x1 - x0) < precisao2) {
        resultado.numIteracoes = 1;
        resultado.raiz = x1;
        resultado.seConvergiu = true;
        return resultado;
    }

    int k = 1;

    for (k; k <= MAX_ITER; k++) {
        double fx0 = f(x0);
        double fx1 = f(x1);
        double denominador = fx1 - fx0;

        double x2 = x1 - (fx1 * (x1 - x0)) / denominador;
        double fx2 = f(x2);

        if (fabs(fx2) < precisao1 || fabs(x2 - x1) < precisao2) {
            resultado.numIteracoes = k;
            resultado.raiz = x2;
            resultado.seConvergiu = true;
            return resultado;
        }

        x0 = x1;
        x1 = x2;
    }

    resultado.numIteracoes = 10000;
    resultado.raiz = NAN;
    resultado.seConvergiu = false;
    return resultado;
}