 /*
 Escrito por Sidney Loyola de Sá
 Data: 30/03/2019
 
 Q5) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste
programa deve ser “1100”. Seu programa para quando n for menor que zero.
 
 
 */

 
#include <stdio.h>
#include <math.h> //lembrar de incluir o -lm no final na hora de compilar

int encontrar(int n, int m);

void imprimirArray(int *v, int n, int tamanho);


int main(void) {

	
	int n,m,tamanho;
	
	while (1){
		
		

		printf("Insira o valor de n: ");
		scanf("%d", &n);

		if(n<0) return 0;

		m = 2;
		
		tamanho = encontrar(n,m);
		
		if (tamanho == 0){
			int v[1] = {0};
			imprimirArray(v,n,1);
		}else{

			int v[tamanho];
			int soma = 0;
			int e = tamanho - 1;
			
			for (int i = 0; i<tamanho; i++){
				int aux = 0;
				if(soma < n){
					aux = pow(2,e);
					if((soma + aux) <= n){
						soma = soma +aux;
						v[i] = 1;
					}else{
						v[i] = 0;
					}
				}else{
					v[i] = 0;
				}
				e = e -1;							
			}
			
			imprimirArray(v,n,tamanho);
		}
	}

	return 0;
}

int encontrar(int n, int m){
	int tamanho = 0;
	
	while(pow(m,tamanho) <= n){
		tamanho = tamanho +1;
	}	
	return tamanho;
}

void imprimirArray(int *v, int n, int tamanho){
		printf("O numero %d em binario fica: ",n);
		for(int i = 0; i< tamanho; i++){
			printf("%d", v[i]);			
		}
		printf("\n");
}






