/* Escrito por Sidney Loyola de Sá
 Data: 02/04/2019
 Alterado em 03/04/2019 
 
 Q4) Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
número for negativo.
 */

  
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

        
        
        int a[n];
        
        transformar(a, n, x) ;

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



