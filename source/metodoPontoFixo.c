#include "../include/metodoBisseccao.h"

Resultado metodo_ponto_fixo(Funcao f, Funcao phi, long double x0, double precisao1, double precisao2) {
  int MAX_ITER = 1000;
  Resultado resultado;
  int k;

  if (fabs(f(x0)) < precisao1) {
    resultado.numIteracoes = 0;
    resultado.raiz = x0;
    resultado.seConvergiu = true;
    return resultado;
  }

  for (k = 1; k <= MAX_ITER; k++) {
    long double x1 = phi(x0);

    if (fabs(f(x1)) < precisao1 || fabs(x1 - x0) < precisao2) {
      resultado.numIteracoes = k;
      resultado.raiz = x1;
      resultado.seConvergiu = true;
      return resultado;
    }

    x0 = x1;
  }

  resultado.numIteracoes = MAX_ITER;
  resultado.raiz = x0;
  resultado.seConvergiu = false;
  return resultado;
}