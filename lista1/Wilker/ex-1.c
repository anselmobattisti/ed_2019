#include <stdio.h>
#include <stdlib.h>


// Cria uma matriz de inteiros alocada dinamicamente
int** new_matrix(int rows, int  columns) {
	int** matrix = (int**) malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int*) malloc(sizeof(int) * columns);
	}
	return matrix;
}

// Le do teclado os elementos de uma matriz de inteiros
int** read_matrix(int** mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}

void show_matrix(int** mat, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		if (i > 0 && i % 3 == 0) {
			printf(" --------+---------+-------- \n");	
		}
		for (int j = 0; j < columns; j++) {
			if (j > 0 && j % 3 == 0) printf("|");
			printf(" %d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void print_vetor(int *vet,int tam){
    int i = 0;
    for (i = 0; i < tam; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int linha_valida(int **mat, int m, int n){
    int i = 0;
    for ( i = 0; i <  m; i++){
        int aux[n];
        int j = 0 ;
        for (j = 0; j < n; j++){
            aux[j]=0;
        }
        for (j = 0; j < n; j++){
            aux[mat[i][j]-1]++;
            if(aux[mat[i][j]-1]>1){
                return 0;
            }
        }
    }
    return 1;
}

int coluna_valida(int **mat, int m, int n){
    int i = 0;
    for ( i = 0; i <  m; i++){
        int aux[n];
        int j = 0 ;
        for (j = 0; j < n; j++){
            aux[j]=0;
        }
        for (j = 0; j < n; j++){
            aux[mat[i][j]-1]++;
            if(aux[mat[i][j]-1]>1){
                return 0;
            }
        }
    }
    return 1;
}

int valido(int ** mat, int m, int n){
    int aux[m*n];
    int i=0, j=0;
    for (i = 0; i < m*n; i++){
        aux[i]=0;
    }
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            aux[mat[i][j]-1]++;
            if (aux[mat[i][j]-1] >1)  
            {
                return 0;
            }
        }
    }
    return 1;    
}

int bloco_valido(int **mat, int m, int n){
    int i =0,j=0;
    for (i = 0; i < m/3; i++){
        for (j = 0; j < m/3; j++){
            if(!valido(&mat[i*3],m/3,n/3))
            return 0;
        }
    }
    return 1;
}

int sudoku_valido(int **mat, int m, int n){
    if(!mat) return 0;
    if(linha_valida(mat,m,n) &&
        coluna_valida(mat,m,n) &&
        bloco_valido(mat,m,n)){
        return 1;
    }
    return 0;
}


int main(int argc, char *argv[]){
    int m = 9;
    int n = 9;
    int** mat = new_matrix(m, n);
    read_matrix(mat, m, n);
    show_matrix(mat, m, n);

    printf("Linha válida? %d \n", linha_valida(mat,m,n));
    printf("Coluna válida? %d \n", coluna_valida(mat,m,n));
    printf("Bloco válido? %d \n", bloco_valido(mat,m,n));
    printf("Sudoku válido? %d \n", sudoku_valido(mat,m,n));
    return 0;
}
