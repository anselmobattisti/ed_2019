/*
Q3) Considere que você receba um vetor de inteiros com números ímpares e pares e um número n,
sendo n o tamanho do vetor. Implemente uma função que separe os valores inteiros de um vetor em
ímpares e pares, obedecendo a ordem de entrada destes números no vetor. Implemente os dois
protótipos abaixo:
a) int* transf_i_p (int *vet, int n)
b) void transf_i_p (int *vet, int n)
*/
#include <stdio.h>
#include <stdlib.h>

int* transf_i_p (int *vet, int n);

int main(void) {

  int n = 6;
  int vet[] = {10,11,20,35,45,99};

  int *vet_2 = (int*) malloc(n*sizeof(int));

  vet_2 = transf_i_p(vet,n);

  for (int i = 0; i < n; i++) {
    printf("%d - ", vet_2[i]);
  }
}

int* transf_i_p (int *vet, int n) {

  int *aux = (int*) malloc(n*sizeof(int));
  int count = 0;

  for (int i = 0; i < n; i++) {
    if (vet[i]%2 == 1) {
      aux[count] = vet[i];
      count++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (vet[i]%2 == 0) {
      aux[count] = vet[i];
      count++;
    }
  }

  return aux;
}