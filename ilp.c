/* ILP - Paralelismo em Nível de Instruction
 * benchmark de loop unrolling
 * @autor: José Adalberto F. Gualeve
 * (c) 2019-11-12
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "comuns.h"

#define MAX 100000000
#define CHECK 10
#define DIMVET 64 * 1024
#define LINHAS 3

int ilp()
{
  double now, diferenca=0;
  int k;
  int vetor[LINHAS][DIMVET];
  printf("Preparando o teste...\n");
  for(int i=0; i<LINHAS; i++) {
    for (int j=0; j<DIMVET; j++) {
      vetor[i][j]=rand();
    }
  }
  //sleep(1);
  printf("início...\n");
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
  printf("Tempo do loop = %fs para %d cálculos matriciais\n", diferenca, MAX*LINHAS);
  diferenca = now;
  return 0;
}
