// Escrito por Sidney Loyola de Sá
// Data: 02/04/2019
  
#include <stdio.h>


int palindromo(int*a,int tamA);

int main(void) {
  int x;

  while(1){
        printf("Insira numero a ser testado :");
        scanf("%d", &x);

	if(x==0) return 0;
	
	int n = contarDigitos(x);
	
	int a[n];
	
       

        int p = palindromo(a,x);

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
	}while(n!=0)
}

void transformar(int *v, tam, x){
	
	for(int i=0; i<tam; i++){
		v[i] = 
	}
}
int palindromo (int*a,int tamA){
      int aux = (tamA-1);

       for(int i=0;i<aux;i++) {
		
		if(a[i] != a[aux])return 0;
		aux--;		
                 
       }
       return 1;
}


