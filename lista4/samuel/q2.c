#include <stdio.h>
#include <stdlib.h>

int **mult(int m1, int n1, int **mat1,int m2, int n2, int **mat2)
{
	int i,j,k;
	
	//Aloca matriz resposta
	int **resp = (int**)malloc(m1 * sizeof(int*));

	for(i = 0 ; i < m1 ; i++) resp[i] = (int*)malloc(n2 * sizeof(int));
	// ------------------//


	for(i = 0 ; i < m1; i++)
	{
		
		for(j = 0 ; j < n2 ; j++)
		{
			resp[i][j] = 0;
			for(k = 0 ; k < n1 ; k++)
			{
				resp[i][j] += mat1[i][k] * mat2[k][j];	
			}
		}
	} 
	return resp;
}

int main()
{
	int m1,n1,m2,n2,i,j;
	int **mat1, **mat2;

	scanf("%d%d%d%d",&m1,&n1,&m2,&n2);

	//Alocação das Matrizes
	mat1 = (int**)malloc(m1 * sizeof(int*));

	for(i = 0 ; i < m1 ; i++) mat1[i] = (int*)malloc(n1 * sizeof(int));

	mat2 = (int**)malloc(m2 * sizeof(int*));

	for(i = 0 ; i < m2 ; i++) mat2[i] = (int*)malloc(n2 * sizeof(int));
	// ------------------------------- //

	for(i = 0 ; i < m1 ; i++)
	{
		for(j = 0 ; j < n1 ; j++)
		{
			scanf("%d",&mat1[i][j]);
		}
	}


	for(i = 0 ; i < m2 ; i++)
	{
		for(j = 0 ; j < n2 ; j++)
		{
			scanf("%d",&mat2[i][j]);
		}
	}

	if(n1 != m2) printf("Impossivel de multiplicar!\n");
	else
	{
		int **mat = mult(m1,n1,mat1,m2,n2,mat2);

		for(i = 0 ; i < m1 ; i++)
		{
			for(j = 0 ; j < n2 ; j++)
			{
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}
		// Desaloca
		for(i = 0 ; i < m1 ; i++) free(mat[i]);
		free(mat);
	}

	//Desaloca
	for(i = 0 ; i < m1 ; i++) free(mat1[i]);
	free(mat1);

	for(i = 0 ; i < m2 ; i++) free(mat2[i]);
	free(mat2);

	
	

	return 0;
}