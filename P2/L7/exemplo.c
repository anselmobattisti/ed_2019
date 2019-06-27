#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
1 - Analisa o caso que a árvore não existe!

    Odem de 2 e 3 podem variar de acordo com o problema

2 - Analisa o caso esquerdo e o caso direito em função do problema
3 - Realiza a chamada recursiva
*/

int conta_pares(TAB* a) {
  if (!a) return 0;
  int p = 0;
  if (a->info % 2 == 0)  p = 1;
  return conta_pares(a->esq) + conta_pares(a->dir) + p;
}

int um_filho(TAB* a) {
  if (!a) return 1;
  if (a->esq && a->dir) return 0;
  return um_filho(a->esq) && um_filho(a->dir);
}

int sucessor(TAB* a, int x, int* s) {
  if (!a) return 0;
  if (a->info > x && a->info < *s) {
    *s = a->info;
  }
  sucessor(a->esq, x, s);
  sucessor(a->dir, x, s);
}

/*
  alt = altura da árvore
 */
int alt(TAB* a) {
  if (!a) return 0;

  int alt_e = alt(a->esq) + 1;
  int alt_d = alt(a->dir) + 1;

  if (alt_e > alt_d) return alt_e;
  return alt_d;
}

int profundidade(TAB* a, int x, int prof) {
  if (a) {
    if (a->info == x) {
      return prof;
    }
    return profundidade(a->esq, x, prof+1)+profundidade(a->dir, x, prof+1);
  }
}

int balanceada_avl(TAB* a) {
  if (!a) return 1;
  int alt_e = alt(a->esq);
  int alt_dir = alt(a->dir);
  if (abs(alt_e - alt_dir) >= 2) return 0;
  return balanceada_avl(a->esq) && balanceada_avl(a->dir);
}

int maior_valor(TAB* a, int maior) {
  if (!a) return 0;

  if (a->info > maior) {
    maior = a->info;
  }

  maior_valor(a->esq, maior);
  maior_valor(a->dir, maior);
}

int main() {

  TAB *t = inicializa();

  t = inserir(t,8);
  t = inserir(t,6);
  t = inserir(t,10);
  t = inserir(t,3);
  t = inserir(t,7);
  t = inserir(t,9);
  t = inserir(t,12);
  t = inserir(t,13);

  int s = 100000000;

  print2DUtil(t,0);

  printf("\n - Pares: %d\n", conta_pares(t));
  printf("\n - Apenas Um Filho: %d\n", um_filho(t));

  int acha_sucessor = 9;
  sucessor(t,acha_sucessor,&s);
  printf("\n - Sucessor de %d: %d\n",acha_sucessor, s);

  printf("\n - Altura: %d\n", alt(t));

  int prof = profundidade(t, acha_sucessor, 0);
  printf("\n - Produndidade: %d\n", prof);

  printf("\n - AVL: %d\n", balanceada_avl(t));

}