#ifndef METODO_NEWTON_RAPHSON_H
#define METODO_NEWTON_RAPHSON_H

#include "types.h"

/**
 * @brief Encontra a raiz de uma função usando o Método da Bissecção.
 *
 * @param f         Ponteiro para a função f(x) cuja raiz queremos encontrar.
 * @param a         Limite inferior do intervalo [a, b].
 * @param b         Limite superior do intervalo [a, b].
 * @param precisao  Precisão
 * @return          O valor da raiz encontrada ou NAN (Not a Number) em caso de erro.
 */
Resultado metodo_newton_raphson(Funcao f, Funcao f_derivada, double x0, double precisao1, double precisao2);

#endif