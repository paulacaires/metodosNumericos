#ifndef TYPES_H
#define TYPES_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Ponteiro para f(x)
typedef double (*Funcao)(double);
typedef enum { false, true } boolean;

typedef struct resultado {
    long double raiz;
    int numIteracoes;   
    boolean seConvergiu;
} Resultado;

#endif