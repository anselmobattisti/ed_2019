#include <stdio.h>
#include <stdlib.h>
void geraHadamard(int atual, int n, int **mat)
{
	
	if(atual > n) return;
	if(atual == 1)
		mat[0][0] = 1;
	else
	{
		int i,j,meio=atual/2;
		for(i = 0 ; i < meio; i++)
		{
			for(j = 0 ; j < meio; j++)
			{
				mat[i][meio+j] = mat[i][j];
				mat[meio+i][j] = mat[i][j];
				mat[meio+i][meio+j] = !mat[i][j];
			}
		}
	}
	
	geraHadamard(atual*2,n,mat);
}

int main()
{

	int n,i,j;

	scanf("%d",&n);

	if(((n - 1) & n)) printf("Impossivel gera a matriz para este N!\n");
	else
	{
		int **mat = (int **)malloc(n*sizeof(int*));
		for(i = 0 ; i < n ; i++) mat[i] = (int*)malloc(n*sizeof(int));


		geraHadamard(1,n,mat);
		
		printf("Matriz Hadamard(%d)\n", n);
		for(i = 0 ; i < n ;i++)
		{
			for(j = 0 ; j < n ; j++) printf("%d ", mat[i][j]);

			printf("\n");
		}
	}

	

	return 0;
}