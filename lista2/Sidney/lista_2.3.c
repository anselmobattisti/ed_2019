// Escrito por Sidney Loyola de Sá
// Data: 02/04/2019
  
#include <stdio.h>
int contar(int *v,int n,int tam);
int permutacao(int*a,int*b,int tamA,int tamB);

int main(void) {
  int x,y;
  while(1){
        printf("Insira a quantidade de elementos de a :");
        scanf("%d", &x);

	if(x==0) return 0;
	

	printf("Digite os elementos de a : \n");
	
        int a[x];
        for(int i = 0; i<x;i++){
           scanf("%d", &a[i]);
        }
        printf("\n");
        printf("Insira a quantidade de elementos de b :");
        scanf("%d", &y);

	if(y == 0) return 0;

	printf("Digite os elementos de a : \n");

        int b[y];
        for(int i = 0; i<y;i++){
           scanf("%d", &b[i]);
        }
        printf("\n");

        int p = permutacao(a,b,x,y);

        if( p>0){
          printf("a e permutação de b!! \n");
        }else{
          printf("a não e permutação de b!! \n");
        }

      
        
  }
  return 0;
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


