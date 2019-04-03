/*
Escrito por Sidney Loyola de Sá
 Data: 30/03/2019

 Q2) Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x2
 + 2x + 12 terá um
vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x 3
 +
x
2
 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero
 */

#include <stdio.h>


void imprimir(int *v, int g, char rotulo[100]);
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
	
		
		
		imprimir(p, g, "Polinomio");
    imprimir(I, g+1, "Integral");
    imprimir(D, g-1, "Derivada");
		
		
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

void imprimir(int *v, int g, char rotulo[100]){

    printf("%s",rotulo);
    printf(": ");


    for(int i = g; i>=0; i--){
			if(i == 0){
				printf("%d x^%d ", v[i],i);	
			}else{
				printf("%d x^%d + ", v[i],i);	
			}	
    }    
    printf("\n");
}





