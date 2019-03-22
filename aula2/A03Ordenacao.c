//Ordenação - Selection Sort, Buble Sort e Insertion Sort
#include <stdio.h>
#include <stdlib.h>

const int n = 5;

int menu(int *vet);
void selectionSort(int n, int *vet);
void bubbleSort(int n, int *vet);
void insertionSort(int n, int *vet);

void main(){
    int vet[] = {30, 20, 50, 40, 10};
    menu(vet);
}

void selectionSort(int n, int *vet){
    int i,j, temp;
    for(i=0; i<n; i++){
        int menor=i;
        for(j=i+1; j<n; j++){
            if(vet[j]<vet[menor])
                menor=j;
            if(menor != i){
                temp = vet[i];
                vet[i]=vet[menor];
                vet[menor]=temp;
            }
        }
    }
}
void bubbleSort(int n, int *vet){
    int i,j, temp;
    for(i=1; i<n; i++)
        for(j=0; j<n-1; j++)
            if(vet[j]>vet[j+1]){
                temp = vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=temp;
            }
}
void insertionSort(int n, int *vet){
   int i, j, temp;
   for (i = 1; i < n; i++){
      temp = vet[i];
      j = i - 1;
      while (j >= 0 && temp < vet[j]) {
         vet[j+1] = vet[j];
         j--;
      }
      vet[j+1] = temp;
   }
}
void listar(int n, int *vet){
    printf("Este e o vetor ordenado: ");
    for(int i=0; i<n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}
int menu(int *vet){
    char op;
    while(1){
        system("cls");
        printf("Digite o valor da opcao\n");
        printf("1 - Para Selection Sort\n");
        printf("2 - Para Bubble Sort\n");
        printf("3 - Para Insertion Sort\n");
        printf("Outro - Para sair\n--->");
        scanf (" %c", &op);
        switch (op){
        case '1':
            selectionSort(n, vet);
            listar(n, vet);
            system("pause");
            break;
        case '2':
            bubbleSort(n, vet);
            listar(n, vet);
            system("pause");
            break;
        case '3':
            insertionSort(n, vet);
            listar(n, vet);
            system("pause");
            break;
        default:
            printf("\nFinalizando sistema... Tchau!\n");
            return 0;
            break;
        }
    }
}
