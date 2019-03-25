/*
Q4) Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
número for negativo.
*/
#include <stdio.h>

int main(void) {
  char numero[100];

  printf("\n\nDigite um número: \n");
  scanf("%s", numero);

  // qual o tamanho da string?
  int i, count = 0;
  while(1) {
    if (numero[count] != '\0') {
      count++;
    } else {
      break;
    }
  }

  // onde é o meio da string?
  int num_rep = (int) count / 2;

  // subtrai o último valor para que o índice fique igual
  // a posição do vetor
  count--;

  for(i = 0; i <= num_rep; i++) {
    if (numero[i] != numero[count-i]){
      break;
    }
  }

  if (i > num_rep) {
    printf("\n\nVERDADEIRO\n");
  } else {
    printf("\n\nFALSO\n");
  }
}