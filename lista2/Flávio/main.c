/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 02
*/

#include <stdio.h>
#include <string.h>

void main(){
    menu();
}
int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 02 - 2019.1\n\n");
        printf("Digite o valor do menu a baixo\n\n");
        printf("1 - Exercicio 01\n");
        printf("2 - Exercicio 02\n");
        printf("3 - Exercicio 03\n");
        printf("4 - Exercicio 04\n");
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n\n");
        switch (op){
        case '1':
            printf("Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2 e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscamse todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se encontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A figura seguinte apresenta o método para n = 40.");
            printf("\n\n");
            Q01();
            system("pause");
            break;
        case '2':
            printf("Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x2 + 2x + 12 terá um vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x3 + x2 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve, infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b) calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.");
            printf("\n\n");
            Q02();
            system("pause");
            break;
        case '3':
            printf("Um número a é dito permutação de um número b se os dígitos de a formam uma permutação dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.: Considere que o dígito 0 (zero) não deve aparecer nos números.");
            printf("\n\n");
            Q03();
            system("pause");
            break;
        case '4':
            printf("Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou “FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o número for negativo.");
            printf("\n\n");
            Q04();
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
    int n,i,j,x,mult;
    printf("\nDigite o valor de n\n---> ");
    scanf(" %d",&n);
    if(n<=1)
        return 0;
    int vet[n];
    for(i=2;i<=n;i++)
        vet[i]=i;
    for(mult=2;mult<=5;mult++)
        for(j=mult;j<=n;j+=mult)
            if(vet[j]!=mult)
                vet[j]=0;
    for(x=2;x<=n;x++)
        if(vet[x]!=0)
            printf("%d ",vet[x]);
    printf("\n");
    return 0;
}

int Q02(){
    printf("\nEste programa trabalha com integrais e dedivadas, como nao fui eu quem fez, não posso ajudar... kkk\n");
    int g,i;
    while(scanf(" %d",&g) && g>0){
        g++;
        double poli[g], derivada[g-1], integral[g+1];
        for(i=0;i<g;i++)
            scanf("%1f",poli+1);
        integral[0]=0;
        for(i=1;i<g+1;i++)
            integral[i]=poli[i-1]/i;
        for(i=0;i<g-1;i++)
            derivada[i]=poli[i+1]*(i+1);
        printf("\nIntegral:\n");
        for(i=0;i<g+1;i++)
            printf("%.1f ",integral[i]);
        printf("\nDerivada:\n");
        for(i=0;i<g-1;i++)
            printf("%.1f ",derivada[i]);
        printf("\n\n");
    }
    return 0;
}

int Q03(){
    char a[10],b[10],i,j,tama,tamb,conta=0,contb;
    printf("\nDigite o valor de a\n---> ");
    scanf("%s",&a);
    printf("\nDigite o valor de b\n---> ");
    scanf("%s",&b);
    for(i=0;a[i]!='\0';i++)
        if(a[i]=='0')
            return 0;
    for(i=0;b[i]!='\0';i++)
        if(b[i]=='0')
            return 0;
    tama=strlen(a);
    tamb=strlen(b);
    if(tama!=tamb)
        return 0;
    for(i=0;a[i]!='\0';i++)
        for(j=0;b[j]!='\0';j++){
            if(a[i]==b[j]){
                a[i]='x';
                b[j]='x';
                break;
            }
        }
    if(strcmp(a,b)==0)
        printf("\nOs valores sao permutacoes\n");
    else
        printf("\nOs valores nao sao permutacoes\n");
    return 0;
}

int Q04(){
    while(1){
        char nome[10];
        int i,j,tamanho,cont=0;
        printf("\nDigite um valor para palindrome\n---> ");
        scanf(" %s",&nome);
        if(nome[0]=='-')
            return 0;
        tamanho=strlen(nome);
        for(i=0,j=tamanho-1;i<(tamanho/2)-1;i++,j--)
            if(nome[i]!=nome[j])
                cont++;
        if(cont>0)
            printf("\nFALSO\n");
        else
            printf("\nVERDADEIRO\n");
    }
    return 0;
}
