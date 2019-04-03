/*Escrito por Sidney Loyola de Sá
 Data: 02/04/2019
 Alterado em 03/04/2019

 Q3) Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números.

 */
  
#include <stdio.h>

void imprimir(int *v, int tam, char rotulo[100]);
int contarDigitos(int n);
void transformar(int *v, int tam, int x);
int contar(int *v,int n,int tam);
int permutacao(int*a,int*b,int tamA,int tamB);

int main(void) {
  int x,y;
  while(1){
        printf("Insira  a :");
        scanf("%d", &x);

	      if(x==0) return 0;
	
        int n = contarDigitos(x);
              
        int a[n];
        
        transformar(a, n, x) ;
	
        printf("Insira  b :");
        scanf("%d", &y);

	      if(y == 0) return 0;

        int m = contarDigitos(y);
              
        int b[m];
        
        transformar(b, m, y) ;
	
        imprimir(a, n, "Vetor a");
         imprimir(b, m, "Vetor b");
        int p = permutacao(a,b,n,m);

        if( p>0){
          printf("a e permutação de b!! \n");
        }else{
          printf("a não e permutação de b!! \n");
        }

      
        
  }
  return 0;
}
int contarDigitos(int n){
	int cont = 0;
	do{
		cont++;
		n = n/10;
	}while(n!=0);
  return cont;
}

void transformar(int *v, int tam, int x){
	
	for(int i=0; i<tam; i++){
		v[i] = x%10;
    x = x/10;
	}
}
int contar(int *v,int n,int tam){
      int cont = 0;
      for(int i=0;i<tam;i++){
        if(v[i]==n){
          cont++;
        }
      }
      return cont;
}
int permutacao (int*a,int*b,int tamA,int tamB){
      if(tamA!=tamB) return 0;

       for(int i=0;i<tamA;i++) {
         int n = a[i];
         if(contar(a,  n,  tamA)!= contar(b,  n, tamB)) return 0;
       }
       return 1;

}

void imprimir(int *v, int tam, char rotulo[100]){

    printf("%s",rotulo);
    printf(":[");
    for(int i=0;i<tam;i++){
        printf("%d ",v[i]);
    }
    printf("] \n");
}


