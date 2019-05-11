*

Escrito por Sidney Loyola de Sá
Data: 11/05/2019

Q3) Escreva uma função que dada uma string composta por substrings separadas por “/”, retorne
todas as suas substrings da string original. Por exemplo, a string /Fla/Flu/Bota/ será decomposta
em:
Fla
Flu
Bota
Esta função não deve modificar a string original. O protótipo da função é o seguinte: char** s2ss
(char *str). Isto é, a resposta desta função será uma matriz de caracteres alocada
dinamicamente.


strlen
strcpy
strcat
strcmp
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char** s2ss (char *str);

int main(void){

	char* str = "/Fla/Flu/Bota/";

	char** res = s2ss(str);	

	
	for(int i=0;i<3;i++){
		for(int j=0;res[i][j]!='\0';j++){
			printf("%c",res[i][j]);
		}
		printf("\n");
	}	
	
	return 0;
}

char** s2ss (char *str){
	
	//cria as variaveis necessarias para executar o codigo
	int m = 0,n = 0, c = 0,contar=0;
	char aux[100];

	//conta o numero de barras para determinar o numero de linhas
	for(int i=0;str[i]!='\0';i++){
		if(str[i] == '/'){
			m++;
		}
	}	
	m--;	
	
	//aloca dinamicamente o numero de linhas
	char **p = (char**) malloc(m*sizeof(char*));
	
	m = 0;

	//percorre a string para fazer a separação

	for(int i=0;str[i]!='\0';i++){
		//verifica se tem que contar o numero de letras		
		if(contar){
			
			if(str[i] != '/'){
				n++;
				aux[c] = str[i];
				c++;
			}			
		}
		if(str[i] == '/'){
			if(contar == 0){
				contar = 1;
			}else{	
				//aloca dinamicamente a linha				
				p[m] = (char*) malloc(n*sizeof(char));	
				for(int j = 0; j<n;j++){
					
					p[m][j] = aux[j];
					
				}
				
				m++;
				aux[0] = '\0';
				n = 0;		
				c = 0;				
			}
			
		}		
	}
		
	
	return p;
}
