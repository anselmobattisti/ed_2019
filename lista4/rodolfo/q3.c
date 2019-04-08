#include <string.h>
#include <stdlib.h>
#include <stdio.h>


char ** s2ss( char * str){
	//inicializacao
	int i,j,count=0;

	//pivot que conterá os indices de onde tiver "/" na string
	int * pivot = (int*)malloc(sizeof(int)*(count+1));


	// contagem de ocorrências de "/" realocação do vetor pivot
	for( i= 0; i < strlen(str); i++){
		if (str[i] == '/'){
			count += 1;
		}
	}
	pivot = (int *)realloc(pivot,sizeof(int)*(count));
	count = 0;
	for( i= 0; i < strlen(str); i++){
		if (str[i] == '/'){
			count += 1;
			pivot[count-1] = i;
		}
	}

	//Alocar dinâmicamente mat_str e ao mesmo tempo copiando o conteúdo que estiver entre "/" com o  auxílio de pivot
	char ** mat_str = (char **)malloc(sizeof(char*)*(count+1));
	for (i = 0; i <= count; i++){
		if (i == 0){
			mat_str[i] = (char *) malloc(sizeof(char)*(pivot[i])+1);
			strncpy(mat_str[i],str,pivot[i]);
		}else{
			if (i == count){
				mat_str[i] = (char *) malloc(sizeof(char)*(strlen(str)-pivot[i-1]));
				strncpy(mat_str[i],str+pivot[i-1]+1,(strlen(str)-pivot[i-1]));
			}else{
				mat_str[i] = (char *) malloc(sizeof(char)*(pivot[i]-pivot[i-1])+1);
				strncpy(mat_str[i],str+pivot[i-1]+1,(pivot[i]-pivot[i-1]-1));
			}
		}
	}

	free(pivot);

	return mat_str;
}

int main(int argc, char const *argv[])
{
	char str[] = "Fla/Flu/Bota/asdsda";

	printf("A string original era: ");
	printf("%s\n", str);
	char ** mat_str = s2ss(str);

	// mostra as strings: está errado pois não é possível achar sizeof() de vetor dinâmicamente alocado!
	int i;
	printf("As strings separadas são: \n");
	for ( i = 0; i < sizeof(mat_str) ; i++)
		printf("%s\n", mat_str[i]);


	// Free em mat_str: está errado pois não é possível achar sizeof() de vetor dinâmicamente alocado!
	int t;
	for ( t = 0; t <=  sizeof(mat_str); t++)
		free(mat_str[t]);
	free (mat_str);

	return 0;
}
