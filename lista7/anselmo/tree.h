typedef struct ab{
  int info;
  struct ab *esq, *dir;
}TAB;

TAB* inicializa();
TAB* cria_no(int x);
void libera(TAB* t);

TAB* busca(TAB* t, int x);
TAB* maior(TAB* t);
TAB* menor(TAB* t);
int altura(TAB* t);

void imprime_pre(TAB* t);
void imprime_pos(TAB* t);
void imprime_sim(TAB* t);

void print2DUtil(TAB *root, int space);