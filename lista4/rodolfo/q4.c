#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int ** construir_hadamard( int ** matriz, int ordem){
int ii, xx, yy;

matriz[0][0]= 1;


for(ii=2; ii<=ordem; ii*=2) {

    for(xx=0; xx<(ii/2); ++xx) {
        for(yy=(ii/2); yy<ii; ++yy){
            matriz[xx][yy]=matriz[xx][yy-(ii/2)];                          
        }
    }

    for(yy=0; yy<(ii/2); ++yy) {
        for(xx=(ii/2); xx<ii; ++xx) {
            matriz[xx][yy]=matriz[xx-(ii/2)][yy];
        }
    }

    for(xx=(ii/2); xx<ii; ++xx) {
        for(yy=(ii/2); yy<ii; ++yy) {
            matriz[xx][yy]=matriz[xx-(ii/2)][yy-(ii/2)];
            if(matriz[xx][yy]==1) {
                matriz[xx][yy]=0;
            }
            else {
                matriz[xx][yy]=1;
            }
        }
    }
}

	return matriz;
}



int main(int argc, char const *argv[])
{
	
	printf("Digite a ordem da matriz de Hadamard: ");
	int n;
	scanf(" %d", &n);
	int i,j;
	int ** matriz = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++){
		matriz[i] = (int*)malloc(sizeof(int)*n);
	}

	
	int ** matriz_hadamard = construir_hadamard(matriz, n);

	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++){
			printf("%d", matriz[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++){
		free(matriz[i]);
	}

	free(matriz);
	/* code */
	return 0;
}
