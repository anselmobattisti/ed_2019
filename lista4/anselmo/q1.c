/*
Q1) Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva
um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma
solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9
somente uma vez).
5 3 4 | 6 7 8 | 9 1 2
 6 7 2 | 1 9 5 | 3 4 8
 1 9 8 | 3 4 2 | 5 6 7
-------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
-------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
 3 4 5 | 2 8 6 | 1 7 9

*/
#include <stdio.h>
#include <stdlib.h>

int** cria_matriz(int i, int j, int x);
int imprimir_matriz(int** mat, int l, int c);
int contem_repeticao(int** mat, int l, int c);

int main(void) {

  // CRIA E POPULA A MATRIZ
  int l = 9, c = 9, k = 1;
  int** mat = cria_matriz(l, c, 2);

  // gera entrada com problema
  for (int i = 0; i < l; i++) {
    k = i+1;
    for (int j = 0; j < c; j++) {
      if (k >= 10) k = 1;
      mat[i][j] = k++;
    }
  }

  imprimir_matriz(mat, l, c);
  imprimir_matriz(mat[3][0], l, c);
  return 0;
}

int contem_repeticao(int** mat, int l, int c) {
  imprimir_matriz(mat, 3,3);
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