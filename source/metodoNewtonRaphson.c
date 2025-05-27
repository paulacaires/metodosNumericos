#include "../include/metodoNewtonRaphson.h"

Resultado metodo_newton_raphson(Funcao f, Funcao f_derivada, double x0, double precisao1, double precisao2) {
    int MAX_ITER = 1000;
    Resultado resultado;
    double f0 = f(x0);

    if (fabs(f0) < precisao1) {
        resultado.numIteracoes = 0;
        resultado.raiz = x0;
        resultado.seConvergiu = true;
        return resultado;
    }

    int k = 1;

    for (k; k < MAX_ITER; k++) {
      double f0 = f(x0);
      double df0 = f_derivada(x0);
      double x1 = x0 - (f0 / df0);
      double f1 = f(x1);

      if (fabs(f1) < precisao1 || fabs(x1 - x0) < precisao2) {
        resultado.numIteracoes = k;
        resultado.raiz = x1;
        resultado.seConvergiu = true;
        return resultado;
      }

      x0 = x1;
    }

    printf("33333");
    resultado.seConvergiu = false;
    resultado.raiz = NAN;
    return resultado;
}