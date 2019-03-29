#include <stdio.h>

int main()
{
	int g,i;

	while(scanf("%d",&g) && g > 0)
	{
		g++;
		double poli[g], derivada[g-1], integral[g + 1];
		for(i = 0; i < g ; i++) scanf("%lf", poli + i);
		integral[0] = 0;
		for(i = 1 ; i < g + 1 ; i++)
		{
			integral[i] = poli[i - 1]/i;
		}
		for(i = 0 ; i < g - 1 ; i++)
		{
			derivada[i] = poli[i+1]*(i+1);
		}
		printf("Integral:\n");
		for(i = 0 ; i < g + 1 ; i++) printf("%.1lf ", integral[i]);

		printf("\nDerivada\n");
		for(i = 0 ; i < g - 1 ; i++) printf("%.1lf ", derivada[i]);

		printf("\n\n");
	}

	return 0;
}