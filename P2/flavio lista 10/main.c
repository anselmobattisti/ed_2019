/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 10 EXTRA
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
    int info;
    struct Lista *prox;
}TLSE;
typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;

//TLSE
TLSE* inicializar_TLSE(){
    return NULL;
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
void imprimir(TLSE *no){
    if(no){
        printf("%d ",no->info);
        imprimir(no->prox);
    }
}
TLSE* retira_recursivo(TLSE *no,int valor){
    if(!no)
        return no;
    if(no->info==valor){
        TLSE *p=no;
        no=no->prox;
        free(p);
        return no;
    }
    no->prox=retira_recursivo(no->prox,valor);
    return no;
}
//Fim TLSE
//Início de Árvore Binária
TAB* inicializa(){
    return NULL;
}
TAB* busca(TAB *a,int x){
    if((!a)||(a->info==x))
        return a;
    TAB *esqerda=busca(a->esq,x);
    if(esqerda)
        return esqerda;
    return busca(a->dir,x);
}
void libera(TAB *a){
    if(a){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
}
void print2DUtilGen(TAB *root, int space){
    if (!root)
        return;
    space += 2;
    print2DUtilGen(root->esq, space);
    for (int i = 3; i < space; i++)
        printf(" -");
    printf(">%d\n", root->info);
    print2DUtilGen(root->dir, space);
}
void imp_pre(TAB *a){
    if(a){
        printf("%d ",a->info);
        imp_pre(a->esq);
        imp_pre(a->dir);
    }
}
void imp_pos(TAB *a){
    if(a){
        imp_pos(a->esq);
        imp_pos(a->dir);
        printf("%d ",a->info);
    }
}
void imp_simetrico(TAB *a){
    if(a){
        imp_simetrico(a->esq);
        printf("%d ",a->info);
        imp_simetrico(a->dir);
    }
}
int maior(TAB *a){
    if(!a)
        return INT_MIN;
    int maior_esq=maior(a->esq),maior_dir=maior(a->dir),resp=a->info;
    if(maior_esq>resp)
        resp=maior_esq;
    if(maior_dir>resp)
        resp=maior_dir;
    return resp;
}
int menor(TAB *a){
    if(!a)
        return INT_MAX;
    int menor_esq=menor(a->esq),menor_dir=menor(a->dir),resp=a->info;
    if(menor_esq<resp)
        resp=menor_esq;
    if(menor_dir<resp)
        resp=menor_dir;
    return resp;
}
int altura(TAB* t){
    if(!t->esq && !t->dir)
        return 0;
    int a_esq=0,a_dir=0;
    if(t->esq)
        a_esq = altura(t->esq)+1;
    if(t->dir)
        a_dir = altura(t->dir)+1;
    if(a_esq > a_dir)
        return a_esq;
    else
        return a_dir;
}
TAB *cria_no(int valor){
    TAB *novo=(TAB*)malloc(sizeof(TAB));
    novo->info=valor;
    novo->esq=NULL;
    novo->dir=NULL;
    return novo;
}
TAB *insere(TAB *a, int valor){
    if(!a)
        return cria_no(valor);
    if(valor<a->info)
        a->esq = insere(a->esq,valor);
    if(valor>a->info)
        a->dir =  insere(a->dir,valor);
    return a;
}
TAB *copia(TAB *a){
    if(!a || (!a->esq && !a->dir))
        return a;
    TAB *b=cria_no(a->info);
    b->esq = copia(a->esq);
    b->dir = copia(a->dir);
    return b;
}
TAB *espelho(TAB *a){
    if(!a || (!a->esq && !a->dir))
        return a;
    TAB *b=cria_no(a->info);
    if(a->esq)
        b->dir=espelho(a->esq);
    if(a->dir)
        b->esq=espelho(a->dir);
    return b;
}
int igual(TAB* a, TAB* b){
    if(!a && !b)
        return 0;
    if((!a && b) || (!a && b))
        return 1;
    if(a->info != b->info)
        return 1;
    igual(a->esq,b->esq);
    igual(a->dir,b->dir);
    return 0;
}
TAB* retira(TAB *a,int x){
    if(!a)
        return a;
    if(a->info<x)
        a->dir=retira(a->dir,x);
    else
        if(a->info>x)
            a->esq=retira(a->esq,x);
        else { //achou!!!
            if((!a->esq)&&(!a->dir)){//não tem filhos
                free(a);
                return NULL;
            }
            if((!a->esq)||(!a->dir)){//tem 1 filho
                TAB *folha;
                if(!a->esq)
                    folha=a->dir;
                else
                    folha=a->esq;
                free(a);
                return folha;
            } else { //tem os 2 filhos
                TAB *folha=a->esq;
                while(folha->dir)
                    folha=folha->dir;
                a->info=folha->info;
                folha->info=x;
                a->esq=retira(a->esq,x);
            }
        }
        return a;
}
TAB* retira_pares(TAB* a){
    if(a){
        a->esq=retira_pares(a->esq);
        a->dir=retira_pares(a->dir);
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
      a=imprime_pre_ordem(arvore->esq);///a==0 caso sub_arvore_esqerda==NULL
      b=imprime_pre_ordem(arvore->dir);///a==0 caso sub_arvore_dirita==NULL
      if(b==0 && a==0)
        printf("()");///imprime  () se e somente se encontrar um nó folha
      else
        if(b==0 && a!=0)
            printf("*>");///isso acontece se encontrar um nó com a perna dirita null
      else
        if(b!=0 && a==0)
            printf("*<");///isso acontece se encontrar um nó com a perna esqerda null
      printf(")");///fecha a representação de uma raiz
   } else
        return 0;
    return 0;
}
int contagem(TAB* a) {
    return (a != NULL) ? (contagem(a->esq) + contagem(a->dir) + 1) : 0;
}
int nos_internos(TAB *a){
    if(!a || (!a->esq && !a->dir)) return 0;
    else return 1 + (nos_internos(a->esq) + nos_internos(a->dir));
}
int nos_folha(TAB *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1;
    return nos_folha(a->esq) + nos_folha(a->dir);
}
//Fim de Árvore Binária

void Q06(){

}
int auxiliar6(TAB *a,int x, int y){
    if(a){
        if(a->esq && a->esq->info==x)
            y = a->info;
        if(a->dir && a->info==x)
            y = a->dir->info;
        y = auxiliar6(a->esq,x,y);
        y = auxiliar6(a->dir,x,y);
    }
    return y;
}
int sucessorTABB(TAB *a,int x){ //não encontra o sucessor anterior a raiz a direita
    if(!a || !busca(a,x))
        return -1;
    else
        return auxiliar6(a,x,x);
}
void Q05(){
    TAB *a = inicializa();
    a = insere(a,6);
    a = insere(a,7);
    a = insere(a,3);
    a = insere(a,2);
    a = insere(a,4);
    a = insere(a,5);
    a = insere(a,0);
    a = insere(a,9);
    a = insere(a,8);
    a = insere(a,11);
    print2DUtilGen(a,0);
    int resp1,resp2, num;
    printf("\n\nDigite um numero: ");
    scanf("%d",&num);
    resp1 = sucessorTABB(a,num);
    if(resp1!=-1)
        printf("\n\nO sucessor e: %d\n",resp1);
    else
        printf("\nNao ha sucessor!\n");
    /*
    resp2 =antecessorTABB(a,num);
    if(resp2!=-1)
        printf("\nO antecessor e: %d\n",resp2);
    else
        printf("\n\nNao ha antecessor!\n");
    */
}
int auxiliar4(TAB *a, int x, int y){
    if(a){
        if(a->info<x)
            y=a->info;
        if(a->info<y)
            y=a->info;
        y = auxiliar4(a->esq,x,y);
        y = auxiliar4(a->dir,x,y);
    }
    return y;
}
int antecessor(TAB *a, int x){
    if(!a || !busca(a,x))
        return -1;
    else
        return auxiliar4(a,x,x);
}
int auxiliar3(TAB *a,int x,int y){
    if(a){
        if(a->info>x){
            if(y==x)
                y=a->info;
            if(y>a->info)
                y=a->info;
        }
        y = auxiliar3(a->esq,x,y);
        y = auxiliar3(a->dir,x,y);
    }
    return y;
}
int sucessor(TAB *a, int x){
    if(!a || !busca(a,x))
        return -1;
    else
        return auxiliar3(a,x,x);
}
void Q04(){
    TAB *a = inicializa();
    a = insere(a,5);
    a = insere(a,7);
    a = insere(a,3);
    a = insere(a,2);
    a = insere(a,4);
    a = insere(a,0);
    a = insere(a,1);
    a = insere(a,9);
    a = insere(a,8);
    a = insere(a,11);
    a = insere(a,10);
    print2DUtilGen(a,0);
    int resp1,resp2, num;
    printf("\n\nDigite um numero: ");
    scanf("%d",&num);
    resp1 = sucessor(a,num);
    if(resp1!=-1)
        printf("\n\nO sucessor e: %d\n",resp1);
    else
        printf("\nNao ha sucessor!\n");
    resp2 =antecessor(a,num);
    if(resp2!=-1)
        printf("\nO antecessor e: %d\n",resp2);
    else
        printf("\n\nNao ha antecessor!\n");
}

int apenas_um_filho(TAB *a) {
    if(!a)
        return 0;
    return apenas_um_filho_aux(a->esq) && apenas_um_filho_aux(a->dir);
}
int apenas_um_filho_aux(TAB *a) {
    if (!a || (!a->esq && !a->dir))
        return 1;
    if (a->esq && a->dir)
        return 0;
    if (a->esq)
        return apenas_um_filho_aux(a->esq);
    if (a->dir)
        return apenas_um_filho_aux(a->dir);
}
int auxiliar5(TAB *a){
    if(!a || (!a->esq && !a->dir))
        return 1;
    if(a){
        if((a->esq && a->dir))
            return 0;
        if((a->esq && !a->dir)||(!a->esq && a->dir))
            return 1;
    }
    teste3(a->esq);
    teste3(a->dir);
}
int teste3(TAB *a){
    if(!a)
        return 1;
    if(a){
        if(!a->esq && !a->dir)
            return 1;
        else
            return auxiliar5(a->esq) && auxiliar5(a->dir);
    }
}
void Q03(){
    TAB *a = inicializa();
    /*
    //caso 1
    a = insere(a,5);
    a = insere(a,4);
    a = insere(a,8);
    a = insere(a,6);
    a = insere(a,7);
    //caso 2
    a = insere(a,5);
    a = insere(a,4);
    a = insere(a,7);
    a = insere(a,6);
    a = insere(a,8);
    */
    //caso 3
    a = insere(a,10);
    a = insere(a,11);
    a = insere(a,12);
    a = insere(a,13);
    a = insere(a,17);
    a = insere(a,16);
    a = insere(a,18);
    print2DUtilGen(a,0);
    if(apenas_um_filho(a)==1)
        printf("\n\nSomente 1 Filho nos nos internos (zigzag)!\n");
    else
        printf("\n\nMais de 1 Filho em no interno (nao zigzag)!\n");
}

TLSE * auxiliar2(TAB *b, TLSE *lista){
    if(b){
        lista = insere_inicio_TLSE(lista,b->info);
        lista = auxiliar2(b->esq,lista);
        lista = auxiliar2(b->dir,lista);
    }
    return lista;
}
TLSE *descendentes(TAB *a, int x){
    TAB *b = busca(a,x);
    if(!b)
        return b;
    else {
        TLSE *l=(TLSE*)malloc(sizeof(TLSE));
        l = inicializar_TLSE();
        l=auxiliar2(b,l);
        l=retira_recursivo(l,x);
        return l;
    }
}
void ancestrais3(TAB *a, int x) {
  if (!a) return;
  int val = -1;
  while (a) {
    val = a->info;
    printf("%d - ",val);
    if (x > val) {
      a = a->dir;
    } else {
      a = a->esq;
    }
  }
  if (val == x) {
    printf("Achou");
  }
}
TLSE *aa(TAB *a, int x){
    if(a->info==x)
        return insere_inicio_TLSE(NULL,x);
    TAB *p;
    if(a->info>x)
        p=a->esq;
    else
        p=a->dir;
    return insere_inicio_TLSE(aa(p,x),a->info);
}
TLSE *ancestrais2(TAB *a, int x){
    if(!busca(a,x))
        return NULL;
    return retira_recursivo(aa(a,x),x);
}
TLSE * auxiliar1(TAB *b, TLSE *lista,int ni, int nf){
    if(b){
        if(ni<nf){ //esquerda
            if(b->info>=ni && b->info<=nf)
                lista = insere_inicio_TLSE(lista,b->info);
        } else { //direita
             if(b->info<=ni && b->info>=nf)
                lista = insere_inicio_TLSE(lista,b->info);
        }
        lista = auxiliar1(b->esq,lista,ni,nf);
        lista = auxiliar1(b->dir,lista,ni,nf);
    }
    return lista;
}
TLSE *ancestrais(TAB *a, int x){
    TAB *b = busca(a,x);
    if(!b)
        return b;
    else {
        TLSE *l=(TLSE*)malloc(sizeof(TLSE));
        l = inicializar_TLSE();
        if(a->info==x){
            l=insere_inicio_TLSE(l,x);
            return l;
        }
        l=auxiliar1(a,l,a->info,x);
        l=retira_recursivo(l,x);
        return l;
    }
}
void Q02(){
    TAB *a = inicializa();
    a = insere(a,5);
    a = insere(a,3);
    a = insere(a,7);
    a = insere(a,1);
    a = insere(a,6);
    a = insere(a,8);
    a = insere(a,0);
    a = insere(a,2);
    a = insere(a,10);
    print2DUtilGen(a,0);
    int num;
    printf("\nDigite um valor da arvore: ");
    scanf("%d",&num);
    printf("\n\nOs ancestrais 1 sao: ");
    imprimir(ancestrais(a,num));
    printf("\n\nOs ancestrais 2 sao: ");
    imprimir(ancestrais2(a,num));
    printf("\n\nOs ancestrais 3 sao: ");
    ancestrais3(a,num);
    printf("\n\nOs descendentes sao: ");
    imprimir(descendentes(a,num));
}

int estritamente_balanceada(TAB *a) {
    if (!a) return 1;
    if (a->esq && !a->dir) return 0;
    if (!a->esq && a->dir) return 0;
    if (!a->esq && !a->dir) return 1;
    if (a->esq && a->dir)
        return estritamente_balanceada(a->esq)&&estritamente_balanceada(a->dir);
}
int teste1(TAB *a){
    if(a){
        if((a->esq && !a->dir)||(!a->esq && a->dir))
            return 0;
        teste1(a->esq);
        teste1(a->dir);
    }
    return 1;
}
void Q01(){
    TAB *a = inicializa();
    /*
    //caso 1
    a = insere(a,5);
    a = insere(a,4);
    a = insere(a,6);
    //caso 2
    a = insere(a,5);
    a = insere(a,4);
    //caso 3
    a = insere(a,5);
    //caso 4 Falhou
    a = insere(a,5);
    a = insere(a,3);
    a = insere(a,2);
    a = insere(a,4);
    */
    //caso 4 Falhou
    a = insere(a,5);
    a = insere(a,3);
    a = insere(a,6);
    a = insere(a,2);
    a = insere(a,4);

    print2DUtilGen(a,0);
    //if(estritamente_balanceada(a)==1)
    if(teste1(a)==1)
        printf("\n\nEstritamente balanceada!\n");
    else
        printf("\n\nDesbalanceada!\n");
}

int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 10 (EXTRA) - 2019.1 - Flavio Miranda de Farias\n\n");
        printf("Digite o valor do menu a baixo\n\n");
        printf("1 - Exercicio 01\n");
        printf("2 - Exercicio 02\n");
        printf("3 - Exercicio 03\n");
        printf("4 - Exercicio 04\n");
        printf("5 - Exercicio 05\n");
        printf("6 - Exercicio 06\n");
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n");
        switch (op){
        case '1':
            printf("Escreva uma função que testa se uma árvore binária é estritamente balanceada (ou 0 ou 2 filhos). int teste1(TAB *a);");
            printf("\n\n");
            Q01();
            system("pause");
            break;
        case '2':
            printf("Dado uma ABB (árvore binária de busca) e uma informação, retorna uma lista de ancestrais dessa informação. TLSE *ancestrais(TABB *a, int x);");
            printf("\n\n");
            Q02();
            system("pause");
            break;
        case '3':
            printf("Dado uma AB (árvore binária simples), teste se os nós, exceto raiz e folhas, possuem apenas 1 filho. int teste3(TAB *a);");
            printf("\n\n");
            Q03();
            system("pause");
            break;
        case '4':
            printf("Dado uma AB (árvore binária simples) e uma informação, retorna o sucessor na árvore. Se x é o maior elemento da árvore, retorne ele mesmo. int sucessor(TAB *a, int x);");
            printf("\n\n");
            Q04();
            system("pause");
            break;
        case '5':
            printf("Refaça a questão 4 considerando que a árvore é uma ABB (árvore binária de busca).");
            printf("\n\n");
            Q05();
            system("pause");
            break;
        case '6':
            printf("Refaça a questão 4 considerando que a árvore é uma Árvore B.");
            printf("\n\n");
            Q06();
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
