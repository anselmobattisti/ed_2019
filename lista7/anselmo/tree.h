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
TAB* copiar(TAB* t);
TAB* inserir(TAB* t, int x);
TAB* retira(TAB* t, int x);
TAB* espelho (TAB *a);
TAB* retira_pares (TAB* t);

int altura(TAB* t);
int igual (TAB* a1, TAB* a2);
int nf(TAB *a);
int ni(TAB *a);

void imprime_pre(TAB* t);
void imprime_pos(TAB* t);
void imprime_sim(TAB* t);

void print_tree(TAB* t, char* title);
void print2DUtil(TAB *root, int space);