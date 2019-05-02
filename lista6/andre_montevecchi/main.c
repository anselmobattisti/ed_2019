#include <stdio.h>
#include <stdlib.h>
#include "rlutil.h"

typedef struct no{
    int info;
    struct no * prox;
}TNO;

typedef struct pilha{
    TNO * prim;
}TPilha;

typedef struct fila {
    TNO *ini, *fim;

}TFila;

//Pilha
TPilha * inicializaPilha (void);
void push (TPilha *p, int elem);
int pop (TPilha *p);
void libera (TPilha *p);
int vazia (TPilha *p);
TPilha*f2p(TFila *f);

//Fila
TFila* inicializaFila (void);
TFila* insereFila (TFila *f, int elem);
int retiraFila (TFila *f);
void liberaFila (TFila *f);
int vaziaFila (TFila *f);
TFila* inv_fila(TFila *f);
TFila* sep_fila (TFila *f);
TFila* Junta_Filas (TFila *f1, TFila *f2);
void retira_pares (TPilha *p);
TFila* p2f (TPilha *p);
void separa_filas(TFila * f, TFila *par, TFila * impar);


//{Exercicios da lista
/*
(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);
*/
TPilha*f2p(TFila *f){
    TPilha *p = inicializaPilha();
    TPilha *pAux = inicializaPilha();
    if(vaziaFila(f)){
        printf("\nFila vazia! flw vlw...\n");
        exit(1);
    }
    while(!vaziaFila(f)){
        push(p, retiraFila(f));
    }

    while(!vazia(p)){
        push(pAux, pop(p));
    }
    return pAux;
}

/*
(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);
*/
TFila *inv_fila(TFila *f){
    TPilha *pilhaAux = inicializaPilha();
    TFila *filaAux = inicializaFila();
    if(vaziaFila(f)) {
        setColor(RED);
        printf("\nFila vazia! flw vlw...\n");
        setColor(WHITE);
        exit(1);
    }
    //Tira da fila e coloca na pilha - saporra já vai invertida ;)
    while(!vaziaFila(f))
        push(pilhaAux, retiraFila(f));

    while(!vazia(pilhaAux))
            insereFila(filaAux, pop(pilhaAux));

    free(pilhaAux);

    return filaAux;

}

/*
(c) uma função que, dada uma fila f, retorne uma nova fila contendo os elementos pares de f,
e modifique a fila original (f) para que ela possua somente os elementos ímpares, respeitando
a ordem de entrada em f. A função deve obedecer o seguinte protótipo: TFila* sep_fila (TFila*f);
*/
TFila* sep_fila (TFila *f){
    TFila *filaPares = inicializaFila();
    TFila *filaImpares = inicializaFila();
    int valor = 0;
    validaFilaVazia(f);

    //separa os itens de f nas filas de pares e ímpares
    while(!vaziaFila(f)){
        valor = retiraFila(f);
        if(valor % 2 == 0)
            insereFila(filaPares, valor);
        else
            insereFila(filaImpares, valor);
    }

    //Insere valores impares na fila f
    while(!vaziaFila(filaImpares))
    {
        insereFila(f, retiraFila(filaImpares));
    }

    free(filaImpares);
    return filaPares;
}



/*
(d) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);
*/
TFila* Junta_Filas (TFila *f1, TFila *f2){
    TFila *filaAux = inicializaFila();
    TFila *f1Inalterada = inicializaFila();
    TFila *f2Inalterada = inicializaFila();
    int valor = 0;
    //Se f1 ou f2 estiverem vazias, pára tudoo!!!
    validaFilaVazia(f1);
    validaFilaVazia(f2);

    //copiando f1 para filaAux
    while(!vaziaFila(f1)){
        valor = retiraFila(f1);
        insereFila(filaAux, valor);
        insereFila(f1Inalterada, valor);
    }

    //copiando f2 para filaAux
    while(!vaziaFila(f2)){
        valor = retiraFila(f2);
        insereFila(filaAux, valor);
        insereFila(f2Inalterada, valor);
    }

    //remonta f1
    while(!vaziaFila(f1Inalterada))
        insereFila(f1, retiraFila(f1Inalterada));

    //remonta f2
    while(!vaziaFila(f2Inalterada))
        insereFila(f2, retiraFila(f2Inalterada));

    free(f1Inalterada);
    free(f2Inalterada);

    return filaAux;
}


