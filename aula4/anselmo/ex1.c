/*
Alocação de matrizes de forma estática e dinâmica
*/
#include <stdio.h>
#include <stdlib.h>

void imprime_matriz(int i, int j, int m[i][j]);
void imprime_matriz_dinamica(int i, int j, int **m);

int** cria_matriz(int i, int j, int x);
void destroi_matriz(int i, int **m);

int main(void) {

  printf("\nMatriz definida estaticamente.\n\n");
  int mat1[4][2] = {1,2,3,4,5,6,7,8};
  imprime_matriz(4, 2, mat1);

  printf("\nMatriz definida dinamicamente.\n\n");
  int **m2 = cria_matriz(3,3,2);
  imprime_matriz_dinamica(3,3,m2);
  destroi_matriz(3, m2);

  // gera um erro pois a matriz foi removida
  imprime_matriz_dinamica(3,3,m2);

}

int** cria_matriz(int i, int j, int x) {
  int **m = (int**) malloc(sizeof(int*)*i);

  for (int k = 0; k < j; k++) {
    m[k] = (int*) malloc(sizeof(int)*j);
  }

  for (int k = 0; k < i; k++) {
    for (int w = 0; w < j; w++) {
      m[k][w] = x;
    }
  }

  return m;
}

void imprime_matriz(int i, int j, int m[i][j]){
  for(int k = 0; k < i; k++) {
    printf("\n-----\n");
    for (int w = 0; w < j; w++)  {
      printf("%d - ",m[k][w]);
    }
  }
  printf("\n-----\n");
}

void imprime_matriz_dinamica(int i, int j, int **m){
  for(int k = 0; k < i; k++) {
    printf("\n-----\n");
    for (int w = 0; w < j; w++)  {
      printf("%d - ",m[k][w]);
    }
  }
  printf("\n-----\n");
}

void destroi_matriz(int i, int **m){
  for(int k = 0; k < i; k++) {
    free(m[i]);
  }
  free(m);
}
