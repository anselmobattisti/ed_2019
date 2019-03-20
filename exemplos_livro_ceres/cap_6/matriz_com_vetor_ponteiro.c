/**
 * Esse programa implementa a estratégia de usar
 * matrizes como sendo um vetor unidimenciosal
 *
 * */
#include <stdio.h>
#include <stdlib.h>

/**
 * Recebe como parâmetro o número de linhas e colunas
 * e aloca uma matriz bidimencional
*/
int** newMatriz(int i, int j);
void destroyMatriz(int **m, int j);

int main(void) {

  int** m = newMatriz(3,4);

  m[0][0] = 20;
  m[1][2] = 5;

  printf("\n\n%d\n\n",m[0][0]);
  printf("\n\n%d\n\n",m[1][2]);
  destroyMatriz(m, 3);

  return 0;
}

int** newMatriz(int i, int j){
  int **m = (int**) malloc(i*sizeof(int*));

  for (int i = 0; i < j; i++) {
    m[i] = (int*) malloc(j*sizeof(int));
  }

  return m;
}

void destroyMatriz(int **m, int i) {
  for(int k = 0; k < i; k++) {
    free(m[k]);
  }

  free(m);
}
