//Vetores estáticos
#include <stdio.h>
void main(){
    int n;
    printf("Digite o tamanho do vetor, após isso, os valores:\n");
    scanf(" %d", &n);
    if(n<=0)
        return 0;
    int vet[n];
    for(int i=0; i<n; i++)
        scanf(" %d", &vet[i]);
    dobra(n,vet);
    for(int i=0; i<n; i++)
        printf("%d ", vet[i]);
}
void dobra(int n, int *vet){
    for(int i=0; i<n; i++)
        vet[i] *= 2;
}

