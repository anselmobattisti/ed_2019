/* Escrito por Sidney Loyola de Sá
 Data: 02/04/2019
 Alterado em 03/04/2019 */

  
#include <stdio.h>

int contarDigitos(int n);
void transformar(int *v, int tam, int x);
int palindromo(int*a,int tamA);

int main(void) {
  int x;

  while(1){
        printf("Insira numero a ser testado :");
        scanf("%d", &x);


        if(x==0) return 0;
        
        int n = contarDigitos(x);

        printf("N = %d \n",n);
        
        int a[n];
        
        transformar(a, n, x) ;

        printf("Array : [");
        for(int i = 0; i<n;i++){
          printf("%d",a[i]);
        }
         printf("] \n");

        int p = palindromo(a,n);


        if( p>0){
            printf("a e palindromo!! \n");
        }else{
            printf("a não e palindromo!! \n");
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
int palindromo (int*a,int tam){
      int aux = (tam-1);
      int lim = tam/2;

       for(int i=0;i<lim;i++) {
				      if(a[i] != a[aux])return 0;
		      aux--;	                 
       }
      return 1;
}



