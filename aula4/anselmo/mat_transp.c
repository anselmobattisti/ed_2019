/*

  implemente um programa que teste uma matriz alocada
  dinamicamente quanto a sua simetria, se for retorne a
  matriz triangular inferior caso contrário retorne a
  matriz transposta.

  Exemplos:
  entrada         saída
   1 2 3          1 4 7
   4 5 6          2 5 8
   7 8 9          3 6 9

  entrada         saída
   1 2 3          1
   2 5 6          2 5
   3 6 9          3 6 9

*/

#include <stdio.h>
#include <stdlib.h>

int** cria_matriz(int i, int j, int x);
int** teste(int** m, int l, int c, int* sim);

void imprime_matriz_dinamica(int i, int j, int **m);
void imprime_matriz_triangular(int i, int **m);

int main(void) {

  int sim = 0;
  int i = 3, j = 3;

  int **m2 = cria_matriz(i,j,2);
  m2[0][0] = 1;
  m2[0][1] = 2;
  m2[0][2] = 3;

  m2[1][0] = 4;
  m2[1][1] = 5;
  m2[1][2] = 6;

  m2[2][0] = 7;
  m2[2][1] = 8;
  m2[2][2] = 9;

  int **m3 = cria_matriz(i,j,2);
  m3[0][0] = 1;
  m3[0][1] = 8;
  m3[0][2] = 3;

  m3[1][0] = 8;
  m3[1][1] = 5;
  m3[1][2] = 6;

  m3[2][0] = 3;
  m3[2][1] = 6;
  m3[2][2] = 9;

  printf("\nM2.\n\n");
  printf("\nAntes da função.\n\n");
  imprime_matriz_dinamica(i,j,m2);

  m2 = teste(m2, i, j, &sim);

  printf("\nDepois da função.\n\n");
  printf("Simétrica: ");
  if (sim) {
    printf("SIM");
    imprime_matriz_triangular(i,m2);
  } else {
    printf("NÃO");
    imprime_matriz_dinamica(i,j,m2);
  }

  printf("\nM3.\n\n");
  printf("\nAntes da função.\n\n");
  imprime_matriz_dinamica(i,j,m3);

  int sim3 = 0;
  m3 = teste(m3, i, j, &sim3);

  printf("\nDepois da função.\n\n");
  printf("Simétrica: ");
  if (sim3) {
    printf("SIM");
    imprime_matriz_triangular(i,m3);
  } else {
    printf("NÃO");
    imprime_matriz_dinamica(i,j,m3);
  }


}

int** teste(int** m, int l, int c, int* sim) {
  int** aux;

  if (l != c) {
    *sim = 0;
  } else {
    *sim = 1;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        if (m[i][j] != m[j][i]) {
          *sim = 0;
          break;
        }
      }
      if (!*sim) {
        break;
      }
    }
  }
  if (*sim) {
    int** aux = (int**) malloc(sizeof(int*)*l);
    for (int i = 0; i < l; i++){
      aux[i] = (int*) malloc(sizeof(int)*(i+1));
    }
    for (int i = 0; i < l; i++){
      for (int j = 0; j < i; j++){
        aux[i][j] = m[i][j];
      }
    }
  } else {
    aux = cria_matriz(c, l, 0);
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        aux[j][i] = m[i][j];
      }
    }
  }

  return aux;
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

void imprime_matriz_triangular(int i, int **m){
  for(int k = 0; k <= i; k++) {
    printf("\n-----\n");
    for (int w = 0; w <= k; w++)  {
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
