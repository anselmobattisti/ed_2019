/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 05
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
    int info;
    struct Lista *prox;
}TLSE;
typedef struct aluno {
    int mat;
    float cr;
    struct aluno *prox;
}TAluno;
typedef struct lista{
    int mat;
    char nome[81];
    float cr;
    struct lista *prox;
}TLista;
typedef struct listas{
    int mat;
    char nome[81];
    float cr;
    struct listas *prox;
}TL;

TLSE* insere_inicio_TLSE(TLSE *no,int valor);
TLSE* inicializar_TLSE();
TAluno* insere_aluno_inicio(TAluno *no,int mat,float cr);
TLSE* insere_fim_recursivo_TLSE(TLSE *no,int valor);
TLista* insere_lista_inicio_TLista(TLista *l,int mat,char *nome,float cr);

TLSE* ordena(TLSE *no){
    if((!no)||(!no->prox))
        return;
    TLSE *p;
    for(p=no;p;p=p->prox){
        TLSE *q,*menor=p;
        for(q=p->prox;q;q=q->prox)
            if(menor->info > q->info)
                menor=q;
        if(menor!=p){
            int temporario=p->info;
            p->info=menor->info;
            menor->info=temporario;
        }
    }
    return no;
}
void Q11(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,3);
    l = insere_inicio_TLSE(l,10);
    l = insere_inicio_TLSE(l,5);
    l = insere_inicio_TLSE(l,9);
    l = insere_inicio_TLSE(l,8);
    l = insere_inicio_TLSE(l,1);
    imprimir(ordena(l));
}

TL* insere_lista_inicio_TL(TLista *l,int mat,char *nome,float cr){
    TL *temp=(TL*)malloc(sizeof(TL));
    temp->prox=l;
    temp->mat=mat;
    strcpy(temp->nome, nome);
    temp->cr=cr;
    return temp;
}
int Contrario (TL *l1, TL *l2){
    TL *novo=(TLSE*)malloc(sizeof(TL));
    novo = inicializar_TLSE();
    while(l1){
        novo=insere_lista_inicio_TL(novo,l1->mat,l1->nome,l1->cr);
        l1=l1->prox;
    }
    while(l2){
        if((novo->mat!=l2->mat)&&(novo->cr!=l2->cr)&&(strcmp(novo->nome,l2->nome)!=1))
            return 0;
        novo=novo->prox;
        l2=l2->prox;
    }
    return 1;
}
void imprimir_alunos_TL(TL *l){
    if(l){
        printf("Matricula: %d\n",l->mat);
        printf("Nome: %s\n",l->nome);
        printf("CR: %.2f\n",l->cr);
        imprimir_alunos_TL(l->prox);
    }
}
void Q10(){
    TL *l1=(TLSE*)malloc(sizeof(TL));
    TL *l2=(TLSE*)malloc(sizeof(TL));
    l1 = inicializar_TLSE();
    l2 = inicializar_TLSE();
    l1 = insere_lista_inicio_TL(l1,1001,"Flavio",7);
    l1 = insere_lista_inicio_TL(l1,1002,"Miranda",8);
    l2 = insere_lista_inicio_TL(l2,1002,"Miranda",8);
    l2 = insere_lista_inicio_TL(l2,1001,"Flavio",7);
    if(Contrario(l1,l2)==1)
        printf("Estao Invertidas!\n");
    else
        printf("Nao Estao Invertidas!\n");
}

TLSE* junta_listas (TLSE* l1, TLSE* l2){
    TLSE *novo=(TLSE*)malloc(sizeof(TLSE));
    novo=l1;
    while(l2){
        novo=insere_fim_recursivo_TLSE(novo,l2->info);
        l2=l2->prox;
    }
    return novo;
}
void Q09(){
    TLSE *l1=(TLSE*)malloc(sizeof(TLSE));
    TLSE *l2=(TLSE*)malloc(sizeof(TLSE));
    l1 = inicializar_TLSE();
    l2 = inicializar_TLSE();
    l1 = insere_inicio_TLSE(l1,3);
    l1 = insere_inicio_TLSE(l1,2);
    l1 = insere_inicio_TLSE(l1,1);
    l2 = insere_inicio_TLSE(l2,6);
    l2 = insere_inicio_TLSE(l2,5);
    l2 = insere_inicio_TLSE(l2,4);
    imprimir(junta_listas(l1,l2));
}

