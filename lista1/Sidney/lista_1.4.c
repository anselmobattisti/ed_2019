// Escrito por Sidney Loyola de Sá
// Data: 30/03/2019  /  02/04/2019


#include <stdio.h>
#include <math.h> //lembrar de incluir o -lm no final na hora de compilar


int primo(int n);

int main(void) {

	
	int n,aux,naoEncontrar;
	
	while (1){
		
		naoEncontrar = 1;
		

		printf("Insira o valor de n: ");
		scanf("%d", &n);
		
		if(n <= 0) return 0;

		int v[n];
		aux = n+1;
		
		for (int i = 0; i< n; i++){
			naoEncontrar = 1;
			while(naoEncontrar){
				if(primo(aux)){
					v[i] = aux;
					naoEncontrar = 0;
				}					
				aux = aux + 1;
			}					
		}		
		printf("Numeros Primos depos de %d : ",n);
		for(int i = 0; i< n; i++){
			printf("%d ", v[i]);			
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
				return 0;
			}
		}
		return 1;
	}
	
}






