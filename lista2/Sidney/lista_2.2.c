// Escrito por Sidney Loyola de Sá
// Data: 30/03/2019

#include <stdio.h>
#include <math.h> //lembrar de incluir o -lm no final na hora de compilar


void integral(int *p, int *I, int tamanho);
void derivada(int *p, int *I, int tamanho);

int main(void) {

	
	int g;
		
	while (1){
		
		printf("Insira o valor de g: ");
		scanf("%d", &g);
		
		if(g <= 0) return 0;

		
		printf("Insira o valor dos coeficientes: \n");

		int p[g+1];
	

		for(int i = 0; i<(g+1); i++){
			scanf("%d",&p[i]);
		}
		
		int D[g];
		derivada(p,D,g);
		
		int I[g+1];
		integral(p,I,g+1);	
	
		
		/*printf("Polinomio : ");
		int e = g;
		for(int i = 0; i< (g+1); i++){
			if(e == 0){
				printf("%d x^%d ", p[i],e);	
			}else{
				printf("%d x^%d + ", p[i],e);	
			}
			
			e--;		
		}
		printf("\n");*/

		printf("Polinomio : ");
		
		for(int i = g; i>=0; i--){
			if(i == 0){
				printf("%d x^%d ", p[i],i);	
			}else{
				printf("%d x^%d + ", p[i],i);	
			}		
				
		}
		printf("\n");
		
		printf("Integral : ");
		
		for(int i = (g+1); i>=0; i--){
			if(i == 0){
				printf("%d x^%d ", I[i],i);	
			}else{
				printf("%d x^%d + ", I[i],i);	
			}
			
					
		}
		printf("\n");

		printf("Derivada : ");
				
		for(int i = g-1; i>=0; i--){
			if(i == 0){
				printf("%d x^%d ", D[i],i);	
			}else{
				printf("%d x^%d + ", D[i],i);	
			}		
				
		}
		printf("\n");

		
		
		
	}

	return 0;
}

void integral(int *p, int *I, int tamanho){
	
	for(int i = 0; i<=tamanho; i++){
		if(i==0){
			I[i] = 0;	
		}else{
			I[i] = p[i-1]/(i);
		}
				
	}
}

void derivada(int *p, int *D, int tamanho){
	
	for(int i = 0; i<tamanho; i++){
		D[i] = (i+1) * p[i+1];
		
	}
}






