/**
 * String
*/
#include <stdio.h>
#include <stdlib.h>

void print_rec(char *s);

int comprimento(char *s);

char * concatenar(char *s, char *r);

int main(void) {

  char *s = (char*) malloc(5*sizeof(char));
  char *r = (char*) malloc(5*sizeof(char));

  s = "abc";
  r = "efg";
  printf("%s",concatenar(s,r));

  //printf("%s",s);

/*
  char nome[30];

  scanf(" %30[^\n]",nome);

  // printf("%s",nome);
  printf("\n\nPrint Recursivo!\n\n");
  print_rec(nome);
  printf("\n\n");

  printf("\n\n");
  printf("\nO comprimento da String é: %d !\n\n", comprimento(nome));
  printf("\n\n");
*/
}

void print_rec(char *s) {
  if (s[0] == '\0') return;
  printf("%c",s[0]);
  print_rec(&s[1]);
}

int comprimento(char *s) {
  int i;
  for(i = 0; s[i] != '\0'; i++);
  return i;
}

char * concatenar(char *s, char *r) {
  int tam_s = comprimento(s);
  int tam_r = comprimento(r);

  int tam = tam_s + tam_r;

  //s = (char*) realloc(s, tam*sizeof(char));
  char * u = (char*) malloc(tam*sizeof(char));

  for(int i = 0; i < tam_s; i++) {
    u[i] = s[i];
  }

  for(int i = 0; i < tam_r; i++) {
    u[tam_s+i] = r[i];
  }

  return u;
}