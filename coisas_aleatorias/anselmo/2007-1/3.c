/*
cifra de cezar
*/
#include <stdio.h>
#include <stdlib.h>

char* cifra_cesar (char* msg);

int main(void) {

  char* msg = "abc xyz ABC XYZ nome 10 é \% Anselmo";

  printf("\n\n----\n%s\n----\n",cifra_cesar(msg));
}

char* cifra_cesar (char* msg) {
  int t = 0;
  for (t = 0; msg[t] != '\0'; t++);
  char *aux = (char*) malloc(sizeof(char)*t);

  for (int i = 0; msg[i] != '\0'; i++) {
    if ((msg[i] >= 'a' && msg[i] <= 'z') || (msg[i] >= 'A' && msg[i] <= 'Z')){

      if (msg[i] == 'x') {
        aux[i] = 'a';
        continue;
      }

      if (msg[i] == 'y') {
        aux[i] = 'b';
        continue;
      }

      if (msg[i] == 'z') {
        aux[i] = 'c';
        continue;
      }

      if (msg[i] == 'X') {
        aux[i] = 'A';
        continue;
      }

      if (msg[i] == 'Y') {
        aux[i] = 'B';
        continue;
      }

      if (msg[i] == 'Z') {
        aux[i] = 'C';
        continue;
      }

      aux[i] = msg[i]+3;
      continue;
    }
    aux[i] = msg[i];
  }

  return aux;
}