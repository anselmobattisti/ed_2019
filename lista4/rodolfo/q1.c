#include <stdlib.h>
#include <stdio.h>

void ** checar_linhas(int  mat[][9], int * flag){
	int i,j, soma;
	
	for ( i = 0; i <= sizeof(&mat); i++){
		if (*flag == 0){
			soma = 0;
			for ( j = 0; j <= sizeof(&mat); j++){
				soma = soma + mat[i][j];
			}
			if ( soma != 45)
				*flag = 1;
		}
	}
}

void ** checar_colunas(int mat[][9], int * flag){
	int i,j, soma;
	
	for ( i = 0; i <= sizeof(&mat); i++){
		if (*flag == 0){
			soma = 0;
			for ( j = 0; j <= sizeof(&mat); j++){
				soma = soma + mat[j][i];
			}

			if ( soma != 45)
				*flag = 1;
		}
	}
}


void ** checar_blocos(int  mat[][9], int * flag){
	int i,j, k, l, soma;

	for ( i = 0; i < 3; i++){
		if (*flag == 0){
			for ( j = 0; j< 3; j++){
				if (*flag == 0){
					soma = 0;
					for ( k = 3*i; k < 3*(i+1); k++){
						for (l = 3*j; l < 3*(j+1); l++){
							soma = soma + mat[k][l];
						}
					}		
					if ( soma != 45)
						*flag = 1;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int mat[][9] = {
						{5,3,4,6,7,8,9,1,2},
						{6,7,2,1,9,5,3,4,8},
						{1,9,8,3,4,2,5,6,7},
						{8,5,9,7,6,1,4,2,3},
						{4,2,6,8,5,3,7,9,1},
						{7,1,3,9,2,4,8,5,6},
						{9,6,1,5,3,7,2,8,4},
						{2,8,7,4,1,9,6,3,5},
						{3,4,5,2,8,6,1,7,9}

					};

	int flag = 0;

	checar_linhas( mat, &flag);
	if (flag == 0)
		checar_colunas( mat, &flag);
	if (flag == 0)
		checar_blocos( mat, &flag);

	if (flag == 1){
		printf("Sudoku não resolvido\n");
	}else{
		printf("Sudoku resolvido\n");
	}

	return 0;
}