/**
 * Definições das funções matemáticas
 */

#ifndef FUNCOES
#define FUNCOES

double f(double x, double y) {
    return x*x - y*y*y - 2.0;
}

double fx(double x, double y) {
    return 2.0*x;
}

double fy(double x, double y) {
    return -3.0*y*y;
}

#endif
