/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 06
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nop{
    int info;
    struct nop *prox;
}TNOP;
typedef struct pilha{
    TNOP *primeiro;
}TPilha;
typedef struct nof{
    int inf;
    struct nof *proxi;
}TNOF;
typedef struct fila{
    TNOF *ini,*fim;
}TFila;

//inicio da estrutura de pilha
TPilha * inicializa (void){
    TPilha *p = (TPilha*)malloc(sizeof(TPilha));
    p->primeiro=NULL;
    return p;
}
void push (TPilha *p, int elem){
    TNOP *novo=(TNOP*)malloc(sizeof(TNOP));
    novo->info=elem;
    novo->prox=p->primeiro;
    p->primeiro=novo;
}
int pop (TPilha *p){
    if(vazia(p))
        exit(1);
    int valor=p->primeiro->info;
    TNOP *temp=p->primeiro;
    p->primeiro=p->primeiro->prox;
    free(temp);
    return valor;
}
void libera (TPilha *p){
    TPilha *temp;
    while(!vazia(p)){
        temp=p;
        free(temp);
        p->primeiro=p->primeiro->prox;
    }
    free(p);
}
int vazia (TPilha *p){
    return p->primeiro==NULL;
}
//inicio da estrutura de fila
TFila* inicializaF (void){
    TFila *novo=(TFila*)malloc(sizeof(TFila));
    novo->ini=novo->fim=NULL;
    return novo;
}
TFila* insere (TFila *f, int elem){
    TNOF *novo=(TNOF*)malloc(sizeof(TNOF));
    novo->inf=elem;
    novo->proxi=NULL;
    if(vaziaF(f))
        f->ini=f->fim=novo;
    else{
        f->fim->proxi=novo;
        f->fim=novo;
    }
}
int retira (TFila *f){
    if(vaziaF())
        exit(1);
    int valor=f->ini->inf;
    TNOF *temp=f->ini;
    f->ini=f->ini->proxi;
    if(!f->ini)
        f->fim=NULL;
    free(temp);
    return valor;
}
void liberaF (TFila *f){
    TNOF *temp;
    while(f){
        temp=f->ini;
        f->ini=f->ini->proxi;
        free(temp);
    }
    free(f);
}
int vaziaF (TFila *f){
    return f->ini==NULL;
}
//fim das bibliotecas

void separa_filas(TFila * f, TFila *par, TFila * impar){
    TFila *fila=inicializa();
    int i;
    while(!vaziaF(f)){
        i=retira(f);
        if((i%2)==1)
            par=insere(par,i);
        else
            impar=insere(impar,i);
        fila=insere(fila,i);
    }
    while(!vaziaF(fila))
        f=insere(f,retira(fila));
}
void Qg(){
    TFila *f=inicializaF(),*par=inicializaF(),*impar=inicializaF();
    f=insere(f,1);
    f=insere(f,2);
    f=insere(f,3);
    f=insere(f,4);
    separa_filas(f,par,impar);
    printf("Todos: ");
    while(!vaziaF(f))
        printf("%d ",retira(f));
    printf("\nImpares: ");
    while(!vaziaF(impar))
        printf("%d ",retira(impar));
    printf("\nPares: ");
    while(!vaziaF(par))
        printf("%d ",retira(par));
}

TFila* p2f (TPilha *p){
    TPilha *p1=p,*p2=inicializa();
    TFila *f=inicializaF();
    while(!vazia(p1))
        push(p2,pop(p1));
    while(!vazia(p2))
        f=insere(f,pop(p2));
    return f;
}
void Qf(){
    TPilha *p=inicializa();
    push(p,1);
    push(p,2);
    push(p,3);
    push(p,4);
    TFila *f=p2f(p);
    while(!vaziaF(f))
        printf("%d ",retira(f));
}

void retira_pares (TPilha *p){
    TPilha *p2=inicializa();
    int i;
    while(!vazia(p))
        push(p2,pop(p));
    while(!vazia(p2)){
        i=pop(p2);
        if((i%2)==1)
            push(p,i);
    }
}
void Qe(){
    TPilha *p=inicializa();
    push(p,1);
    push(p,2);
    push(p,3);
    push(p,4);
    retira_pares(p);
    while(!vazia(p))
        printf("%d ",pop(p));
}

