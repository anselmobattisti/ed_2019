/*
Escrito por Sidney Loyola de Sá
 Data: 30/03/2019
 
 Q1) Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho,
seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um
segmento crescente destes n números. Exemplos:
 Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.
 Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.
Seu programa para quando n for menor ou igual a zero.

 */

#include <stdio.h>


int main(void) {

	int n, c, aux, c1;
	
	n = 1;
	
	while (n > 0){
		
		c = 1;
		//aux = 0;
		c1 = 1;

		printf("Insira o valor de n: ");
		scanf("%d", &n);
		
		int v[n];
		
		printf("Insira os valores da sequencia: ");

		for(int i = 0; i < n; i++){
			scanf("%d", &v[i]);
		}
				
		for (int i = 1; i< n; i++){
			if(v[i] > v[i-1]){
				c = c + 1;				
			}else{
				if(c>c1){
					c1 = c;					
				}
				c = 1;
			}
			//aux = v[i];						
			
		}		
		printf("Sequencia : ");
		for(int i = 0; i< n; i++){
			printf("%d ", v[i]);			
		}
		printf("\n");
		printf("Comprimento máximo do segmento crescente : %d \n", c1);		
	}

	return 0;
}






