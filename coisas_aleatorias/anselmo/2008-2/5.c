/*
  Insere em uma lista em ordem alfabética
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct lista {
 char nome[81];
 float media;
 struct lista *prox;
};

typedef struct lista Lista;

void imprime(Lista* l);
Lista* insere (Lista* l, char* nome, float media);


int main() {
  Lista* l = NULL;
  l = insere(l,"maria",100);
  l = insere(l,"anselmo",100);
  l = insere(l,"paula",100);
  l = insere(l,"duda",100);

  imprime(l);
  return 0;
}

Lista* insere (Lista* l, char* nome, float media){
  Lista *aux = (Lista*) malloc(sizeof(Lista));
  strcpy(aux->nome, nome);
  aux->media = media;
  // se naõ tem lista insere e retorna
  if (!l) {
    aux->prox = l;
    return aux;
  }
  Lista *p = l;
  Lista *ant = NULL;
  while (p) {
    if (strcmp(nome, p->nome) < 0)
      break;
    ant = p;
    p = p->prox;
  }
  if (!ant) {
    aux->prox = l;
    return aux;
  }
  ant->prox = aux;
  aux->prox = p;
  return l;
}

void imprime(Lista* l) {
  if(!l) return;

  while (l) {
    printf("%s\n",l->nome);
    l = l->prox;
  }
  printf("\n");
}
