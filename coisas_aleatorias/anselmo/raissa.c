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

  for(int i = 0; i<n_linhas; i++) {
    printf("%d - ",mat[i]);
    if (i%n == n-1)
      printf("\n");
  }

  printf("\n\nRemovida\n\n");

  aux = complemento(n,1,1,mat);
  for(int i = 0; i<((n-1)*(n-1)); i++) {
    printf("%d - ",aux[i]);
    if (i%n == n-2)
      printf("\n");
  }

  printf("\n");
  return 0;
}

int * complemento(int n, int i, int j, int *mat) {

  int n_linhas = (n-1)*(n-1);
  int *aux_vet = (int*) malloc(sizeof(int)*n_linhas);

  int inicio_linha = n*i; // linha
  int fim_linha = inicio_linha + n; // coluna
  int c = 0;
  for (int i = 0; i < n*n; i++) {
    // pula a linha
    if (i>=inicio_linha && i < fim_linha) {
      continue;
    }

    // pula a coluna
    if (i%n == 0) {
      continue;
    }

    printf("****%d****%d\n",i,i%n);
    aux_vet[c] = mat[i];
    c++;
  }

  return aux_vet;

}