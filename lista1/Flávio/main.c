/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 01
*/

#include <stdio.h>

int main(){
    menu();
    return 0;
}
int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 01 - 2019.1\n\n");
        printf("Digite o valor do menu a baixo\n\n");
        printf("1 - Exercicio 01\n");
        printf("2 - Exercicio 02\n");
        printf("3 - Exercicio 03\n");
        printf("4 - Exercicio 04\n");
        printf("5 - Exercicio 05\n");
        printf("6 - Exercicio 06\n");
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n\n");
        switch (op){
        case '1':
            printf("Escreva um programa que, infinitamente, leia um número inteiro n, que representa o tamanho, seguida de uma sequência de n números inteiros, e determine o comprimento máximo de um segmento crescente destes n números. Exemplos:\n Na sequência 5, 10, 3, 2, 4, 7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.\n Na sequência 10, 8, 7, 5, 2 o comprimento de um segmento crescente máximo é 1.\nSeu programa para quando n for menor ou igual a zero.");
            printf("\n\n");
            Q01();
            system("pause");
            break;
        case '2':
            printf("Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne os n primeiros números primos existentes. Seu programa para quando n for menor ou igual a zero.");
            printf("\n\n");
            Q02();
            system("pause");
            break;
        case '3':
            printf("Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e um número m, e retorne todas as potências de m, menores que n. Por exemplo, se n = 1000 e m = 2, seu programa deve imprimir os seguintes números: 1, 2, 4, 8, 16, 32, 64, 128, 256 e 512. Seu programa para quando n for menor que 1 ou quando m for 0, ou 1 ou -1.");
            printf("\n\n");
            Q03();
            system("pause");
            break;
        case '4':
            printf("Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa para quando n for menor ou igual a zero.");
            printf("\n\n");
            Q04();
            system("pause");
            break;
        case '5':
            printf("Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste programa deve ser “1100”. Seu programa para quando n for menor que zero.");
            printf("\n\n");
            Q05();
            system("pause");
            break;
        case '6':
            printf("Informe os valores de teste, x, y e z depois da avaliação das seguintes expressões:\nint x, y, z;\nint teste;\nx = 5;\ny = x++;\nz = x--;");
            printf("\n\n");
            Q06();
            system("pause");
            break;
        default:
            printf("Finalizando sistema... Tchau!\n");
            return 0;
            break;
        }
    }
}

int Q01(){
    while(1){
        int n,i,cont=1,tam=0;
        printf("\nDigite o valor de n\n---> ");
        scanf(" %d",&n);
        if(n<=0)
            return 0;
        int vet[n];
        printf("\nEstes sao os numeros: ");
        for(i=0;i<n;i++){
            vet[i]=rand()%5;//gera valores aleatorios
            printf("%d ",vet[i]);
        }
        for(i=0;i<n-1;i++)
            if(vet[i]<vet[i+1]){
                cont++;
                if(cont>=tam)
                    tam=cont;
            }else{
                if(cont>=tam)
                    tam=cont;
                cont=1;
            }
        printf("\n\nO comprimento do segmento crescente maximo e %d\n",tam);
    }
    return 0;
}

int Q02(){
    while(1){
        int n,i,cont=0;
        printf("\nDigite um numero inteiro e positivo para n\n---> ");
        scanf(" %d",&n);
        if(n<=0)
            return 0;
        while(n>0){
            for(i=1;i<=n;i++)
                if((n%i)==0)
                    cont++;
            if(cont==2||n==1)
                printf("%d ",n);
            n--;
            cont=0;
        }
    }
    return 0;
}

int Q03(){
    while(1){
        int n,m,i=1;
        printf("\n\nDigite um numero inteiro e positivo para n\n---> ");
        scanf(" %d",&n);
        if(n<=0)
            return 0;
        printf("\nDigite um numero inteiro e positivo para m\n---> ");
        scanf(" %d",&m);
        if(m==0 || m==1 || m==-1)
            return 0;
        if(m>=n){
            printf("\nNao ha potencias entre esses numeros\n---> ");
            return 0;
        }
        printf("\nEstes sao os numeros: ");
        while(i<=n){
            printf("%d ",i);
            i=i*m;
        }
    }
    return 0;
}

int isPrime(int n) {
    if(n%2 == 0)
        return 0;
    int metade = n/2, i;
    for(i=3; i<=metade;i+= 2)
        if(n%i==0)
            return 0;
    return 1;
}
int Q04(){
    while(1){
        int n,count;
        printf("\n\nDigite um numero inteiro e positivo para n\n---> ");
        scanf(" %d",&n);
        if(n<=0)
            return 0;
        count = n;
        while (count){
          if (isPrime(n)) {
            count--;
            printf("%d ", n);
          }
          n++;
        }
    }
    return 0;
}

int Q05(){
    while(1){
        int n,i=0,j;
        printf("\n\nDigite um numero inteiro e positivo para n\n---> ");
        scanf(" %d",&n);
        if(n<0)
            return 0;
        int vet[n];
        printf("\nEstes e o equivalente binario pra %d: ",n);
        if(n==0 || n==1)
            printf("%d ",n);
        else{
            do{
                vet[i]=n%2;
                i++;
                n=n/2;
            }while(n>=1);
            for(j=i-1;j>=0;j--)
                printf("%d",vet[j]);
        }
    }
    return 0;
}

void Q06(){
    int x, y, z;
    int teste;
    x = 5;
    y = x++;
    z = x--;
    printf("\n\nOs valores de x=%d, y=%d, z=%d, teste=%d",x,y,z,teste);
    teste = !y == !x;
    printf("\n\n(A) teste = !y == !x; ---> %d",teste);
    teste = ((x++ > y) || (--z <= y));
    printf("\n\n(B) teste = ((x++ > y) || (--z <= y)); ---> %d",teste);
    teste = ((x++ > y) || (--z <= y));
    printf("\n\n(C) teste = ((!x) || (!(!z))); ---> %d",teste);
    teste = (((x + y) > z) && (x++));
    printf("\n\n(D) teste = (((x + y) > z) && (x++)); ---> %d",teste);
    teste = x && y + !3 || 4;
    printf("\n\n(E) teste = x && y + !3 || 4; ---> %d\n\n",teste);
}
