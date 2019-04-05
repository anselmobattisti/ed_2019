/*
Q3) Escreva uma função que dada uma string composta por substrings separadas por “/”, retorne
todas as suas substrings da string original. Por exemplo, a string /Fla/Flu/Bota/ será decomposta
em:
Fla
Flu
Bota
Esta função não deve modificar a string original. O protótipo da função é o seguinte: char** s2ss
(char *str). Isto é, a resposta desta função será uma matriz de caracteres alocada
dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h>

char** s2ss(char *str);

int main(void) {

  char *s = "/Fla/Flu/Bota/";

  char** s = s2ss(&s);

  return 0;
}

char** s2ss(char *str) {
  int oc = 2;
  char** n = (char**) malloc(sizeof(char*)*oc);
  printf("%s",str);
  return n;
}