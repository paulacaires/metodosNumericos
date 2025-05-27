#include "../include/metodoBisseccao.h"
#include "../include/metodoPontoFixo.h"
#include "../include/metodoNewtonRaphson.h"
#include "../include/metodoSecante.h"

// f(x) = x^3 - 9x + 3
double f(double x) {
    return (x * x * x) - 9 * x + 3;
}

// f'(x) = 3*x^2 - 9
double f_derivada(double x) {
    return 3 * (x * x) - 9;
}

// phi(x) = x^3 / 9 + 1 / 3
double phi(double x) {
    return (x * x * x) / 9 + 1 / 3;
}

// g(x) = 2*x^3 - 20*x - 13
double g(double x) {
    return 2 * (x * x * x) - 20 * x - 13;
}

// g'(x) = 6*x² - 20
double g_derivada(double x) {
    return 6 * (x * x) - 20;
}

// x³ / 10 - 13 / 20
double phi_g(double x) {
    return (x * x * x) / 10 - 13 / 20;
}

void imprimeResultado(Resultado resultado, char *nomeMetodo) {
    printf("\n========    %s    ========\n", nomeMetodo);
    printf("Raiz:            %llf\n", resultado.raiz);
    printf("N. de iterações: %d\n", resultado.numIteracoes);
    printf("Convergência:    %s\n", resultado.seConvergiu ? "Houve convergência" : "Não houve convergência");
}

int main() {
    printf("\n\n========    f(x) = x^3 - 9x + 3     ========\n\n");
    double a = 0;
    double b = 1;
    double precisao = 0.001;
    Resultado resultadoB = metodo_bisseccao(f, a, b, precisao);
    imprimeResultado(resultadoB, "Método da Bissecção");

    double x0 = 0.5;
    double precisao1 = 0.0001, precisao2 = 0.0001;
    Resultado resultadoNR = metodo_newton_raphson(f, f_derivada, x0, precisao1, precisao2);
    imprimeResultado(resultadoNR, "Método de Newton Raphson");

    double precisao3 = 0.0005;
    double precisao4 =  0.0005;
    Resultado resultadoPF = metodo_ponto_fixo(f, phi, x0, precisao3, precisao4);
    imprimeResultado(resultadoPF, "Método do Ponto Fixo");

    double x0_secante = 0;
    double x1_secante = 1;
    double precisao5 = 0.0005;
    double precisao6 = 0.0005;
    Resultado resultadoS = metodo_secante(f, x0_secante, x1_secante, precisao5, precisao6);
    imprimeResultado(resultadoS, "Método da Secante");

    printf("\n========    g(x) = 2 * x^3 - 20x - 13     ========\n");
    double aG = 3;
    double bG = 4;
    double precisaoG = 0.000001;
    Resultado resultadoBG = metodo_bisseccao(g, aG, bG, precisaoG);
    imprimeResultado(resultadoBG, "Método da Bissecção");

    Resultado resultadoNRG = metodo_newton_raphson(g, g_derivada, x0, precisaoG, precisaoG);
    imprimeResultado(resultadoNRG, "Método de Newton Raphson");

    Resultado resultadoPFG = metodo_ponto_fixo(g, phi_g, x0, precisaoG, precisaoG);
    imprimeResultado(resultadoPFG, "Método do Ponto Fixo");

    double x0_secanteG = 0;
    double x1_secanteG = 1;
    Resultado resultadoSG = metodo_secante(g, x0_secanteG, x1_secanteG, precisaoG, precisaoG);
    imprimeResultado(resultadoSG, "Método da Secante");
    return 0;
}