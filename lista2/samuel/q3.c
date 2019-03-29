#include <stdio.h>

int main()
{
	int contaA[10] = {0,0,0,0,0,0,0,0,0,0};
	int contaB[10] = {0,0,0,0,0,0,0,0,0,0};
	int a,b;

	scanf("%d%d",&a,&b);

	while(a >= 10)
	{
		contaA[a%10]++;
		a/=10;
	}
	contaA[a]++;

	while(b >= 10)
	{
		contaB[b%10]++;
		b/=10;
	}
	contaB[b]++;
	int ans = 0,i;
	for(i = 0 ; i < 10 ;i++)
	{
		if(contaA[i] == contaB[i]) ans++;
	}

	if(ans == 10) printf("Eh permutacao\n");
	else printf("Nao eh permutacao\n");

	return 0;
}