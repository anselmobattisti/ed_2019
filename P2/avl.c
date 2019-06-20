#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct no{
    int info;
    struct no*  esq;
    struct no*  dir;
    int alt;
}no;


void libera(no* t){
    if( t != NULL ){
        libera( t->esq );
        libera( t->dir );
        free( t );
    }
}


no* busca(int e, no* t ){
    if( t == NULL ) return NULL;
    if( e < t->info ) return busca( e, t->esq );
    if( e > t->info ) return busca( e, t->dir );
    return t;
}


static int calc_alt( no* n ){
    if( n == NULL ) return -1;
    return n->alt;
}


static int max( int l, int r){
    return l > r ? l: r;
}


static no* rot_dir( no* k2, int tab ){
    if (tab)
      printf("\t -");
    printf("RSD\n");
    no* k1 = NULL;
    k1 = k2->esq;
    k2->esq = k1->dir;
    k1->dir = k2;
    k2->alt = max( calc_alt( k2->esq ), calc_alt( k2->dir ) ) + 1;
    k1->alt = max( calc_alt( k1->esq ), k2->alt ) + 1;
    return k1; /* nova raiz */
}


static no* rot_esq( no* k1, int tab ){
    if (tab)
      printf("\t -");
    printf("RSE\n");
    no* k2;
    k2 = k1->dir;
    k1->dir = k2->esq;
    k2->esq = k1;
    k1->alt = max( calc_alt( k1->esq ), calc_alt( k1->dir ) ) + 1;
    k2->alt = max( calc_alt( k2->dir ), k1->alt ) + 1;
    return k2;  /* nova raiz */
}


static no* rot_esq_dir( no* k3 ){
    printf("\nRED\n");
    k3->esq = rot_esq( k3->esq, 1);
    return rot_dir( k3, 1 );
}


static no* rot_dir_esq( no* k1 ){
    printf("\nRDE\n");
    k1->dir = rot_dir( k1->dir, 1);
    return rot_esq( k1, 1);
}


no* insere(int e, no* t ){
    if( t == NULL ){
        t = (no*)malloc(sizeof(no));
        t->info = e;
        t->alt = 0;
        t->esq = t->dir = NULL;
    } else if( e < t->info ){
        t->esq = insere( e, t->esq );
        if( calc_alt( t->esq ) - calc_alt( t->dir ) == 2 )
            if( e < t->esq->info )
                t = rot_dir( t, 0 );
            else
                t = rot_esq_dir( t );
    } else if( e > t->info ){
        t->dir = insere( e, t->dir );
        if( calc_alt( t->dir ) - calc_alt( t->esq ) == 2 )
            if( e > t->dir->info )
                t = rot_esq( t, 0 );
            else
                t = rot_dir_esq( t );
    }

    t->alt = max( calc_alt( t->esq ), calc_alt( t->dir ) ) + 1;
    return t;
}


int calc_alt_retira(no *T){
    int lh,rh;
    if(T==NULL) return(0);
    if(T->esq==NULL) lh=0;
    else lh=1+T->esq->alt;
    if(T->dir==NULL) rh=0;
    else rh=1+T->dir->alt;
    if(lh>rh) return(lh);
    return(rh);
}


int FB(no *T){
    int lh,rh;
    if(T==NULL) return(0);
    if(T->esq==NULL) lh=0;
    else lh=1+T->esq->alt;
    if(T->dir==NULL) rh=0;
    else rh=1+T->dir->alt;
    return(lh-rh);
}


void imprime_aux(no *a, int andar){
  if(a){
      int j;
      imprime_aux(a->dir,andar+1);
      for(j=0; j<=andar; j++) printf("   ");
      printf("%d\n", a->info);
      imprime_aux(a->esq,andar+1);
  }
}


void imprime(no *a){
  imprime_aux(a, 1);
}


no * retira(int x, no *T){
    no *p;
    if(T==NULL)
        return NULL;
    else
        if(x > T->info){
            T->dir=retira(x,T->dir);
            if(FB(T)==2)
                if(FB(T->esq)>=0)
                    T=rot_dir(T,0);
                else
                    T=rot_esq_dir(T);
        }
        else
            if(x<T->info){
                    T->esq=retira(x,T->esq);
                    if(FB(T)==-2)//Rebalance during windup
                        if(FB(T->dir)<=0)
                            T=rot_esq(T,0);
                        else
                            T=rot_dir_esq(T);
            }
            else{
                //info to be deleted is found
                  if(T->esq != NULL){
                      p=T->esq;
                      while(p->dir != NULL) p=p->dir;
                      T->info=p->info;
                      T->esq=retira(p->info, T->esq);
                      if(FB(T)== -2)//Rebalance during windup
                        if(FB(T->dir)<=0)
                            T=rot_esq(T,0);
                        else
                            T=rot_dir_esq(T);
                  }
                  else{
                      no *x = T;
                      T = T->dir;
                      free(x);
                      return(T);
                  }
            }
    T->alt=calc_alt_retira(T);
    return(T);
}


static int min( int l, int r){
    return l < r ? l: r;
}


int main(int argc, char *argv[]){
  struct no * arvore = NULL;
  int num = 0, from, to;

  arvore = insere(1, arvore);
  arvore = insere(64, arvore);
  arvore = insere(12, arvore);
  arvore = insere(18, arvore);
  arvore = insere(66, arvore);
  arvore = insere(38, arvore);
  arvore = insere(95, arvore);
  arvore = insere(58, arvore);
  arvore = insere(59, arvore);

  imprime(arvore);
  while(num != -1){
    printf("\nDigite o numero a ser inserido ou -9 para retirar ou -1 para sair -> ");
    scanf("%i", &num);
    if(num == -9){
        printf("Digite o numero a ser retirado -> ");
        scanf("%i", &num);
        arvore = retira(num, arvore);
    } else
        arvore = insere(num, arvore);
    imprime(arvore);
    printf("\n\n");
  }
}