/*
(e) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A
função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);
*/
void retira_pares (TPilha *p){
    if(vazia(p)) exit(1);
    TPilha *pilhaAux = inicializaPilha();
    TPilha *pilhaPar = inicializaPilha();
    int valor = 0;
    //separa elementos pares e impares
    while(!vazia(p)){
        valor = pop(p);
        if(valor % 2 == 0)
            push(pilhaPar, valor);
        else
            push (pilhaAux, valor);
    }

    //Devolve somente elementos impares para pilha original p
    while(!vazia(pilhaAux))
        push(p, pop(pilhaAux));

    printf("\nImprimindo pilha p...\n");
    imprimePilha(p);
    free(pilhaAux);
    free(pilhaPar);

}

/*
(f) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p);
*/
TFila* p2f (TPilha *p){
    if(vazia(p)) exit(1);
    TFila *fila = inicializaFila();
    TPilha *pilhaAux = inicializaPilha();

    //Insere na pilha pra inverter saporra :P
    while(!vazia(p)){
        push(pilhaAux, pop(p));
    }

    //Insere na fila já na ordem solicitada! :P
    while(!vazia(pilhaAux)){
        insereFila(fila, pop(pilhaAux));
    }
    free(pilhaAux);
    return fila;
}

/*
(g) implemente uma função que receba três filas, f, impares e pares, e separe todos os valores
guardados em f de tal forma que os valores pares são colocados na fila pares e os valores
ímpares na impares. Ao final da execução desta função, f permanecerá com todos os seus
elementos. O protótipo desta função é o seguinte: void separa_filas(TFila * f, TFila *par,
TFila * impar).
*/

void separa_filas(TFila * f, TFila *par, TFila * impar){
    validaFilaVazia(f);
    TFila *filaAux = inicializaFila();
    int valor = 0;
    //Verifica valor e separa nas listas par e impar
    while(!vaziaFila(f)){
        valor = retiraFila(f);
        if(valor % 2 == 0)
            insereFila(par, valor);
        else
            insereFila(impar, valor);

        insereFila(filaAux, valor);
    }
    //Devolve os elementos de f
    while(!vaziaFila(filaAux))
        insereFila(f, retiraFila(filaAux));

    printf("\nImprimindo fila original\n");
    setColor(GREEN);
    imprimeFila(f);
    setColor(WHITE);
    printf("\nImprimindo fila par\n");
    setColor(CYAN);
    imprimeFila(par);
    setColor(WHITE);
    printf("\nImprimindo fila impar\n");
    setColor(CYAN);
    imprimeFila(impar);
    free(filaAux);
}

//}Exercicios da lista


//{Metodos basicos Pilha
TPilha *inicializaPilha(){
    TPilha *p = (TPilha*) malloc(sizeof(TPilha));
    p->prim = NULL;
    return p;
}

int pop(TPilha *p){
    if(vazia(p)) exit(1);
    int resp = p->prim->info;
    TNO *q = p->prim;
    p->prim = q->prox;
    free(q);
    return resp;
}
void push(TPilha *p, int elem){
    TNO *novo = (TNO*) malloc(sizeof(TNO));
    novo->info = elem;
    novo -> prox = p->prim;
    p->prim = novo;

}
int vazia (TPilha *p){
    return p->prim == NULL;
}

void libera(TPilha *p){
    TNO *q = p->prim, *t;
    while(q){
        t = q;
        q = q->prox;
        free(t);
    }
    free(p);
}

void imprimePilha(TPilha *p){
    if(vazia(p)) return;
    setColor(YELLOW);
    while(!vazia(p)){
        printf("\n%d", pop(p));
    }
    setColor(WHITE);
}


//}Metodos basicos Pilha

//{Metodos basicos Fila

void validaFilaVazia(TFila *f){
    if(vaziaFila(f)) {
        setColor(RED);
        printf("\nFila vazia! flw vlw...\n");
        setColor(WHITE);
        exit(1);
    }
}
TFila* inicializaFila(){
    TFila *f = (TFila*) malloc(sizeof(TFila));
    f->ini = f->fim = NULL;
    return f;
}
int vaziaFila(TFila *f){
    return f->ini == NULL;
}

