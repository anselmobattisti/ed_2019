/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 05
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int info;
    struct Lista *prox;
}TLSE;
typedef struct aluno {
    int mat;
    float cr;
    struct aluno *prox;
}TAluno;

TLSE* insere_inicio_TLSE(TLSE *no,int valor);
TLSE* insere_fim_TLSE(TLSE *no,int valor);
TLSE* inicializar_TLSE();

void imprimir_alunos(TAluno *l){
    if(l){
        printf("Matricula: %d\n",l->mat);
        printf("CR: %.2f\n",l->cr);
        imprimir_alunos(l->prox);
    }
}
TAluno *copia (TAluno *l){
    TAluno *temp = (TAluno*)malloc(sizeof(TAluno));
    temp=l;
    return temp;
}
TAluno* insere_aluno_inicio(TAluno *no,int mat,float cr){
    TAluno *novo = (TAluno*)malloc(sizeof(TAluno));
    novo->mat=mat;
    novo->cr=cr;
    novo->prox=no;
    return novo;
}
void Q04(){
    TAluno *l = (TAluno*)malloc(sizeof(TAluno));
    l=inicializar_TLSE();
    l=insere_aluno_inicio(l,1001,7);
    l=insere_aluno_inicio(l,1002,8);
    imprimir_alunos(copia(l));
}

TLSE* desloca(TLSE* l, int n){
    TLSE *temp,*inicio,*fim=(TLSE*)malloc(sizeof(TLSE)),*no=(TLSE*)malloc(sizeof(TLSE));
    if(n%2==0){
        int valor=l->info;
        inicio=l->prox;
        temp=inicio;
        while(temp->prox)
            temp=temp->prox;
        fim->prox=NULL;
        fim->info=valor;
        temp->prox=fim;
        temp=inicio;
    } else {
        inicio=l;
        temp=inicio;
        while(temp->prox)
            temp=temp->prox;
        fim=temp;
        no->info=fim->info;
        no->prox=inicio;
        temp=inicio;
        while(fim!=temp->prox)
            temp=temp->prox;
        temp->prox=NULL;
        temp=no;
    }
    return temp;
}
void Q03(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,4);
    l = insere_inicio_TLSE(l,3);
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,1);
    l = desloca(l,1);
    printf("\nLista deslocada: ");
    imprimir(l);
}

TLSE* insere_fim_TLSE(TLSE *no,int valor){
    if(!no)
        return insere_inicio_TLSE(no,valor);
    TLSE *p=no,*temp=(TLSE*)malloc(sizeof(TLSE));
    temp->prox=NULL;
    temp->info=valor;
    while(p->prox)
        p=p->prox;
    p->prox=temp;
    return p;
}
TLSE* inverte2(TLSE *l){
    TLSE *temp = inicializar_TLSE();
    while(l){
        temp = insere_inicio_TLSE(temp,l->info);
        l = l->prox;
    }
    return temp;
}
void imprimir(TLSE *no){
    if(no){
        printf("%d ",no->info);
        imprimir(no->prox);
    }
}
void Q02(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,3);
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,1);
    TLSE *l2=(TLSE*)malloc(sizeof(TLSE));
    l2 = inverte2(l);
    imprimir(l2);
}

void inverte(TLSE* l){
    if(l->prox)
        inverte(l->prox);
    printf("%d ",l->info);
}
TLSE* insere_inicio_TLSE(TLSE *no,int valor){
    TLSE *temp=(TLSE*)malloc(sizeof(TLSE));
    if(!temp){
        temp->info=valor;
        temp->prox=NULL;
        return temp;
    } else {
        temp->prox=no;
        temp->info=valor;
        return temp;
    }
}
TLSE* inicializar_TLSE(){
    return NULL;
}
void Q01(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,3);
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,1);
    inverte(l);
}

int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 05 - 2019.1 - Flavio Miranda de Farias\n\n");
        printf("Digite o valor do menu a baixo\n\n");
        printf("1 - Exercicio 01\n");
        printf("2 - Exercicio 02\n");
        printf("3 - Exercicio 03\n");
        printf("4 - Exercicio 04\n");
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n");
        switch (op){
        case '1':
            printf("Considerando as seguintes declarações de lista encadeada:\ntypedef struct lista{\n\tint info;\n\tstruct lista *prox;\n}TLSE;\nEscreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O protótipo da função de inversão é o seguinte: void inverte (TLSE* l);");
            printf("\n\n");
            Q01();
            system("pause");
            break;
        case '2':
            printf("Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).");
            printf("\n\n");
            Q02();
            system("pause");
            break;
        case '3':
            printf("Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLSE* desloca (TLSE* l, int n).");
            printf("\n\n");
            Q03();
            system("pause");
            break;
        case '4':
            printf("Considere a existência de um tipo que representa um aluno numa universidade hipotética: \ntypedef struct aluno {\n\tint mat;\n\tfloat cr;\n\tstruct aluno *prox;\n}TAluno; Escreva uma função que copie uma lista. A lista original deve permanecer inalterada. O protótipo da função é o seguinte: TAluno *copia (TAluno *l).");
            printf("\n\n");
            Q04();
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
    //menu();
    Q04();
}
