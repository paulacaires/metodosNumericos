#ifndef METODO_BISSECCAO_H
#define METODO_BISSECCAO_H

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
Resultado metodo_bisseccao(Funcao f, double a, double b, double precisao);

#endif