int igual(TLista *l1, TLista *l2){
    while(l1&&l2){
        if((l1->mat!=l2->mat)||(l1->cr!=l2->cr)||(strcmp(l1->nome,l2->nome)!=0))
           return 1;
        l1=l1->prox;
        l2=l2->prox;
    }
    if((l1==NULL)&&(l2==NULL))
        return 0;
    return 1;
}
TLista* insere_lista_inicio_TLista(TLista *l,int mat,char *nome,float cr){
    TLista *temp=(TLista*)malloc(sizeof(TLista));
    temp->prox=l;
    temp->mat=mat;
    strcpy(temp->nome, nome);
    temp->cr=cr;
    return temp;
}
void Q08(){
    TLSE *l1=(TLSE*)malloc(sizeof(TLSE));
    TLSE *l2=(TLSE*)malloc(sizeof(TLSE));
    l1 = inicializar_TLSE();
    l2 = inicializar_TLSE();
    l1 = insere_lista_inicio_TLista(l1,1001,"Flavio",7);
    l1 = insere_lista_inicio_TLista(l1,1002,"Miranda",8);
    l2 = insere_lista_inicio_TLista(l2,1001,"Flavio",7);
    l2 = insere_lista_inicio_TLista(l2,1002,"Miranda",8);
    if(igual(l1,l2)==0)
        printf("Iguais.\n");
    else
        printf("Diferentes.\n");
}

void* i_p2 ( TLSE *l){
    TLSE *pares,*impares,*novo;
    pares=inicializar_TLSE();
    impares=inicializar_TLSE();
    novo=inicializar_TLSE();
    while(l){
        if(l->info%2==0){
            pares=insere_fim_recursivo_TLSE(pares,l->info);
        } else {
            impares=insere_fim_recursivo_TLSE(impares,l->info);
        }
        l=l->prox;
    }
    int i=0;
    while(pares||impares){
        if(impares&&i==0){
            novo=insere_fim_recursivo_TLSE(novo,impares->info);
            impares=impares->prox;
        } else
            i=1;
        if(pares&&i==1){
            novo=insere_fim_recursivo_TLSE(novo,pares->info);
            pares=pares->prox;
        }
    }
    imprimir(novo);
}
void Q07(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,15);
    l = insere_inicio_TLSE(l,14);
    l = insere_inicio_TLSE(l,13);
    l = insere_inicio_TLSE(l,12);
    l = insere_inicio_TLSE(l,11);
    l = insere_inicio_TLSE(l,10);
    l = i_p2(l);
}

TLSE* i_p ( TLSE *l){
    TLSE *pares,*impares,*novo;
    pares=inicializar_TLSE();
    impares=inicializar_TLSE();
    novo=inicializar_TLSE();
    while(l){
        if(l->info%2==0){
            pares=insere_fim_recursivo_TLSE(pares,l->info);
        } else {
            impares=insere_fim_recursivo_TLSE(impares,l->info);
        }
        l=l->prox;
    }
    int i=0;
    while(pares||impares){
        if(impares&&i==0){
            novo=insere_fim_recursivo_TLSE(novo,impares->info);
            impares=impares->prox;
        } else
            i=1;
        if(pares&&i==1){
            novo=insere_fim_recursivo_TLSE(novo,pares->info);
            pares=pares->prox;
        }
    }
    return novo;
}
void Q06(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,6);
    l = insere_inicio_TLSE(l,5);
    l = insere_inicio_TLSE(l,4);
    l = insere_inicio_TLSE(l,3);
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,1);
    l = i_p(l);
    imprimir(l);
}

