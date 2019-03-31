/**
 * Usando o quicksort nativo do C
 *
*/
#include <stdio.h>
#include <stdlib.h>

/*
------------ *(int*)a
o primeiro * indica que vamos usar o valor do ponteiro e o
(int *) é o cast do tipo void pra int
*/
int comp_int(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

int main () {
   int n;

   int values[] = { 88, 56, 100, 2, 25 };

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), comp_int);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   return(0);
}