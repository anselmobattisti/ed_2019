/**
 * String
*/
#include <stdio.h>
#include <stdlib.h>

void print_rec(char *s);

int comprimento(char *s);

void concatenar(char *s, char *r);

int main(void) {

  char *s = (char*) malloc(5*sizeof(int));
  char *r = (char*) malloc(5*sizeof(int));
  s = "abc";
  r = "efg";
  concatenar(s,r);

  printf("%s",s);

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

void concatenar(char *s, char *r) {
  int tam_s = comprimento(s);
  int tam_r = comprimento(r);
  if (tam_r <= 0) return;

  int tam = tam_s + tam_r;

  s = (char*) realloc(s, tam*sizeof(int));

  int c = 0;
  for(int i = tam_s; i < tam; i++) {
    s[i] = r[c];
    c++;
  }
}