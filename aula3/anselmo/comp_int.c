/**
 * Usando o quicksort nativo do C
 *
*/
#include <stdio.h>
#include <stdlib.h>

int comp_int(const void *a, const void *b);
int * ordena_certo(int * vet, int n);

int main () {
   int n = 5;

   int values[] = { 88, 56, 100, 2, 25 };

   printf("\n Ordenação direta! \n");
   printf("\n---------------------\n");
   printf("\nBefore sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), comp_int);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

  printf("\n\n Ordenação dentro de função!\n");
  printf("\n---------------------\n");
  int * novo = (int*) malloc(5*sizeof(int));
  novo = ordena_certo(values, n);
  for( n = 0 ; n < 5; n++ ) {
    printf("%d ", novo[n]);
  }
  printf("\n---------------------\n");
  return(0);
}

/*
------------ *(int*)a
o primeiro * indica que vamos usar o valor do ponteiro e o
(int *) é o cast do tipo void pra int
*/
int comp_int(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int * ordena_certo(int * vet, int n) {
  int *certo = (int*) malloc(n*sizeof(int));

  for(int i = 0; i < n; i++) {
    certo[i] = vet[i];
  }

  qsort(certo, n, sizeof(int), comp_int);

  return certo;
}