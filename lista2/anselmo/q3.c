/**
 * Q3) Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números.
*/

/**
 * A ideia é contar quantas vezes os números de 1 até 9 repetem-se no número 1 e depois contar no número 2 se a contagem for diferente então eles não são permutações
 *
*/
#include <stdio.h>

int main(void) {

  char numero1[100];
  char numero2[100];

  // seta a variável como zero antes de usar
  int count_num[] = {0,0,0,0,0,0,0,0,0,0};
  int tamanho = 0;
  int n;
  int i;

  scanf("\n\n%s", numero1);
  scanf("\n\n%s", numero2);

  while(numero1[tamanho] != '\0') {
    n = (int) numero1[tamanho]%9;
    count_num[n]++;
    tamanho++;
  }

  tamanho = 0;
  while(numero2[tamanho] != '\0') {
    n = (int) numero2[tamanho]%9;
    count_num[n]--;
    tamanho++;
  }

  for(i = 0; i < 10; i++) {
    if (count_num[i] != 0) {
      break;
    }
  }

  if (i>=10){
    printf("\n\nPERMUTAÇÃO\n\n");
  } else {
    printf("\n\nNÃO\n\n");
  }
}