TLSE* insere_fim_recursivo_TLSE(TLSE *no,int valor){
    if(!no)
        return insere_inicio_TLSE(no,valor);
    no->prox=insere_fim_recursivo_TLSE(no->prox,valor);
    return no;
}
TLSE* rto (TLSE* l, int elem){
    TLSE *novo=(TLSE*)malloc(sizeof(TLSE));
    novo=inicializar_TLSE();
    while(l->prox){
        if(l->info!=elem)
            novo=insere_fim_recursivo_TLSE(novo,l->info);
        l=l->prox;
    }
    return novo;
}
void Q05(){
    TLSE *l=(TLSE*)malloc(sizeof(TLSE));
    l = inicializar_TLSE();
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,5);
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,3);
    l = insere_inicio_TLSE(l,2);
    l = insere_inicio_TLSE(l,1);
    l = rto(l,2);
    imprimir(l);
}

void imprimir_alunos(TAluno *l){
    if(l){
        printf("Matricula: %d\n",l->mat);
        printf("CR: %.2f\n",l->cr);
        imprimir_alunos(l->prox);
    }
}
TAluno *copia (TAluno *l){
    TAluno *temp=inicializar_TLSE();
    while(l){
        temp=insere_aluno_inicio(temp,l->mat,l->cr);
        l=l->prox;
    }
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
    imprimir(l);
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
        printf("5 - Exercicio 05\n");
        printf("6 - Exercicio 06\n");
        printf("7 - Exercicio 07\n");
        printf("8 - Exercicio 08\n");
        printf("9 - Exercicio 09\n");
        printf("a - Exercicio 10\n");
        printf("b - Exercicio 11\n");
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
        case '5':
            printf("Considerando a definição de lista de Q1, escreva uma função em C que remova todas as ocorrências de um elemento numa lista. Seu protótipo O protótipo desta função é o seguinte: TLSE* rto (TLSE* l, int elem).");
            printf("\n\n");
            Q05();
            system("pause");
            break;
        case '6':
            printf("Considerando a definição de lista de Q1, escreva uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída, os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos aparecem em l. Ao final da execução desta função, a lista resultante terá todos os elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função é o seguinte: TLSE* i_p ( TLSE *l).");
            printf("\n\n");
            Q06();
            system("pause");
            break;
        case '7':
            printf("Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o seguinte: void* i_p ( TLSE *l).");
            printf("\n\n");
            Q07();
            system("pause");
            break;
        case '8':
            printf("Considerando as seguintes declarações de uma lista encadeada:\ntypedef struct lista{\n\tint mat;\n\tchar nome[81];\n\tfloat cr;\n\tstruct lista *prox;\n}TLista;\nEscreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 e l2são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se aslistas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual(TLista *l1, TLista *l2).\nOBS: protótipo de função que pode ser útil: int strcmp (char *s, char *t).");
            printf("\n\n");
            Q08();
            system("pause");
            break;
        case '9':
            printf("Considerando a definição de lista de Q1, escreva uma função em C que, dadas duas listas, faça a concatenação das mesmas ao final de l1. O protótipo da função é o seguinte: TLSE* junta_listas (TLSE* l1, TLSE* l2).");
            printf("\n\n");
            Q09();
            system("pause");
            break;
        case 'a':
            printf("Considerando a seguinte declaração de uma lista encadeada:\ntypedef struct lista{\n\tint mat;\n\tchar nome[81];\n\tfloat cr;\n\tstruct lista *prox; \n}TL;\nEscreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1 é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int Contrario (TL *l1, TL *l2).");
            printf("\n\n");
            Q10();
            system("pause");
            break;
        case 'b':
            printf("Considerando a declaração da Q1, escreva uma função em C que, dada uma lista l qualquer, ordene os elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O protótipo da função desta função é o seguinte: TLSE * ordena (TLSE* l).");
            printf("\n\n");
            Q11();
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
