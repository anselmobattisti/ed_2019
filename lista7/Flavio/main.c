/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 07
*/
#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct ab{
    int info;
    int corr;
    struct ab *esqu, *dire;
}TAB;
typedef struct abb{
    int inf;
    int cor;
    struct abb *esq,*dir;
}TABB;

TAB* busca(TAB *a,int x);
TABB* copiaBB(TABB *a);
TAB *cria_no(int valor);
TABB* cria_noBB(int x);
TAB *espelho(TAB *a);
TABB* espelhoBB(TABB *t);
TABB* maiorBB(TABB *t);
TABB* menorBB(TABB *t);
TABB* retiraBB(TABB *a,int x);

//Início de Árvore Binária
TAB* inicializa(){
    return NULL;
}
TAB* busca(TAB *a,int x){
    if((!a)||(a->info==x))
        return a;
    TAB *esquerda=busca(a->esqu,x);
    if(esquerda)
        return esquerda;
    return busca(a->dire,x);
}
void libera(TAB *a){
    if(a){
        libera(a->esqu);
        libera(a->dire);
        free(a);
    }
}
void print2DUtilGen(TAB *root, int space){
    if (!root)
        return;
    space += 2;
    print2DUtilGen(root->esqu, space);
    for (int i = 3; i < space; i++)
        printf(" -");
    printf(">%d\n", root->info);
    print2DUtilGen(root->dire, space);
}
void imp_pre(TAB *a){
    if(a){
        printf("%d ",a->info);
        imp_pre(a->esqu);
        imp_pre(a->dire);
    }
}
void imp_pos(TAB *a){
    if(a){
        imp_pos(a->esqu);
        imp_pos(a->dire);
        printf("%d ",a->info);
    }
}
void imp_simetrico(TAB *a){
    if(a){
        imp_simetrico(a->esqu);
        printf("%d ",a->info);
        imp_simetrico(a->dire);
    }
}
int maior(TAB *a){
    if(!a)
        return INT_MIN;
    int maior_esq=maior(a->esqu),maior_dir=maior(a->dire),resp=a->info;
    if(maior_esq>resp)
        resp=maior_esq;
    if(maior_dir>resp)
        resp=maior_dir;
    return resp;
}
int menor(TAB *a){
    if(!a)
        return INT_MAX;
    int menor_esq=menor(a->esqu),menor_dir=menor(a->dire),resp=a->info;
    if(menor_esq<resp)
        resp=menor_esq;
    if(menor_dir<resp)
        resp=menor_dir;
    return resp;
}
int altura(TAB* t){
    if(!t->esqu && !t->dire)
        return 0;
    int a_esq=0,a_dir=0;
    if(t->esqu)
        a_esq = altura(t->esqu)+1;
    if(t->dire)
        a_dir = altura(t->dire)+1;
    if(a_esq > a_dir)
        return a_esq;
    else
        return a_dir;
}
TAB *insere(TAB *a, int valor){
    if(!a)
        return cria_no(valor);
    if(valor<a->info)
        a->esqu = insere(a->esqu,valor);
    if(valor>a->info)
        a->dire =  insere(a->dire,valor);
    return a;
}
TAB *cria_no(int valor){
    TAB *novo=(TAB*)malloc(sizeof(TAB));
    novo->info=valor;
    novo->esqu=NULL;
    novo->dire=NULL;
    return novo;
}
TAB *copia(TAB *a){
    if(!a || (!a->esqu && !a->dire))
        return a;
    TAB *b=cria_no(a->info);
    b->esqu = copia(a->esqu);
    b->dire = copia(a->dire);
    return b;
}
TAB *espelho(TAB *a){
    if(!a || (!a->esqu && !a->dire))
        return a;
    TAB *b=cria_no(a->info);
    if(a->esqu)
        b->dire=espelho(a->esqu);
    if(a->dire)
        b->esqu=espelho(a->dire);
    return b;
}
int igual(TAB* a, TAB* b){
    if(!a && !b)
        return 0;
    if((!a && b) || (!a && b))
        return 1;
    if(a->info != b->info)
        return 1;
    igual(a->esqu,b->esqu);
    igual(a->dire,b->dire);
    return 0;
}
TAB* retira(TAB *a,int x){
    if(!a)
        return a;
    if(a->info<x)
        a->dire=retira(a->dire,x);
    else
        if(a->info>x)
            a->esqu=retira(a->esqu,x);
        else { //achou!!!
            if((!a->esqu)&&(!a->dire)){//não tem filhos
                free(a);
                return NULL;
            }
            if((!a->esqu)||(!a->dire)){//tem 1 filho
                TAB *folha;
                if(!a->esqu)
                    folha=a->dire;
                else
                    folha=a->esqu;
                free(a);
                return folha;
            } else { //tem os 2 filhos
                TAB *folha=a->esqu;
                while(folha->dire)
                    folha=folha->dire;
                a->info=folha->info;
                folha->info=x;
                a->esqu=retira(a->esqu,x);
            }
        }
        return a;
}
TAB* retira_pares(TAB* a){
    if(a){
        a->esqu=retira_pares(a->esqu);
        a->dire=retira_pares(a->dire);
        if((a->info%2)==0){
            a = retira(a,a->info);
        }
    }
    return a;
}
int imprime_pre_ordem(TAB *arvore){
   int a=1,b=1;
   if(arvore != NULL){
      printf("(");
      printf("%d",arvore->info);
      a=imprime_pre_ordem(arvore->esqu);///a==0 caso sub_arvore_esquerda==NULL
      b=imprime_pre_ordem(arvore->dire);///a==0 caso sub_arvore_direita==NULL
      if(b==0 && a==0)
        printf("()");///imprime  () se e somente se encontrar um nó folha
      else
        if(b==0 && a!=0)
            printf("*>");///isso acontece se encontrar um nó com a perna direita null
      else
        if(b!=0 && a==0)
            printf("*<");///isso acontece se encontrar um nó com a perna esquerda null
      printf(")");///fecha a representação de uma raiz
   } else
        return 0;
    return 0;
}
int contagem(TAB* a) {
    return (a != NULL) ? (contagem(a->esqu) + contagem(a->dire) + 1) : 0;
}
int nos_internos(TAB *a){
    if(!a || (!a->esqu && !a->dire)) return 0;
    else return 1 + (nos_internos(a->esqu) + nos_internos(a->dire));
}
int nos_folha(TAB *a){
    if(!a) return 0;
    if(!a->esqu && !a->dire) return 1;
    return nos_folha(a->esqu) + nos_folha(a->dire);
}
//Fim de Árvore Binária
//Inicio de Árvore de Busca Binária
TABB* inicializaBB(){
    return NULL;
}
void imp_preBB(TABB *a){
    if(a){
        printf("%d ",a->inf);
        imp_preBB(a->esq);
        imp_preBB(a->dir);
    }
}
void imp_posBB(TABB *a){
    if(a){
        imp_posBB(a->esq);
        imp_posBB(a->dir);
        printf("%d ",a->inf);
    }
}
void imp_simetricoBB(TABB *a){
    if(a){
        imp_simetricoBB(a->esq);
        printf("%d ",a->inf);
        imp_simetricoBB(a->dir);
    }
}
int maior_iterativoBB(TABB *a){
    if(!a)
        return INT_MIN;
    TABB *p=a;
    while(p->dir)
        p=p->dir;
    return p->inf;
}
int maiorBB2(TABB *a){
    if(!a)
        return INT_MIN;
    if(!a->dir)
        return a->inf;
    return maiorBB2(a->dir);
}
TABB* maiorBB(TABB *a){
    if(!a)
        return a;
    if(!a->dir)
        return a;
    return maiorBB(a->dir);
}
int menorBB2(TABB *a){
    if(!a)
        return INT_MIN;
    if(!a->esq)
        return a->inf;
    return menorBB2(a->esq);
}
TABB* menorBB(TABB *a){
    if(!a)
        return a;
    if(!a->esq)
        return a;
    return menorBB(a->esq);
}
TABB* cria_noBB(int x) {
      TABB* aux = (TABB*)malloc(sizeof(TABB));
      aux->inf = x;
      aux->esq = NULL;
      aux->dir = NULL;
      return aux;
}
TABB* copiaBB(TABB *a){
    if(a){
        TABB* aux = cria_noBB(a->inf);
        aux->esq = copiaBB(a->esq);
        aux->dir = copiaBB(a->dir);
        return aux;
    }else
        return NULL;
}
TABB *buscaBB(TABB *a,int x){
    if((!a)||(a->inf==x))
        return a;
    if(a->inf>x)
        return buscaBB(a->esq,x);
    return buscaBB(a->dir,x);
}
int igualBB(TABB* a1, TABB* a2){
    if(!a1 || !a2) return 0;
    if(!a1->esq && a2->esq) return 1;
    if(!a1->dir && a2->dir) return 1;
    if(a1->esq && !a2->esq) return 1;
    if(a1->dir && !a2->dir) return 1;
    if(a1->inf != a2->inf) return 1;
    return igualBB(a1->esq,a2->esq)+igualBB(a1->dir,a2->dir);
}
TABB* espelhoBB(TABB *t){
    if(t){
        if(!t->esq && !t->dir)
            return t;
        TABB* aux_e = t->esq;
        t->esq = t->dir;
        t->dir = aux_e;
        t->esq = espelhoBB(t->esq);
        t->dir = espelhoBB(t->dir);
        return t;
    }else
        return NULL;
}
TABB* insereBB(TABB *a,int x){
    if(!a){
        TABB *a=(TABB*)malloc(sizeof(TABB));
        a->inf=x;
        a->esq=a->dir=NULL;
        return a;
    }
    if(a->inf>x)
        a->esq=insereBB(a->esq,x);
    else
        if(a->inf<x)
            a->dir=insereBB(a->dir,x);
    return a;
}
void liberaBB(TABB *a){
    if(a){
        liberaBB(a->esq);
        liberaBB(a->dir);
        free(a);
    }
}
TABB* retira_paresBB(TABB* a){
    if(a){
        if((a->inf%2)==0){
            a = retiraBB(a,a->inf);
            a->esq = retira_paresBB(a->esq);
            a->dir = retira_paresBB(a->dir);
            return a;
        } else{
            a->esq = retira_paresBB(a->esq);
            a->dir = retira_paresBB(a->dir);
            return a;
        }

    } else
        return NULL;
}
TABB* retiraBB(TABB *a,int x){
    if(!a)
        return a;
    if(a->inf<x)
        a->dir=retiraBB(a->dir,x);
    else
        if(a->inf>x)
            a->esq=retiraBB(a->esq,x);
        else { //achou!!!
            if((!a->esq)&&(!a->dir)){//não tem filhos
                free(a);
                return NULL;
            }
            if((!a->esq)||(!a->dir)){//tem 1 filho
                TABB *folha;
                if(!a->esq)
                    folha=a->dir;
                else
                    folha=a->esq;
                free(a);
                return folha;
            } else { //tem os 2 filhos
                TABB *folha=a->esq;
                while(folha->dir)
                    folha=folha->dir;
                a->inf=folha->inf;
                folha->inf=x;
                a->esq=retiraBB(a->esq,x);
            }
        }
        return a;
}
int buscaBB2(TABB* a, int c) {
    if (!a)
        return 0; /* árvore vazia*/
    else
        return a->inf == c || buscaBB2(a->esq, c) || buscaBB2(a->dir,c);
}
int contagemBB(TABB* a) {
    return (a != NULL) ? (contagemBB(a->esq) + contagemBB(a->dir) + 1) : 0;
}
int nos_internosBB(TABB *a){
    if(!a || (!a->esq && !a->dir)) return 0;
    else return 1 + (nos_internosBB(a->esq) + nos_internosBB(a->dir));
}
int nos_folhaBB(TABB *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1;
    return nos_folhaBB(a->esq) + nos_folhaBB(a->dir);
}
int imprime_pre_ordemBB(TABB *arvore){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela direita
   int a=1,b=1;
   if(arvore != NULL){
      printf("(");
      printf("%d",arvore->inf);
      a=imprime_pre_ordemBB(arvore->esq);///a==0 caso sub_arvore_esquerda==NULL
      b=imprime_pre_ordemBB(arvore->dir);///a==0 caso sub_arvore_direita==NULL
      if(b==0 && a==0)printf("()");///imprime  () se e somente se encontrar um nó folha
      else if(b==0 && a!=0);///isso acontece se encontrar um nó com a perna direita null
      else if(b!=0 && a==0);///isso acontece se encontrar um nó com a perna esquerda null
      /**         Observações:
      Existem tambem mais dois casos:
         1°- Para imprimir quando a perna direita ou esquerda for null ou seja quando as raizes da arvore não estiverem completas basta retirar a condição da linha 50 (obs:só imprimira as "pernas" vazias)e atualizar o resto assim:
         if(b==0 && a!=0)printf("()");
         if(b!=0 && a==0)printf("()");
         2°- Para imprimir quando a perna direita ou esquerda for null ou as duas basta retirar a condição da linha 50,51,52 e fazer uma condição para cada assim:
         if(b==0)printf("()");
         if(a==0)printf("()");
      That's All Folks! (É só isso pessoal!)
      **/
      printf(")");///fecha a representação de uma raiz
   }else return 0;//retorna 0 caso arvore == NULL
   return 0;
}
//Fim de Árvore de Busca Binária

