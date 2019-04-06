/*
Q2) Implemente uma função em C que receba uma string como parâmetro e retorne uma nova string
com todos os caracteres minúsculos substituídos pelo caracter ‘?’. Por exemplo, se for passada a
string “740-Charitas-Leme”, a função deve retornar a string “740-Ch?r?t?s-L?m?”. A assinatura desta
função deve ser char * codifica (char *str). A string passada como parâmetro não pode ser alterada.
O espaço de memória para a nova string deve ser alocado dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h>

char * codifica (char *str);

int main(void) {

  char s[] = "740-Charitas-Leme";

  printf("\n%s\n",codifica(s));

  return 0;
}


char * codifica (char *str) {

  int i;
  for (i=0; str[i] != '\0'; i++);

  char *r = (char*) malloc(i*sizeof(char));

  for (i=0; str[i] != '\0'; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
      r[i] = '?';
    } else {
      r[i] = str[i];
    }
  }

  return r;
}