#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme {
  char titulo [100];
  int num_acessos;
  int num_dias_disponivel;
  float media_acessos_dia;
};

typedef struct filme Filme;

Filme* cria_filme (char* titulo, int acessos, int dias);

void imprime(Filme *f);

void mais_procurados (int n, Filme** acervo);

int main(void) {

  Filme **acerto = (Filme**) malloc(sizeof(Filme*)*10);
  acerto[0] = cria_filme("Meu nome é", 150, 10);
  acerto[1] = cria_filme("Meu nome é II", 200, 10);

  mais_procurados(2, acerto);

  return 0;
}

Filme* cria_filme (char* titulo, int acessos, int dias) {
  Filme *aux = (Filme*) malloc(sizeof(Filme));
  strcpy(aux->titulo, titulo);
  aux->num_acessos = acessos;
  aux->num_dias_disponivel = dias;
  aux->media_acessos_dia = acessos / dias;

  return aux;
}

void imprime(Filme *f) {
  printf("\n==============;");
  printf("\nTítulo: %s",f->titulo);
  printf("\nNum Acessos: %d",f->num_acessos);
  printf("\nNum Dias: %d",f->num_dias_disponivel);
  printf("\nMédia: %.2f",f->media_acessos_dia);
  printf("\n==============\n;");
}


void mais_procurados (int n, Filme** acervo) {

  for (int i  = 0; i < n; i++) {
    if (acervo[i]->media_acessos_dia > 10)
      imprime(acervo[i]);
  }

}