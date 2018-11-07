/* Cache
 * benchmark de cache associativa por conjunto
 * @autor: José Adalberto F. Gualeve
 * (c) 2018-11-05
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX 10000000
#define CHECK 10
#define DIMVET 64 * 1024


double segundo_atual(void);

int main()
{
    double now, diferenca=0;
    int k;
    int vetor[16][DIMVET];
    FILE *fd;

    for(int i=0; i<DIMVET; i++) {
        for (int j=0; j<16; j++) {
            vetor[j][i]=rand();
        }
    }
    sleep(1);
    if ((fd=fopen("saida.dat", "w")) == NULL) {
        printf("Erro de abertura de arquivo!");
        return 0;
    }
    for (int loop=2; loop<16; loop++) {
        now = segundo_atual();
        k = 0;
        while (k < MAX) {
            for(int i=0; i<16; i++) {
                switch (loop) {
                case 2:
                    vetor[0][i] = vetor[1][i] + vetor[2][i];
                    break;
                case 3:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i];
                    break;
                case 4:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] ;
                    break;
                case 5:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i];
                    break;
                case 6:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i];
                    break;
                case 7:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i];
                    break;
                case 8:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i];
                    break;
                case 9:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i];
                    break;
                case 10:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i] + vetor[10][i];
                    break;
                case 11:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i] + vetor[10][i] + vetor[11][i];
                    break;
                case 12:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] ;
                    break;
                case 13:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] +
                            vetor[13][i];
                    break;
                case 14:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] +
                            vetor[13][i] + vetor[14][i];
                    break;
                case 15:
                    vetor[0][i] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
                            vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
                            vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] +
                            vetor[13][i] + vetor[14][i] + vetor[15][i];
                }
            }
            k++;
        }
        now = segundo_atual() - now;
        diferenca = now - diferenca;
        if (loop == 2)
            diferenca = 0;
        fprintf(fd, "%d %.6f\n", loop, now);
        printf("%d parcelas: tempo = %fs (%fs - %f%%)\n", loop, now, diferenca, (now/(now-diferenca)-1)*100);
        diferenca = now;
    }
    printf("\npara plotar o gráfico, verifique se gnuplot está instalado e execute:\n\n");
    printf("$ gnuplot -p -e \"plot 'saida.dat' using 1:2\"\n");
    printf("\nou carregue o arquivo 'saida.dat' em uma planilha e gere o gráfico manualmente.");
    return 0;
}


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
