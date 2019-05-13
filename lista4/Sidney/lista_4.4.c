#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void hadamard(int** mat,int n);


int main(void){

	int n;

	printf("Digite a Dimensão da Matriz H(N) : ");
	scanf("%d",&n);

	//aloca a matriz dinamicamente
	int **p = (int**) malloc(n*sizeof(int*));

	for(int i=0;i<n;i++){
		p[i] = (int*) malloc(n*sizeof(int));
	}

	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			p[i][j] = 1;
		}
	}
	
	hadamard(p,n);

		

	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			printf("%d ",p[i][j]);

		}
		printf("\n");
	}

	
	
	return 0;
}

void  hadamard(int** mat,int n){	
	
	int cont = 1;

	while(cont<=n){
		
		if(cont ==1){
			mat[0][0] = 1;
		}else{
			int q = cont/2;
			
			for(int i = 0 ; i < q; i++){
				for(int j = 0 ; j < q; j++){
					mat[i][q+j] = mat[i][j];
					mat[q+i][j] = mat[i][j];
					mat[q+i][q+j] = !mat[i][j];
				}
			}
		}
		cont = cont*2;
	}		
}
