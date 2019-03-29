#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *codifica(char *str)
{
	int tam = strlen(str);
	char *aux = (char*)malloc( tam * sizeof(char));
	int i;
	for(i = 0 ; i < tam; i++)
	{
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			aux[i] = '?';
		else
			aux[i] = str[i];
	}
	aux[tam] = '\0';
	return aux;
}

int main()
{
	char antiga[200];
	char *nova;

	scanf("%s", antiga);

	nova = codifica(antiga);
	printf("%s\n",nova);
	
	return 0;
}