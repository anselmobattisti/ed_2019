/*
Q7) Escreva um programa que receba duas strings, como parâmetros de entrada, e informe qual é a
maior substring existente nas duas strings. Por exemplo, se as strings de entrada são
ACCTGAACTCCCCCC e ACCTAGGACCCCCC, então a maior substring existente entre as duas
strings será CCCCCC.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  char s1[] = "ACCTGAACTCCCCCC";
  char s2[] = "ACCTGAACTCACCCCC";

  int i, j, maior = 0, pos_inicial_maior = 0;
  for(i = 0; s1[i] != '\0'; i++) {
    for(j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        int aux_i = i;
        int aux_j = j;

        while (s1[aux_i] == s2[aux_j] && s1[aux_i] != '\0' && s2[aux_j] != '\0') {
          aux_i++;
          aux_j++;
        }

        if ((aux_i - i) > maior) {
          maior = aux_i - i;
          pos_inicial_maior = i;
        }
      }
    }
  }

  printf("\nA maior substring é: ");
  for(int k = pos_inicial_maior; maior > 0; k++){
    printf(" %c", s1[k]);
    maior--;
  }
  printf("\n");

  return 0;
}