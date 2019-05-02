#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aeroporto {
  char sigla[3];
  char cidade[50];
  char pais[30];
  float taxa;
  int capacidade;
}Aeroporto;

Aeroporto* Cadastra(char* s, char* c, char* p, float tx, int cap);

int main() {

  Aeroporto *ar = Cadastra("SDU", "Rio", "BR", 20, 1000);

  printf("%s",ar->cidade);

  return 0;
}

Aeroporto* Cadastra(char* s, char* c, char* p, float tx, int cap) {
  Aeroporto* ar = (Aeroporto*) malloc(sizeof(Aeroporto));

  if (ar == NULL) return NULL;

  strcpy(ar->sigla, s);
  strcpy(ar->cidade, s);
  strcpy(ar->pais, p);
  ar->taxa = tx;
  ar->capacidade = cap;

  return ar;
}