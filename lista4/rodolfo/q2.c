#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int ** multi( int m1, int n1, int mat1[][m1], int m2, int n2, int mat2[][m2]){
	if ( n1 == m2){
		int **resp = (int **) malloc(sizeof(int*)*m1);
		int i;
		for (i = 0; i < m1 ; i++)
			resp[i] = (int*)malloc(sizeof(int)*n2);
		int j,k,l;
		for ( j = 0; j < m1; j++){
			for( k = 0; k < n2; k++){
				for( l = 0; l < n1 ; l++){
						resp[j][k] = resp[j][k] + mat1[j][l]*mat2[l][k];	
				}
			}
		}

		return resp;
	}else{
		return NULL;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int mat1[][3] = {
					{1,2,3},
					{0,1,4},
					};
	int mat2[][5] = {
					{1,3,4,5,6},
					{0,4,3,2,1},
					{-1,3,5,0,0}
					};

	int m1 = sizeof(mat1)/sizeof(mat1[0]);
	int n1 = sizeof(mat1)/sizeof(mat1[0][0])/m1;
	int m2 = sizeof(mat2)/sizeof(mat2[0]);
	int n2 = sizeof(mat2)/sizeof(mat2[0][0])/m2;



	int ** resp = multi(m1,n1, mat1, m2, n2, mat2);


	if (resp != NULL){
		int j,k;
		printf("O resultado da multiplicação entre: \n");
		printf("\n");
		for ( j = 0; j < m1; j++){
			for(k = 0; k < n1; k++){
				printf("%d ", mat1[j][k]);
			}
			printf("\n");
		}
		printf("\n");
		printf("e \n");
		printf("\n");
		for ( j = 0; j < m2; j++){
			for(k = 0; k < n2; k++){
				printf("%d ", mat2[j][k]);
			}
			printf("\n");
		}
		printf("\n");
		printf("será \n");
		printf("\n");

		for ( j = 0; j < m1; j++){
			for(k = 0; k < n2; k++){
				printf("%d ", resp[j][k]);
			}
			printf("\n");
		}
	}else{
		printf("As matrizes não podem ser multiplicadas!\n");
	}

	int i;
	for (i= 0; i < m2; i++)
		free(resp[i]);
	free(resp);


	return 0;
}