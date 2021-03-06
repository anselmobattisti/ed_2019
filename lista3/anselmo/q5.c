/*
Q5) Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
seguida, retire o "sufixo" da cadeia s de tamanho n (isto é, retire os n últimos caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
= "abcdefghi" e n = 3, então a cadeia "abcdef" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_fim_n (char *str, int n).

*/
#include <stdio.h>
#include <stdlib.h>

void retira_fim_n (char *str, int n);

int main(void) {

  int n = 3;
  char s[] = "abcdefghi";

  retira_fim_n(s,n);

  printf("\n\n%s\n\n",s);

  return 0;
}

void retira_fim_n (char *str, int n) {
  int tam;
  for(tam=0; str[tam] != '\0'; tam++);

  if (tam <= n) {
    printf("\n\nERRO");
    return;
  }

  // faz com que a posição 0 do vetor seja a posição n
  str[tam-n] = '\0';
}