#include <stdio.h>
#include <stdlib.h>

int * complemento(int n, int i, int j, int *mat);

int main(void) {
  int n = 3;
  int n_linhas = n*n;

  int *mat = (int*) malloc(sizeof(int)*n_linhas);
  int *aux;

  for(int i = 0; i<n_linhas; i++) {
    mat[i] = i;
  }

  printf("\nMatriz Original\n");
  for(int i = 0; i<n_linhas; i++) {
    printf("%d - ",mat[i]);
    if (i%n == n-1)
      printf("\n");
  }

  int k = 2, w = 1;
  printf("\nMatriz Complementar removendo linha: %d e coluna: %d.\n",k,w);
  aux = complemento(n,k,w,mat);
  for(int i = 0; i<((n-1)*(n-1)); i++) {
    printf("%d - ",aux[i]);
    if (i%n == n-2)
      printf("\n");
  }

  printf("\n");
  return 0;
}

int * complemento(int n, int i, int j, int *mat) {

  int n_linhas = (n-1)*(n-1); // número de elementos do vetor resultante
  int *aux_vet = (int*) malloc(sizeof(int)*n_linhas);

  int inicio_linha = n*i; // início da linha na tabela linha
  int fim_linha = inicio_linha + n; // fim da linha na tabela linha

  // índica no vetor resultante
  int c = 0;

  int rem_coluna = j; // primeria coluna que será removida
  for (int i = 0; i < n*n; i++) {

    // pula a coluna
    if (i == rem_coluna) {
      rem_coluna += n;
      continue;
    }

    // pula a linha
    if (i>=inicio_linha && i < fim_linha) {
      continue;
    }

    aux_vet[c] = mat[i];
    c++;
  }

  return aux_vet;
}