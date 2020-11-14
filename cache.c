/* Cache
 * benchmark de cache associativa por conjunto
 * @autor: José Adalberto F. Gualeve
 * (c) 2018-11-05
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "comuns.h"

#define MAX 10000000
#define CHECK 10
#define TAM_LINHA_L2 64 /* tamanho da linha de L2 (em Bytes) */
/* cache L2 de 256KB 4-way */
#define QTD_CONJUNTOS_L2 ((256 * 1024) / TAM_LINHA_L2) / 4
#define DIMVET TAM_LINHA_L2 * QTD_CONJUNTOS_L2
#define QTD_VETORES 16


int cache()
{
  double now, diferenca=0;
  int k;
  int vetor[QTD_VETORES][DIMVET];
  int inteirosPorLinha = TAM_LINHA_L2 / sizeof(int);
  FILE *fd;

  for(int i=0; i<DIMVET; i++) {
    for (int j=0; j<QTD_VETORES; j++) {
      vetor[j][i]=rand();
    }
  }
  sleep(1);
  if ((fd=fopen("saida.dat", "w")) == NULL) {
    printf("Erro de abertura de arquivo!");
    return 0;
  }

  /* serao somadas 2, 3, 4, ..., 15 parcelas de diferentes vetores de cada vez */
  for (int loop=2; loop<QTD_VETORES; loop++) {
    now = segundo_atual();
    /* cada soma sera repetida MAX vezes */
    for (k=0; k < MAX; k++) {
      /* soma os primeiros blocos de inteiros de cada vetor */
      for(int i=0; i < inteirosPorLinha; i++) {
	switch (loop) {
	case 2:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i];
	  break;
	case 3:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i];
	  break;
	case 4:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] ;
	  break;
	case 5:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i];
	  break;
	case 6:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i];
	  break;
	case 7:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i];
	  break;
	case 8:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i];
	  break;
	case 9:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i];
	  break;
	case 10:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i] + vetor[10][i];
	  break;
	case 11:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i] + vetor[10][i] + vetor[11][i];
	  break;
	case 12:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] ;
	  break;
	case 13:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] +
	    vetor[13][i];
	  break;
	case 14:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] +
	    vetor[13][i] + vetor[14][i];
	  break;
	case 15:
	  vetor[0][i+inteirosPorLinha] = vetor[1][i] + vetor[2][i] + vetor[3][i] + vetor[4][i] +
	    vetor[5][i] + vetor[6][i] + vetor[7][i] + vetor[8][i] +
	    vetor[9][i] + vetor[10][i] + vetor[11][i] + vetor[12][i] +
	    vetor[13][i] + vetor[14][i] + vetor[15][i];
	}
      }
    }
    now = segundo_atual() - now;
    diferenca = now - diferenca;
    if (loop == 2)
      diferenca = 0;
    fprintf(fd, "%d %.6f\n", loop, now);
    printf("%d parcelas: tempo = %fs (%fs - %f%%)\n", loop, now, diferenca, (now/(now-diferenca)-1)*100);
    diferenca = now;
  }
  fclose(fd);
  printf("\npara plotar o gráfico, verifique se gnuplot está instalado e execute:\n\n");
  printf("$ gnuplot -p -e \"plot 'saida.dat' using 1:2 w lp ls 7\"\n");
  printf("\nou carregue o arquivo 'saida.dat' em uma planilha e gere o gráfico manualmente.");
  return 0;
}