TFila* Junta_Filas (TFila *f1, TFila *f2){
    TFila *fa=f1,*fb=f2,*fc=inicializaF();
    while(!vaziaF(fa))
        fc=insere(fc,retira(fa));
    while(!vaziaF(fb))
        fc=insere(fc,retira(fb));
    return fc;
}
void Qd(){
    TFila *f1=inicializaF(),*f2=inicializaF(),*f3;
    f1=insere(f1,1);
    f1=insere(f1,2);
    f2=insere(f2,3);
    f2=insere(f2,4);
    f3=Junta_Filas(f1,f2);
    while(!vaziaF(f3))
        printf("%d ",retira(f3));
}

TFila* sep_fila (TFila *f){
    TFila *fPar=inicializaF(),*fImpar=inicializaF();
    int i;
    while(!vaziaF(f)){
        i=retira(f);
        if((i%2)==0)
            fPar=insere(fPar,i);
        else
            fImpar=insere(fImpar,i);
    }
    while(!vaziaF(fImpar))
        f=insere(f,retira(fImpar));
    return fPar;
}
void Qc(){
    TFila *f1=inicializaF(),*f2;
    f1=insere(f1,1);
    f1=insere(f1,2);
    f1=insere(f1,3);
    f1=insere(f1,4);
    f2=sep_fila(f1);
    printf("Impares: ");
    while(!vaziaF(f1))
        printf("%d ",retira(f1));
    printf("\nPares: ");
    while(!vaziaF(f2))
        printf("%d ",retira(f2));
}

TFila* inv_fila (TFila *f){
    TPilha *p=inicializa();
    TFila *f2=inicializaF();
    while(!vaziaF(f))
        push(p,retira(f));
    while(!vazia(p))
        insere(f2,pop(p));
    return f2;
}
void Qb(){
    TFila *f=inicializaF(),*f2;
    f=insere(f,1);
    f=insere(f,2);
    f=insere(f,3);
    f2=inv_fila(f);
    while(!vaziaF(f2))
        printf("%d ",pop(f2));
}

TPilha* f2p (TFila *f){
    TPilha *p1=inicializa(),*p2=inicializa();
    while(!vaziaF(f))
        push(p1,retira(f));
    while(!vazia(p1))
        push(p2,pop(p1));
    return p2;
}
void Qa(){
    TFila *f=inicializaF();
    f=insere(f,1);
    f=insere(f,2);
    f=insere(f,3);
    TPilha *p = f2p(f);
    while(!vazia(p))
        printf("%d ",pop(p));
}

int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 06 - 2019.1 - Flavio Miranda de Farias\n\n");
        printf("Digite o valor do menu a baixo\n\n");
        printf("a - Exercicio A\n");
        printf("b - Exercicio B\n");
        printf("c - Exercicio C\n");
        printf("d - Exercicio D\n");
        printf("e - Exercicio E\n");
        printf("f - Exercicio F\n");
        printf("g - Exercicio G\n");
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n");
        switch (op){
        case 'a':
            printf("(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);");
            printf("\n\n");
            Qa();
            system("pause");
            break;
        case 'b':
            printf("(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f, porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);");
            printf("\n\n");
            Qb();
            system("pause");
            break;
        case 'c':
            printf("(c) uma função que, dada uma fila f, retorne uma nova fila contendo os elementos pares de f, e modifique a fila original (f) para que ela possua somente os elementos ímpares, respeitando a ordem de entrada em f. A função deve obedecer o seguinte protótipo: TFila* sep_fila (TFila *f);");
            printf("\n\n");
            Qc();
            system("pause");
            break;
        case 'd':
            printf("(d) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);");
            printf("\n\n");
            Qd();
            system("pause");
            break;
        case 'e':
            printf("(e) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha. A função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);");
            printf("\n\n");
            Qe();
            system("pause");
            break;
        case 'f':
            printf("(f) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p);");
            printf("\n\n");
            Qf();
            system("pause");
            break;
        case 'g':
            printf("(g) implemente uma função que receba três filas, f, impares e pares, e separe todos os valores guardados em f de tal forma que os valores pares são colocados na fila pares e os valores ímpares na impares. Ao final da execução desta função, f permanecerá com todos os seus elementos. O protótipo desta função é o seguinte: void separa_filas(TFila * f, TFila *par, TFila * impar).");
            printf("\n\n");
            Qg();
            system("pause");
            break;
        default:
            printf("Finalizando sistema... Tchau!\n");
            return 0;
            break;
        }
    }
}
void main(){
    menu();
}
