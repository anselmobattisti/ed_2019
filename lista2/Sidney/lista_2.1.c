// Escrito por Sidney Loyola de Sá
// Data: 30/03/2019

#include <stdio.h>
#include <math.h> //lembrar de incluir o -lm no final na hora de compilar


int primo(int n); 


int main(void) {
	
	int n;
	
	while (1){
		
		printf("Insira o valor de n: ");
		scanf("%d", &n);
		
		if(n <= 0) return 0;

		int v[n-1]; // vetor onde vai se escrever todos os valores entre 2 e n
		int c[n-1]; // vetor que indicará os numeros primos circulados

		for(int i = 0; i<(n-1); i++){
			v[i] = i +2; 	// escreve os valores no vetor
			c[i] = 1;	// preenche o vetor com numero 1 em todas as posições
		}
		
		for(int i = 0; i<(n-1); i++){
			if(c[i] != 0){ // verifica se esse numero ja foi eliminado
				for(int j = i+1; j<(n-1); j++){
					if(v[j]%v[i] == 0){ // testa para saber se e multiplo
						c[j] = 0;  // marca com 0 para considerar eliminado
					}
				}
			}
		}

		printf("Peneira de Erastothenes %d : ",n);
		for(int i = 0; i< (n-1); i++){
			printf("%d ", v[i]);			
		}
		printf("\n");

		printf("Primos : ");
		for(int i = 0; i< (n-1); i++){
			if(c[i] == 1){ // so exibe os marcados com 1 que sao os primos
				printf("%d ", v[i]);
			}
						
		}
		printf("\n");
		
		
	}

	return 0;
}

int primo(int n) {

	if(n == 2){
		return 1;
	}else if (n<2 || (n%2) == 0){
		return 0;
	}else{
		int lim = (int) sqrt(n); 

		for(int i = 3; i<= lim; i+=2){
			if(n%i == 0){
				//se encontrar multiplo quer dizer que nao e primo.				
				return 0;
			}
		}
		return 1;
	}
	
}






