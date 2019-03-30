#include <stdio.h>
#include <string.h>
int main()
{

	char s1[100],s2[100];

	scanf("%s%s",s1,s2);

	int n = strlen(s1);
	int m = strlen(s2);
	int maior = 0;
	char resposta[100];
	int i,j;

	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < m ; j++)
		{
			if(s1[i] == s2[j])
			{
				int a = i,b = j;
				int cont=0;
				char aux[100];
				while(s1[a] == s2[b] && a < n && b < m)
				{
					aux[cont++] = s1[a];
					a++;
					b++;
				}
				if(cont > maior)
				{
					maior = cont;
					strcpy(resposta, aux);
				}
				else if(cont == maior)
				{
					if(strcmp(resposta, aux) == -1)
						strcpy(resposta, aux);
				}
			}
		}
	}
	printf("Maior subsequencia: %s\n", resposta);
	return 0;
}