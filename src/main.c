/**
 * Programa para estimar uma raiz de uma função de duas variáveis utilizando do 
 * método de Newton
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funcoes.h"

#define DELTA 0.0000001

int main(void) {
    double x, y; // pontos que estão sendo iterados, que irá terminar em uma raiz
    double a, b; // auxiliares responsáveis pela mudança de base na solução do sist. linear
    double f_ret, fx_ret, fy_ret; // variável com o valor das funções avaliadas no ponto

    // inicia o random
    srand(time(NULL));

    // atribuindo os pontos iniciais
    x = (double) (rand() % 20 - 10);
    y = (double) (rand() % 20 - 10);
    f_ret = f(x, y);    

    // loop enquanto não aproximou o suficiente da raiz
    do {
        // verifica se as derivadas não são ambas 0
        fx_ret = fx(x, y);
        fy_ret = fy(x, y);
        if (fy_ret == 0.0) {
            // imprime a mensagem de erro e sai do programa
            printf("O ponto escolhido chegou a derivadas nulas em x = %lf e y = %lf\n", x, y);
            return 1;
        }

        // escolhe aleatoriamente a primeira solução do sistema
        a = (double) (rand() % 20 - 10);
        // implementa na formula a segunda solução
        b = (-f_ret - (fx_ret * a)) / fy_ret;

        // retorna a base para as soluções em x e y
        x += a;
        y += b;

        // calcula novamente a f
        f_ret = f(x, y);
    } while ((f_ret >= 0.0 && f_ret > DELTA) || (f_ret < 0.0 && f_ret < -DELTA));


    // saída do programa
    printf("A raíz encontrada foi (x, y) = (%.20lf, %.20lf)\n", x, y);
    printf("f(x, y) = %.20lf\n", f(x, y));

    return 0;
}
