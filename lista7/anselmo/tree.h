typedef struct ab{
  int info;
  struct ab *esq, *dir;
}TAB;

TAB* inicializa();
int altura(TAB* t);