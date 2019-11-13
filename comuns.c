#include "comuns.h"

/* retorna o segundo atual desde 1/1/1970,
 * com precisão de nanosegundos
*/
double segundo_atual(void)
{
    double now;
    struct timespec timenow;
    clock_gettime(CLOCK_REALTIME, &timenow);
    now = ((double)((timenow.tv_sec * 1000000000) + (timenow.tv_nsec))) / 1000000000;
    return now;
}


int menu(int nopcoes, char *opcoes[])
{
    int i;
    int op;
    printf("\n              == MENU ==\n");
    for (i = 0; i < nopcoes; ++i) {
        printf("%s\n", opcoes[i]);
    }
    printf("0: Sair\n\n=> ");
    scanf("%d", &op);
    return op;
}
