#include <stdio.h>
#include <math.h>



int main()
{
	int n;

	while(scanf("%d",&n) && n >= 0)
	{
		int digitos[(int)(log10(n) + 1)];

		int i = 0;
		while(n >= 10)
		{
			digitos[i++] = n%10;
			n/=10;
		}
		digitos[i] = n;

		int l = 0,r = i;
		int palindromo = 1;
		while((l <= r) && palindromo)
		{
			if(digitos[l] == digitos[r])
			{
				l++;
				r--;
			}
			else
					palindromo = 0;
		} 
		if(palindromo) printf("Eh palindromo\n");
		else printf("Nao eh palindromo\n");
	}


	return 0;
}