void liberaFila(TFila *f){
    TNO *q = f->ini, *t;
    while(q){
        t = q;
        q = q->prox;
        free(t);
    }
    free(f);
}
TFila* insereFila(TFila *f, int elem){
    TNO *novo = (TNO*) malloc(sizeof(TNO));
    novo->info = elem;
    novo->prox = NULL;
    if(vaziaFila(f))
        f->ini = f->fim = novo;
    else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}
int retiraFila(TFila *f){
    if(vaziaFila(f)) exit(1);
    int resp = f->ini->info;
    TNO *q = f->ini;
    f->ini = f->ini->prox;
    if(!f->ini)
        f->fim = NULL;
    free(q);
    return resp;

}
void imprimeFila(TFila *f){
    if(vaziaFila(f)) return;
    setColor(GREEN);
    while(!vaziaFila(f))
        printf("\n%d", retiraFila(f));
    setColor(WHITE);
}
//}Metodos basicos Fila


int main()
{
    printf("Lista 6 da Rossetti!\n");
    printf("\nCriando a pilha...\n");
    TPilha *p = inicializaPilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    push(p, 4);
    push(p, 5);

    //Imprimindo a marvada
    printf("\nImprimindo a pilha...\n");
    imprimePilha(p);


    printf("\nCriando a fila principal...\n");
    TFila *f = inicializaFila();
    insereFila(f, 1);
    insereFila(f, 2);
    insereFila(f, 3);
    insereFila(f, 4);
    //printf("\nImprimindo a fila...\n");
    //imprimeFila(f);

    //{Questao a
    /*
    printf("\nQuestao a\n");
    TPilha *pp = f2p(f);
    imprimePilha(pp);
    */
    //}Questao a

    //{Questao b
    /*
    printf("\nQuestao b\n");
    TFila *fila = inv_fila(f);
    printf("\nImprimindo fila f\n");
    imprimeFila(f);
    printf("\nImprimindo fila invertida\n");
    imprimeFila(fila);
    */
    //}Questao b

    //{Questao c
    /*
    printf("\nQuestao c\n");
    TFila *filaPares = sep_fila(f);
    printf("\nImprimindo fila de elementos pares...\n");
    imprimeFila(filaPares);
    printf("\nImprimindo fila f resultando...");
    imprimeFila(f);
    */
    //}Questao c

    //{Questao d
    /*
    printf("\nTestando questao d\n");
    TFila *f1 = inicializaFila();
    TFila *f2 = inicializaFila();
    insereFila(f1, 1);
    insereFila(f1, 2);
    insereFila(f1, 3);
    insereFila(f2, 4);
    insereFila(f2, 5);
    insereFila(f2, 6);
    TFila *filaFinal = Junta_Filas(f1, f2);
    printf("\nImprimindo fila com conteudo de f1 e f2...\n");
    imprimeFila(filaFinal);
    printf("\nImprimindo somente f1...\n");
    imprimeFila(f1);
    */
    //}Questao d

    //{Questao e
    /*
    printf("\nTestando questao e\n");
    TPilha *pilhao = inicializaPilha();
    push(pilhao, 1);
    push(pilhao, 2);
    push(pilhao, 3);
    push(pilhao, 4);
    push(pilhao, 5);
    push(pilhao, 6);
    push(pilhao, 7);
    retira_pares(pilhao);
    */
    //}Questao e

    //{Questao f
    /*
    printf("\nTestando questao f\n");
    TPilha *pilhao = inicializaPilha();
    push(pilhao, 1);
    push(pilhao, 2);
    push(pilhao, 3);
    push(pilhao, 4);
    push(pilhao, 5);
    push(pilhao, 6);
    push(pilhao, 7);
    TFila *filao = p2f(pilhao);
    printf("\nImprimindo filao...\n");
    imprimeFila(filao);
    */
    //}Questao f

    //{Questao g
    TFila *par = inicializaFila();
    TFila *impar = inicializaFila();
    separa_filas(f, par, impar);
    //}Questao g

    getchar();
    return 0;
}
