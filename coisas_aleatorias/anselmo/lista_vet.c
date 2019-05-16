#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  int ant;
  int prox;
  int total;
}TNO;

TNO* memoria[8];

void zera();
int vazia();
void imprime(int pilha);
void insere(int pilha, int valor);

int main() {
  zera();

  int PILHA_1 = 0;
  int PILHA_2 = 1;

  insere(PILHA_1,10);
  insere(PILHA_1,20);
  insere(PILHA_1,30);
  insere(PILHA_1,30);
  insere(PILHA_1,30);
  insere(PILHA_1,31);

  insere(PILHA_2,40);

  imprime(PILHA_1);

  imprime(PILHA_2);

  return 0;
}

void imprime(int pilha) {
  printf("\n Pilha: %d\n",pilha);
  TNO *no = memoria[pilha];
  while(no) {
    printf("%d-> ",no->info);
    if (no->prox == -1) break;
    no = memoria[no->prox];
  }
  printf("\n");
}

void zera() {
  for (int i = 0; i < 8; i++) {
    memoria[i] = NULL;
  }
}

void insere(int pilha, int valor) {
  int pos = vazia();

  if (pos >= 0) {
    if (memoria[pilha] == NULL) {
      pos = pilha;
    }
    TNO *no = (TNO*) malloc(sizeof(TNO));
    no->info = valor;
    no->prox = -1;
    TNO* aux = memoria[pilha];
    int limite = 5;
    while(aux && aux->prox != -1) {
      aux = memoria[aux->prox];
      limite--;
    }
    //printf("- %d - ",limite);
    if (limite == 1) {
      printf("\n\n\nPilha cheia!\n");
      return;
    }

    if (aux) {
      aux->prox = pos;
    }
    memoria[pos] = no;
  } else {
    printf("\n\n\nPilha cheia!\n");
  }
}

int vazia() {
  for (int i = 2; i < 8; i++) {
    if (memoria[i] == NULL)
      return i;
  }
  return -1;
}
