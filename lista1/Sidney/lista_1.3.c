/*Escrito por Sidney Loyola de Sá
 Data: 30/03/2019
 Duvidas quanto ao m negativo

 Q3) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e um número m, e retorne todas as potências de m, menores que n. Por exemplo, se n = 1000 e
m = 2, seu programa deve imprimir os seguintes números: 1, 2, 4, 8, 16, 32, 64, 128, 256 e 512.
Seu programa para quando n for menor que 1 ou quando m for 0, ou 1 ou -1.
 
 */
#include <stdio.h>
#include <math.h> //lembrar de incluir o -lm no final na hora de compilar

int encontrar(int n, int m);


int main(void) {

	
	int n,m,tamanho;
	
	while (1){
		
		

		printf("Insira o valor de n: ");
		scanf("%d", &n);

		if(n<1) return 0;

		printf("Insira o valor de m: ");
		scanf("%d", &m);

		if(m>= -1 && m<=1)return 0;
		
		
		tamanho = encontrar(n,m);

		int v[tamanho];
		
		for (int i = 0; i<tamanho; i++){
			v[i] = pow(m,i);				
		}
		
		printf("Potencias menores que %d  : ",n);
		for(int i = 0; i< tamanho; i++){
			printf("%d ", v[i]);			
		}
		printf("\n");
		
	}

	return 0;
}

int encontrar(int n, int m){
	int tamanho = 0;
	
	while(pow(m,tamanho) < n){
		tamanho = tamanho +1;
	}	
	return tamanho;
}





