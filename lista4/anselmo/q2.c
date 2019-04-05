/**
Q2) Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1
representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e
m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda
matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a
primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2)
*/
#include <stdio.h>
#include <stdlib.h>

int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2);
int** cria_matriz(int i, int j, int x);
int imprimir_matriz(int** mat, int l, int c);

int main(void) {
  int m1 = 2, n1 = 3, m2 = 3, n2 = 2;
  int ** mat1 = cria_matriz(m1, n1, 0);
  int ** mat2 = cria_matriz(m2, n2, 0);

  mat1[0][0] = 2;
  mat1[0][1] = 5;
  mat1[0][2] = 9;

  mat1[1][0] = 3;
  mat1[1][1] = 6;
  mat1[1][2] = 8;

  mat2[0][0] = 2;
  mat2[0][1] = 7;

  mat2[1][0] = 4;
  mat2[1][1] = 3;

  mat2[2][0] = 5;
  mat2[2][1] = 2;

  // imprimir_matriz(mat1, m1, n1);
  // imprimir_matriz(mat2, m2, n2);

  printf("\n\nO resultado da multiplicação é:");
  int** result = mult(m1, n1, mat1, m2, n2, mat2);
  imprimir_matriz(result, m1, n2);

}


int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2) {

  if (n1 != m2) {
    printf("Não possível realizar multiplicação");
    return cria_matriz(1,1,0);
  }

  int** n = cria_matriz(m1,n2,0);

  for (int i = 0; i < m1; i++) {
    for(int j = 0; j < n2; j++) {
      for (int k = 0; k < n1; k++) {
        n[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  return n;
}

int imprimir_matriz(int** mat, int l, int c) {
  printf("\n\n");
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d - ",mat[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

int** cria_matriz(int i, int j, int x) {
  int **m = (int**) malloc(sizeof(int*)*i);

  for (int k = 0; k < i; k++) {
    m[k] = (int*) malloc(sizeof(int)*i);
  }

  for (int k = 0; k < i; k++) {
    for (int w = 0; w < j; w++) {
      m[k][w] = x;
    }
  }

  return m;
}