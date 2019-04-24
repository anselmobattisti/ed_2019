/*
  Dada uma matriz  Amxn, imprimir o número de linhas
  e o número de colunas nulas da matriz.
*/
#include <stdio.h>
#include <stdlib.h>

void linha_coluna_nula(int **m, int l, int c);

int main(void) {

  int **m = (int**) malloc(sizeof(int*)*4);

  for (int i = 0; i < 4; i++) {
    m[i] = (int*) malloc(sizeof(int)*4);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] = 0;
    }
  }

  m[1][1] = 1;

  linha_coluna_nula(m, 4, 4);

  return 0;
}

void linha_coluna_nula(int **m, int l, int c) {

  for (int i = 0; i < l; i++) {
    int linha = 1;
    int coluna = 1;
    for (int j = 0; j < c; j++) {
      if(m[i][j] != 0) {
        linha = 0;
      }

      if(m[j][i] != 0) {
        coluna = 0;
      }
    }
    if (linha) {
      printf("\nLinha %d não nula.\n",i);
    }

    if (coluna) {
      printf("\nColuna %d não nula.\n",i);
    }
    printf("\n--------\n");
  }

}