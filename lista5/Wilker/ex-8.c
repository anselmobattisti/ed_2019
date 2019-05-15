#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
} TLista;

// Interface da lista.
TLista* inicializa();
TLista* insere_ini(TLista *l, int mat, char* nome, float cr);
void libera(TLista *l);
void imprime(TLista *l);
int igual(TLista* l1, TLista *l2);

int main(void) {
    TLista *l1 = inicializa();
    l1 = insere_ini(l1, 1234, "João", 7.8);
    l1 = insere_ini(l1, 2345, "Maria", 6.5);
    l1 = insere_ini(l1, 3456, "Ana", 9.2);

    TLista *l2 = inicializa();
    l2 = insere_ini(l2, 1234, "João", 7.8);
    l2 = insere_ini(l2, 2345, "Maria", 6.5);

    imprime(l1);
    imprime(l2);
  
    printf("L1 e L2 iguails? %d\n",igual(l1, l2));
    
    libera(l1);
    libera(l2);

    printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
    l1 = inicializa();
    l1 = insere_ini(l1, 1234, "João", 7.8);
    l1 = insere_ini(l1, 2345, "Maria", 6.5);
    l1 = insere_ini(l1, 3456, "Ana", 9.2);

    l2 = inicializa();
    l2 = insere_ini(l2, 1234, "João", 7.8);
    l2 = insere_ini(l2, 2345, "Maria", 6.5);
    l2 = insere_ini(l2, 3456, "Sara", 8.3);

    imprime(l1);
    imprime(l2);
  
    printf("L1 e L2 iguails? %d\n",igual(l1, l2));
    
    libera(l1);
    libera(l2);
    
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
    l1 = inicializa();
    l1 = insere_ini(l1, 1234, "João", 7.8);
    l1 = insere_ini(l1, 2345, "Maria", 6.5);
    l1 = insere_ini(l1, 3456, "Ana", 9.2);

    l2 = inicializa();
    l2 = insere_ini(l2, 1234, "João", 7.8);
    l2 = insere_ini(l2, 2345, "Maria", 6.5);
    l2 = insere_ini(l2, 3456, "Ana", 9.2);
    
    imprime(l1);
    imprime(l2);
  
    printf("L1 e L2 iguails? %d\n",igual(l1, l2));
    
    libera(l1);
    libera(l2);
    
    return 0;
}

int igual(TLista* l1, TLista *l2) {
    if (!l1&&!l2) return 1;
    if (!l1 || !l2) return 0;
    if (l1->mat == l2->mat &&
	    !strcmp(l1->nome, l2->nome) &&
		l1->cr == l2-> cr) 
			return 1 && igual(l1->prox, l2->prox);
    return 0;
}

void imprime(TLista *l) {
    TLista *p = l;
    while (p) {
        printf("Matricula: %d, Nome: %s, CR: %.2f\n", p->mat, p->nome, p->cr);
        p = p->prox;
    }
    printf("\n");
}

TLista* inicializa() {
    return NULL;
}

// Insere um aluno no inicio da lista de alunos.

TLista* insere_ini(TLista *l, int mat, char* nome, float cr) {
    TLista *novo = (TLista*) malloc(sizeof (TLista));
    novo->mat = mat;
    strcpy(novo->nome, nome);
    novo->cr = cr;
    novo->prox = l;

    return novo;
}

// Libera da memória a lista de alunos.

void libera(TLista *l) {
    TLista *p = l;
    while (p) {
        TLista *temp = p;
        p = p->prox;
        free(temp);
    }
}
