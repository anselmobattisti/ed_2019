#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha {
 int vet[MAX],
 num;
} PILHA;

PILHA* p;

void push(int x);
int top();
void pop1();

int main() {
  p = (PILHA*) malloc(sizeof(PILHA));
  p->num = 0;

  push(20);
  push(21);
  push(22);
  push(23);
  push(24);

  pop1();

  printf("%d",top());
  return 0;
}

void push(int x) {
  if (p->num == 99) {
    printf("Pilha lotada");
    return;
  }
  p->vet[p->num] = x;
  p->num++;
}

int top() {
  return p->vet[p->num-1];
}

void pop1() {
  if (p->num >= 0)
    p->num--;
}