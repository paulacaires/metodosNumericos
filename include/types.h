#ifndef TYPES_H
#define TYPES_H

// Ponteiro para f(x)
typedef double (*Funcao)(double);
typedef enum { true, false } boolean;

typedef struct resultado {
    double raiz;
    int numIteracoes;   
    boolean seConvergiu;
} Resultado;

#endif