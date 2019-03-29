#include <stdio.h>

int main()
{
	int n,i,j;
	scanf("%d",&n);

	int primos[n + 1];
	primos[0] = 0;
	primos[1] = 0;

	for(i = 2 ; i <= n ; i++) primos[i] = 1;

	for(i = 2 ; i <= n ; i++)
	{
		for(j = i + i; j <= n ; j+=i)
			primos[j] = 0;
	}
	printf("Primos ate N:\n");
	for(i = 0 ; i <= n ; i++)
	{
		if(primos[i])
			printf("%d\n", i);
	}
	
	return 0;
}