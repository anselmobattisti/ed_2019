/*
Q4) A matriz de Hadamard H(N), usada em projetos de programas corretores de erros, é uma
matriz N por N, onde N é potência de dois, de elementos booleanos (isto é, elementos 0 e 1) que
satisfaz a seguinte propriedade: dadas duas linhas distintas i e j, onde 0 <= i < N e 0 <= j < N,
desta matriz, a quantidade de elementos distintos nestas linhas é sempre igual a N/2. Abaixo
exemplica-se H(1), H(2) e H(4).
H(1) | H(2) | H(4)
-----------+--------+------------
 1 | 1 1 | 1 1 1 1
 | 1 0 | 1 0 1 0
 | 1 1 0 0
 | 1 0 0 1
Para construir H(M), onde M = 2 * N, divide-se a matriz H(M) em quatro partes iguais, chamadas
de quadrantes, repete-se três vezes a matriz H(N) nos quadrantes de menores índices, e no
quadrante de maiores índices de H(M), inverte-se a matriz H(N). Implemente um programa que
imprima a matriz H(N) na console. A dimensão desta matriz deve ser lida pelo seu programa.
*/
#include <stdio.h>
#include <stdlib.h>

void hadamard(int** mat, int n, int i);

int** cria_matriz(int i, int j, int x);
int imprimir_matriz(int** mat, int l, int c);

int main(void) {
  int n = 0;

  scanf("%d",&n);

  int** mat = cria_matriz(n,n,8);

  hadamard(mat, n, 1);

  imprimir_matriz(mat, n, n);

  return 0;
}

void hadamard(int** mat, int n, int i) {

  if (i > n) {
    return;
  }
  if (i == 1) {
    mat[0][0] = 1;
  } else {
    int i_final = i/2;
    int j_final = i/2;

    for(int k = 0; k < i_final; k++) {
      for(int w = 0; w < j_final; w++) {

        // direito
        mat[k][j_final+w] = mat[k][w];

        // abaixo
        mat[i_final+k][w] = mat[k][w];

        // invetido
        mat[i_final + k][j_final + w] = !mat[k][w];

      }
    }
    printf("\n\n");
  }

  hadamard(mat, n, i*2);
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