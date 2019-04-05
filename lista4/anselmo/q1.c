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

typedef struct ponto
{
  int i, j;
}TPONTO;


int** cria_matriz(int i, int j, int x);
int imprimir_matriz(int** mat, int l, int c);
int contem_repeticao(int** mat, int l, int c);
int contem_repeticao_linha(int** mat, int l);
int contem_repeticao_coluna(int** mat, int c);

int main(void) {

  // CRIA E POPULA A MATRIZ
  int l = 9, c = 9, k = 1;
  /*
  int** mat = cria_matriz(l, c, 2);

  // gera entrada com problema
  for (int i = 0; i < l; i++) {
    k = i+1;
    for (int j = 0; j < c; j++) {
      if (k >= 10) k = 1;
      mat[i][j] = k++;
    }
  }
  */
  ///////////////////////////////
  // gera entrada com sucesso
  int aux[9][9] = {
      {5,3,4,6,7,8,9,1,2},
      {6,7,2,1,9,5,3,4,8},
      {1,9,8,3,4,2,5,6,7},
      {8,5,9,7,6,1,4,2,3},
      {4,2,6,8,5,3,7,9,1},
      {7,1,3,9,2,4,8,5,6},
      {9,6,1,5,3,7,2,8,4},
      {2,8,7,4,1,9,6,3,5},
      {3,4,5,2,8,6,1,7,9}
  };

  int** mat = cria_matriz(l, c, 0);
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      mat[i][j] = aux[i][j];
    }
  }
  ///////////////////////////////

  // lista de todos os pontos iniciais das matrizes que
  // devem ser verificadas
  TPONTO p[9];
  int pos = 0;

  p[0].i = 0;
  p[0].j = 0;

  p[1].i = 0;
  p[1].j = 3;

  p[2].i = 0;
  p[2].j = 6;

  p[3].i = 3;
  p[3].j = 0;

  p[4].i = 3;
  p[4].j = 3;

  p[5].i = 3;
  p[5].j = 6;

  p[6].i = 6;
  p[6].j = 0;

  p[7].i = 6;
  p[7].j = 3;

  p[8].i = 6;
  p[8].j = 6;


  int i;
  for (i = 0; i < 9; i++) {
    if (!contem_repeticao(mat,p[i].i,p[i].j)){
      printf("Erro no quadrante: (%d,%d)",p[i].i, p[i].j);
      break;
    }
    if (!contem_repeticao_linha(mat,i)){
      printf("Erro na linha: %d",i+1);
      break;
    }
    if (!contem_repeticao_coluna(mat,i)){
      printf("Erro na coluna: %d",i+1);
      break;
    }
  }

  // foi até o final
  if (i == 9) {
    printf("\nSim");
  } else {
    printf("\nNão é uma solução");
  }

  imprimir_matriz(mat, l, c);

  return 0;
}

int contem_repeticao_linha(int** mat, int l) {
  int t[9] = {0,0,0,0,0,0,0,0,0};
  int s = 1;
  for (int j = 0; j < 9; j++) {
    if (t[mat[l][j]%9]){
      s = 0;
      break;
    } else {
      t[mat[l][j]%9] = 1;
    }
  }
  return s;
}

int contem_repeticao_coluna(int** mat, int c) {
  int t[9] = {0,0,0,0,0,0,0,0,0};
  int s = 1;
  for (int i = 0; i < 9; i++) {
    if (t[mat[i][c]%9]){
      s = 0;
      break;
    } else {
      t[mat[i][c]%9] = 1;
    }
  }
  return s;
}

/*
  l = representa a linha inicial do bloco que será verificado
  c = representa a coluna inicial do bloco que será verificada
*/
int contem_repeticao(int** mat, int l, int c) {
  int t[9] = {0,0,0,0,0,0,0,0,0};
  int s = 1;
  for (int i = l; i < l+3; i++) {
    for (int j = c; j < c+3; j++) {
      if (t[mat[i][j]%9]){
        s = 0;
        break;
      } else {
        t[mat[i][j]%9] = 1;
      }
    }
    if (s == 0) break;
  }
  return s;
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