//exercicios de Arvore Binaria Simples
void Q09B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,8);
    a = insere(a,7);
    imprime_pre_ordem(a);
    printf("\n");
    print2DUtilGen(a,0);
    printf("\nSao %d nos folhas\n",nos_folha(a));
    printf("\nSao %d nos no total\n",contagem(a));
}
void Q08B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,8);
    a = insere(a,9);
    imprime_pre_ordem(a);
    printf("\n");
    print2DUtilGen(a,0);
    printf("\nSao %d nos internos\n",nos_internos(a));
    printf("\nSao %d nos no total\n",contagem(a));
}
void imprime_pre_cores(TAB *a, int espaco){
    if (!a)
        return;
    espaco += 2;
    imprime_pre_cores(a->esqu, espaco);
    for(int i = 3; i < espaco; i++)
        printf(" -");
    if(a->corr==0)
        printf(">VERMELHO\n");
    else
        if(a->corr==1)
            printf(">PRETO\n");
        else
            printf(">SEM COR\n");
    imprime_pre_cores(a->dire, espaco);
}
void colore(TAB* a){
    if(a){
        if(a->corr==0){
            if(a->esqu && a->esqu->corr==0)
                a->esqu->corr = 1;
            if(a->dire && a->dire->corr==0)
                a->dire->corr = 1;
        }
        if(a->corr==1){
            if(a->esqu && a->esqu->corr==1)
                a->esqu->corr = 0;
            if(a->dire && a->dire->corr==1)
                a->dire->corr = 0;
        }
        colore(a->esqu);
        colore(a->dire);
    }
}
void Q07B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,6);
    a = insere(a,2);
    a = insere(a,5);
    a = insere(a,4);
    print2DUtilGen(a,0);
    printf("\n");
    colore(a);
    imprime_pre_cores(a,0);
    printf("\n");
}
void Q06B(){
    TAB *a = inicializa();
    a = insere(a,0);
    a = insere(a,4);
    a = insere(a,1);
    a = insere(a,3);
    a = insere(a,2);
    a = insere(a,5);
    print2DUtilGen(a,0);
    printf("\n");
    a = retira_pares(a);
    print2DUtilGen(a,0);
    printf("\n");
}
void Q05B(){
    TAB *a = inicializa();
    a = insere(a,2);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,3);
    TAB *b = inicializa();
    b = insere(b,2);
    b = insere(b,0);
    b = insere(b,1);
    b = insere(b,3);
    print2DUtilGen(a,0);
    printf("\n");
    print2DUtilGen(b,0);
    printf("\n");
    if(igual(a,b)==0)
        printf("\nIGUAIS\n");
    else
        printf("\nDIFERENTES\n");
}
void Q04B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,8);
    a = insere(a,9);
    print2DUtilGen(a,0);
    printf("\n%d\n",menor(a));
}
void Q03B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,8);
    a = insere(a,9);
    print2DUtilGen(a,0);
    printf("\n%d\n",maior(a));
}
void Q02B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,8);
    a = insere(a,9);
    print2DUtilGen(a,0);
    imp_pre(a);
    printf("\n");
    imprime_pre_ordem(a);
    printf("\n");
    TAB *b = inicializa();
    b = espelho(a);
    imp_pre(b);
    printf("\n");
    imprime_pre_ordem(b);
    printf("\n");
    print2DUtilGen(b,0);
    printf("\n");
}
void Q01B(){
    TAB *a = inicializa();
    a = insere(a,3);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,2);
    a = insere(a,4);
    a = insere(a,5);
    imp_pre(a);
    printf("\n");
    imprime_pre_ordem(a);
    printf("\n");
    TAB *b = inicializa();
    b = copia(a);
    imp_pre(b);
    printf("\n");
}
//exercicios de Arvore Busca Binaria
void Q09BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,3);
    a = insereBB(a,0);
    a = insereBB(a,8);
    a = insereBB(a,7);
    imprime_pre_ordemBB(a);
    printf("\nSao %d nos folhas ",nos_folhaBB(a));
    printf("\nSao %d nos no total ",contagemBB(a));
}
void Q08BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,3);
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,8);
    a = insereBB(a,9);
    imprime_pre_ordemBB(a);
    printf("\nSao %d nos internos ",nos_internosBB(a));
    printf("\nSao %d nos no total ",contagemBB(a));
}
int imprime_pre_coresBB(TABB *arvore){
    int a=1,b=1;
    if(arvore != NULL){
        printf("(");
        if(arvore->cor==0) printf("VERMELHO ");
        else printf("PRETO ");
        a=imprime_pre_coresBB(arvore->esq);///a==0 caso sub_arvore_esquerda==NULL
        b=imprime_pre_coresBB(arvore->dir);///a==0 caso sub_arvore_direita==NULL
        if(b==0 && a==0) printf("()");///imprime  () se e somente se encontrar um nó folha
        else if(b==0 && a!=0);///isso acontece se encontrar um nó com a perna direita null
        else if(b!=0 && a==0);///isso acontece se encontrar um nó com a perna esquerda null
        printf(")");
    } else return 0;
    return 0;
}
void coloreBB(TABB* a){
    if(a){
        if(a->cor==0){
            if(a->esq && a->esq->cor==0)
                a->esq->cor = 1;
            if(a->dir && a->dir->cor==0)
                a->dir->cor = 1;
        }
        if(a->cor==1){
            if(a->esq && a->esq->cor==1)
                a->esq->cor = 0;
            if(a->dir && a->dir->cor==1)
                a->dir->cor = 0;
        }
        coloreBB(a->esq);
        coloreBB(a->dir);
    }
}
void Q07BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,3);
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,6);
    a = insereBB(a,2);
    a = insereBB(a,5);
    a = insereBB(a,4);
    imp_preBB(a);
    printf("\n");
    imprime_pre_ordemBB(a);
    printf("\n");
    coloreBB(a);
    imprime_pre_coresBB(a);
}
void Q06BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,2);
    a = insereBB(a,3);
    a = insereBB(a,4);
    a = insereBB(a,5);
    imp_simetricoBB(a);
    printf("\n");
    TABB *b = inicializaBB();
    b = retira_paresBB(a);
    imp_simetricoBB(b);
}
void Q05BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,2);
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,3);
    TABB *b = inicializaBB();
    b = insereBB(b,2);
    b = insereBB(b,0);
    b = insereBB(b,1);
    b = insereBB(b,3);
    imprime_pre_ordemBB(a);
    printf("\n");
    imprime_pre_ordemBB(b);
    printf("\n");
    if(igualBB(a,b)==0)
        printf("\nIGUAIS\n");
    else
        printf("\nDIFERENTES\n");
}
void Q04BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,2);
    a = insereBB(a,3);
    imp_simetricoBB(a);
    printf("\n%d\n",menorBB2(a));
}
void Q03BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,2);
    a = insereBB(a,3);
    imp_simetricoBB(a);
    printf("\n%d\n",maiorBB(a)->inf);
}
void Q02BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,3);
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,2);
    a = insereBB(a,4);
    a = insereBB(a,5);
    imp_preBB(a);
    printf("\n");
    imprime_pre_ordemBB(a);
    printf("\n");
    TABB *b = inicializaBB();
    b = espelhoBB(a);
    imp_preBB(b);
    printf("\n");
    imprime_pre_ordemBB(a);
}
void Q01BB(){
    TABB *a = inicializaBB();
    a = insereBB(a,3);
    a = insereBB(a,0);
    a = insereBB(a,1);
    a = insereBB(a,2);
    a = insereBB(a,4);
    a = insereBB(a,5);
    imp_preBB(a);
    printf("\n");
    imprime_pre_ordemBB(a);
    printf("\n");
    TABB *b = inicializaBB();
    b = copiaBB(a);
    imp_preBB(b);
}

