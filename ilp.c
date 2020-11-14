/* ILP - Paralelismo em Nível de Instrução
 * benchmark de loop unrolling
 * @autor: José Adalberto F. Gualeve
 * (c) 2019-11-12
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "comuns.h"

#define MAX 10000 // 100000000
#define CHECK 10
#define DIMVET 3
#define LINHAS 64 * 1024

int ilp()
{
  FILE *fd;
  double now, diferenca=0;
  int k;
  int vetor[LINHAS][DIMVET];
  printf("Preparando o teste...\n");
  for(int i=0; i<LINHAS; i++) {
    for (int j=0; j<DIMVET; j++) {
      vetor[i][j]=rand();
    }
  }
  sleep(1);
  if ((fd=fopen("ilp.dat", "w")) == NULL) {
      printf("Erro de abertura de arquivo!");
      return 0;
  }
  printf("início...\n");
  for (int loop=0; loop<16; loop++) {
    now = segundo_atual();
    k = 0;
    for (k=0; k < MAX; k++) {
        //for (int i=0; i<LINHAS; i+=2) {
        for (int i=0; i<LINHAS; i++) {
          vetor[0][i] = vetor[1][i] + vetor[2][i];
          //vetor[0][i+1] = vetor[1][i+1] + vetor[2][i+1];
         }
    }
    now = segundo_atual() - now;
    diferenca = now - diferenca;
    fprintf(fd, "%d %.6f\n", loop, now);
    printf("Tempo do loop = %fs para %d cálculos matriciais\n", now, MAX*LINHAS);
    diferenca = now;
  }
  for (int loop=16; loop<32; loop++) {
    now = segundo_atual();
    k = 0;
    for (k=0; k < MAX; k++) {
        for (int i=0; i<LINHAS; i+=2) {
        //for (int i=0; i<LINHAS; i++) {
          vetor[0][i] = vetor[1][i] + vetor[2][i];
          vetor[0][i+1] = vetor[1][i+1] + vetor[2][i+1];
         }
    }
    now = segundo_atual() - now;
    diferenca = now - diferenca;
    fprintf(fd, "%d %.6f\n", loop, now);
    printf("Tempo do loop = %fs para %d cálculos matriciais\n", now, MAX*LINHAS);
    diferenca = now;
  }
  fclose(fd);
  printf("\npara plotar o gráfico, verifique se gnuplot está instalado e execute:\n\n");
  printf("$ gnuplot -p -e \"set yrange [0.0:2.0]; plot 'ilp.dat' using 1:2 w lp ls 7\"\n");
  printf("Caso o gráfico não esteja apresentando corretamente, ajuste a faixa do eixo Y no comando acima\n");
  printf("\nou carregue o arquivo 'saida.dat' em uma planilha e gere o gráfico manualmente.");


  return 0;
}
