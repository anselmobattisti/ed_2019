#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int barras=0;

char **s2ss(char *str)
{

	int i;
	for(i = 0 ; i < (int)strlen(str); i++) if(str[i] == '/') barras++;
	barras--;
	char **resp = (char **) malloc(barras * sizeof(char*));
	char *c = strtok(str, "/");
	int cont=0;
	while(c != NULL)
	{
		resp[cont] = (char *)malloc(strlen(c)*sizeof(char));
		strcpy(resp[cont++],c);
		c = strtok(NULL, "/");
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