int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 07 - 2019.1 - Flavio Miranda de Farias\n\n");
        printf("Relacionado a Arvore Binária de Simples\n\n");
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
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n");
        switch (op){
        case '1':
            printf("Cópia de uma árvore: TAB* copia (TAB *a);");
            printf("\n\n");
            Q01B();
            system("pause");
            break;
        case '2':
            printf("Espelho de uma árvore (o que está a esquerda na árvore original, estará a direita no espelho, e vice-versa): TAB* espelho (TAB *a);");
            printf("\n\n");
            Q02B();
            system("pause");
            break;
        case '3':
            printf("Maior elemento da árvore: TAB* maior(TAB *a);");
            printf("\n\n");
            Q03B();
            system("pause");
            break;
        case '4':
            printf("menor elemento da árvore: TAB* menor(TAB *a);");
            printf("\n\n");
            Q04B();
            system("pause");
            break;
        case '5':
            printf("uma função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A função retorna um se elas são iguais e zero, caso contrário. A função deve obedecer ao seguinte protótipo: int igual (TAB* a1, TAB* a2);");
            printf("\n\n");
            Q05B();
            system("pause");
            break;
        case '6':
            printf("uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* arv);");
            printf("\n\n");
            Q06B();
            system("pause");
            break;
        case '7':
            printf("se esta estrutura TAB tivesse um campo cor (int cor), defina uma função em C que, ao receber uma árvore binária “sem cor” e totalmente balanceada (isto é, a distância da raiz a qualquer folha da árvore é sempre a mesma), retorne esta árvore com os nós coloridos somente de vermelho e preto, sendo que o nó pai NUNCA pode ter a mesma cor de seus filhos. A função deve possuir o seguinte protótipo: void colore (TAB* arv);");
            printf("\n\n");
            Q07B();
            system("pause");
            break;
        case '8':
            printf("descubra a quantidade de nós internos: int ni(TAB *a);");
            printf("\n\n");
            Q08B();
            system("pause");
            break;
        case '9':
            printf("ache a quantidade de nós folha: int nf(TAB *a);");
            printf("\n\n");
            Q09B();
            system("pause");
            break;
        default:
            printf("Finalizando sistema... Tchau!\n");
            return 0;
            break;
        }
    }
}
int menuBB(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 07 - 2019.1 - Flavio Miranda de Farias\n\n");
        printf("Relacionado a Arvore Binária de Busca\n\n");
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
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n");
        switch (op){
        case '1':
            printf("Cópia de uma árvore: TAB* copia (TAB *a);");
            printf("\n\n");
            Q01BB();
            system("pause");
            break;
        case '2':
            printf("Espelho de uma árvore (o que está a esquerda na árvore original, estará a direita no espelho, e vice-versa): TAB* espelho (TAB *a);");
            printf("\n\n");
            Q02BB();
            system("pause");
            break;
        case '3':
            printf("Maior elemento da árvore: TAB* maior(TAB *a);");
            printf("\n\n");
            Q03BB();
            system("pause");
            break;
        case '4':
            printf("menor elemento da árvore: TAB* menor(TAB *a);");
            printf("\n\n");
            Q04BB();
            system("pause");
            break;
        case '5':
            printf("uma função que, dadas duas árvores deste tipo, testa se estas árvores são iguais. A função retorna um se elas são iguais e zero, caso contrário. A função deve obedecer ao seguinte protótipo: int igual (TAB* a1, TAB* a2);");
            printf("\n\n");
            Q05BB();
            system("pause");
            break;
        case '6':
            printf("uma função em C que, dada uma árvore binária qualquer, retire todos os elementos pares da árvore original. A função deve ter o seguinte protótipo: TAB* retira_pares (TAB* arv);");
            printf("\n\n");
            Q06BB();
            system("pause");
            break;
        case '7':
            printf("se esta estrutura TAB tivesse um campo cor (int cor), defina uma função em C que, ao receber uma árvore binária “sem cor” e totalmente balanceada (isto é, a distância da raiz a qualquer folha da árvore é sempre a mesma), retorne esta árvore com os nós coloridos somente de vermelho e preto, sendo que o nó pai NUNCA pode ter a mesma cor de seus filhos. A função deve possuir o seguinte protótipo: void colore (TAB* arv);");
            printf("\n\n");
            Q07BB();
            system("pause");
            break;
        case '8':
            printf("descubra a quantidade de nós internos: int ni(TAB *a);");
            printf("\n\n");
            Q08BB();
            system("pause");
            break;
        case '9':
            printf("ache a quantidade de nós folha: int nf(TAB *a);");
            printf("\n\n");
            Q09BB();
            system("pause");
            break;
        default:
            printf("Finalizando sistema... Tchau!\n");
            return 0;
            break;
        }
    }
}
int main(){
    menu();
    //menuBB();
    return 0;
}
