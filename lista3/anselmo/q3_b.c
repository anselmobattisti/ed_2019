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

void transf_i_p (int *vet, int n);

int main(void) {

  int n = 6;
  int vet[] = {10,11,20,35,45,99};

  transf_i_p(vet,n);

  for (int i = 0; i < n; i++) {
    printf("%d - ", vet[i]);
  }

  return 0;
}

void transf_i_p (int *vet, int n) {

  for (int i = 0; i < n; i++) {
    // se for impar encontra o número par
    // sucessor e troque de lugar
    if (vet[i]%2 == 0) {
      for (int j = i+1; j < n; j++) {
        if (vet[j]%2 == 1) {
          int tmp = vet[i];
          vet[i] = vet[j];
          vet[j] = tmp;
        }
      }
    }
  }
}