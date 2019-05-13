#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expressao
{
 char descricao[81];
 struct expressao *prox, *ant;
};
typedef struct expressao Expressao;

int Ranking(Expressao** p, char* exp);
void Imprime(Expressao* lst);

int main(void) {

  Expressao* l = NULL;

  Ranking(&l, "Anselmo");
  Ranking(&l, "Battisti");
  Ranking(&l, "Battisti");

  Imprime(l);

}

void Imprime(Expressao* lst) {
  Expressao* l = lst;
  int n = 1;
  printf("\n");
  while (l) {
    printf("%d - %s\n",n,l->descricao);
    l = l->prox;
  }
}

int Ranking(Expressao** p, char* exp1) {

  Expressao *q = *p;
  Expressao *ant = NULL;

  int n = 1;
  while(q) {
    ant = q;
    if (strcmp(q->descricao, exp1) == 0) {
      continue;
    }
    q = q->prox;
    n++;
  }

  if (!q) {
    Expressao *aux = (Expressao*) malloc(sizeof(Expressao));
    strcpy(aux->descricao, exp1);
    aux->prox = NULL;

    if (ant == NULL) {
      *p = aux;
      aux->ant = NULL;
    } else {
      aux->ant = ant;
      ant->prox = aux;
    }
    return n;
  }

  if (ant == NULL) return 1;

  ant->prox = q->prox;
  ant->ant = q->ant;

}