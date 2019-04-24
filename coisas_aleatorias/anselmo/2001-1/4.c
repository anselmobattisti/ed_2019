/*
Escreva uma função que faça a busca de um elemento num vetor de valores inteiros
ordenados em ordem decrescente. A função deve tirar proveito do fato dos elementos
do vetor estarem ordenados e retornar 1 (um), se o elemento estiver presente no
vetor, ou 0 (zero), se o elemento não estiver presente. A assinatura da função deve
ser:
int busca (int n, int *vet, int elem);

*/
#include <stdio.h>

int busca (int n, int *vet, int elem);

int main(void) {
  int vet[] = {1,2,3,5,8,9,10,25,90,100};

  printf("\n%d\n",busca(10, vet,1));
}

int busca (int n, int *vet, int elem) {

  int meio, fim = n, inicio = 0;

  while (inicio < fim) {
    meio = (inicio+fim)/2;

    if (vet[meio] == elem)
      return 1;

    if (vet[meio] > elem)
      fim = meio-1;

    if (vet[meio] < elem)
      inicio = meio+1;
  }

  return 0;
}
