#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int barras=0;
char **s2ss(char *str)
{

	int i;
	for(i = 0 ; i < (int)strlen(str); i++) if(str[i] == '/') barras++;
		
	barras--;
	int tamPalavras[barras];
	int contaPalavras = 0;
	int tamanho = 0;
	for(i = 1 ; i < (int)strlen(str); i++)
	{
		if(str[i] == '/')
		{
			tamPalavras[contaPalavras] = tamanho;
			tamanho=0;

			contaPalavras++;
		}
		else
			tamanho++;
	}

	char **resp = (char **) malloc(barras * sizeof (char*));

	int cont=0, palavras = 0;
	resp[0] = (char *) malloc(tamPalavras[palavras]+1 * sizeof(char));
	for(i = 1 ; i < (int)strlen(str); i++)
	{
		if(str[i] != '/')
		{
			resp[palavras][cont++] = str[i];
			//printf("%c\n", str[i]);
		}
		else
		{
			cont=0;
			palavras++;
			resp[palavras] = (char *)malloc(tamPalavras[palavras]+1 * sizeof(char));
		}
	}

	return resp;
}

int main()
{
	char *original = (char *)malloc(1000 * sizeof(char));
	char **palavras;

	scanf("%s",original);

	palavras = s2ss(original);
	int i;
	for(i = 0 ; i < barras; i++)
	{
		printf("%s\n", palavras[i]);
	}

	return 0;
}