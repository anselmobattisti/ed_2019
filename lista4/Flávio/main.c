/*
Este programa foi desenvolvido por Flavio Miranda de Farias
Para disciplina Estrutura de Dados e Algoritmos 2019-1
Professora Isabel Rosseti - UFF
Lista de exercícios 04
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 9

int isSoduku(int matriz[N][N]){
    int linha,coluna,contador=0,tamanho=N;
     printf("\n");
    for(linha = 0; linha < tamanho; linha++){
        for(coluna = 0; coluna < tamanho; coluna++)
            if(matriz[linha][linha]==matriz[linha][coluna])
                 contador++;
        if(contador>1)
            return 0;
        else
            contador=0;
    }
    return 1;
}
void Q01(){
    int tamanho=N, linha,coluna;
    int matriz[N][N] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                       {6, 7, 2, 1, 9, 5, 3, 4, 8},
                       {1, 9, 8, 3, 4, 2, 5, 6, 7},
                       {8, 5, 9, 7, 6, 1, 4, 2, 3},
                       {4, 2, 6, 8, 5, 3, 7, 9, 1},
                       {7, 1, 3, 9, 2, 4, 8, 5, 6},
                       {9, 6, 1, 5, 3, 7, 2, 8, 4},
                       {2, 8, 7, 4, 1, 9, 6, 3, 5},
                       {3, 4, 5, 2, 8, 6, 1, 7, 9}};
    for(int linha = 0; linha < tamanho; linha++){
        for(int coluna = 0; coluna < tamanho; coluna++)
             printf("%2d", matriz[linha][coluna]);
        printf("\n");
    }
    if(isSoduku(matriz)==1)
        printf("\nE Soduku!");
    else
        printf("\nNao e Soduku!");
}

void imprimeMatriz(int **matriz, int taml, int tamc){
    int linha,coluna;
    for(linha=0;linha<taml;linha++){
        for(coluna=0;coluna<tamc;coluna++)
            printf("%d ",matriz[linha][coluna]);
        printf("\n");
    }
    printf("\n");
}
int** alocaMatriz(int **matriz, int taml, int tamc){
    int linha;
    matriz=(int**)malloc(sizeof(int*)*taml);
    for(linha=0;linha<taml;linha++)
        matriz[linha]=(int*)malloc(sizeof(int)*tamc);
    return matriz;
}
int** mult(int m1, int n1, int **mat1, int m2, int n2, int **mat2){
    int linha, coluna,**matProduto,somaprod,i;
    matProduto=alocaMatriz(matProduto,m1,n2);
    for(linha=0;linha<m1;linha++)
        for(coluna=0;coluna<m1;coluna++){
            somaprod=0;
            for(i=0; i<m1; i++)
                somaprod+=mat1[linha][i]*mat2[i][coluna];
            matProduto[linha][coluna]=somaprod;
        }
    return matProduto;
}
void Q02(){
    int m1=3,n1=3,**mat1,m2=3,n2=3,**mat2,linha,coluna,**matProduto;
    //só é possivel realizar a multiplicação de matrizes se a quantidade de coluna da primeira for igual quantidade de linhas da segunda
    if(n1!=m2){
        printf("\nNao e possivel realizar a multiplicacao de matrizes\n");
        return 0;
    }
    mat1=alocaMatriz(mat1,m1,n1);
    for(linha=0;linha<m1;linha++)
        for(coluna=0;coluna<m1;coluna++)
            mat1[linha][coluna]=linha+coluna;
    mat2=alocaMatriz(mat2,m2,n2);
    for(linha=0;linha<m2;linha++)
        for(coluna=0;coluna<m2;coluna++)
            mat2[linha][coluna]=(linha+1)*(coluna+1);
    imprimeMatriz(mat1,m1,n1);
    imprimeMatriz(mat2,m2,n2);
    printf("\nA nova Matriz e:\n");
    matProduto=alocaMatriz(matProduto,m1,n2);
    matProduto=mult(m1,n1,mat1,m2,n2,mat2);
    imprimeMatriz(matProduto,m1,n2);
}
int contPalavras(char *str){
    int i,cont=0, tam=strlen(str)-1;
    for(i=0;i<tam;i++)
        if(str[i]=='/')
            cont++;
    if(str[0])
        cont--;
    if(str[tam])
        cont--;
    return ++cont;
}
char** s2ss(char *str){
    int palavras=contPalavras(str),i=0,j=0,k=0,p;
    char **resposta=(char**)malloc(sizeof(char*)*palavras);
    while(str[i]!='\0'){
        // achou uma barra
        if(str[i]=='/'){
            // acha a próxima barra
            for(j=i+1;str[j]!= '/' && str[j]!='\0';j++)
                resposta[k]=(char*)malloc(sizeof(char)*(j-i));
            int temp=0;
            for(p=i+1;p<j;p++){
                resposta[k][temp]=str[p];
                temp++;
            }
            k++;
        }
        i++;
    }
    return resposta;
}
void Q03(){
    char *stringOriginal="/Fla/Flu/Bota/",**stringResultante;
    printf("\nString Original: %s\n",stringOriginal);
    stringResultante=s2ss(stringOriginal);
    for(int i = 0; i < 3; i++){
        for(int j = 0; stringResultante[i][j] != '\0'; j++)
            printf("%c",stringResultante[i][j]);
        printf("\n");
    }
}

int ** construir_hadamard( int ** matriz, int ordem){
    int ii, xx, yy;
    matriz[0][0]=1;
    for(ii=2; ii<=ordem; ii*=2){
        for(xx=0; xx<(ii/2); ++xx)
            for(yy=(ii/2); yy<ii; ++yy)
                matriz[xx][yy]=matriz[xx][yy-(ii/2)];
        for(yy=0; yy<(ii/2); ++yy)
            for(xx=(ii/2); xx<ii; ++xx)
                matriz[xx][yy]=matriz[xx-(ii/2)][yy];
        for(xx=(ii/2); xx<ii; ++xx)
            for(yy=(ii/2); yy<ii; ++yy){
                matriz[xx][yy]=matriz[xx-(ii/2)][yy-(ii/2)];
                if(matriz[xx][yy]==1)
                    matriz[xx][yy]=0;
                else
                    matriz[xx][yy]=1;
            }
    }
	return matriz;
}
void Q04(){
    printf("Este eu pedi arrego e copiei do anselmo mesmo! kkkkkkk\n\n");
	printf("Digite a ordem da matriz de Hadamard: ");
	int n,i,j;
	scanf(" %d", &n);
	int ** matriz = (int**)malloc(sizeof(int*)*n);
	for (i = 0; i < n; i++)
		matriz[i] = (int*)malloc(sizeof(int)*n);
	int **matriz_hadamard = construir_hadamard(matriz, n);
	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++)
			printf("%d", matriz[i][j]);
		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(matriz[i]);
	free(matriz);
}

int menu(){
    char op;
    while(1){
        system("cls");
        printf("Lista de exercicios 04 - 2019.1\n\n");
        printf("Digite o valor do menu a baixo\n\n");
        printf("1 - Exercicio 01\n");
        printf("2 - Exercicio 02\n");
        printf("3 - Exercicio 03\n");
        printf("4 - Exercicio 04\n");
        printf("Outro - Para sair\n\n---> ");
        scanf (" %c", &op);
        printf("\n");
        switch (op){
        case '1':
            printf("Dada uma matriz quadrada de dimensão 9, com valores de 1 a 9 em suas posições, escreva um programa que verifique se esta matriz é uma solução válida para o Sudoku (isto é, uma solução é válida no Sudoku se cada linha, cada coluna e cada bloco contém os números de 1 a 9 somente uma vez).");
            printf("\n\n");
            Q01();
            system("pause");
            break;
        case '2':
            printf("Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1 representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2)");
            printf("\n\n");
            Q02();
            system("pause");
            break;
        case '3':
            printf("Escreva uma função que dada uma string composta por substrings separadas por “/”, retorne todas as suas substrings da string original. Por exemplo, a string /Fla/Flu/Bota/ será decomposta em:\n\nFla\nFlu\nBota\nEsta função não deve modificar a string original. O protótipo da função é o seguinte: char** s2ss (char *str). Isto é, a resposta desta função será uma matriz de caracteres alocada dinamicamente.");
            printf("\n\n");
            Q03();
            system("pause");
            break;
        case '4':
            printf("A matriz de Hadamard H(N), usada em projetos de programas corretores de erros, é uma matriz N por N, onde N é potência de dois, de elementos booleanos (isto é, elementos 0 e 1) que satisfaz a seguinte propriedade: dadas duas linhas distintas i e j, onde 0 <= i < N e 0 <= j < N, desta matriz, a quantidade de elementos distintos nestas linhas é sempre igual a N/2. Abaixo exemplica-se H(1), H(2) e H(4).\nPara construir H(M), onde M = 2 * N, divide-se a matriz H(M) em quatro partes iguais, chamadas de quadrantes, repete-se três vezes a matriz H(N) nos quadrantes de menores índices, e no quadrante de maiores índices de H(M), inverte-se a matriz H(N). Implemente um programa que imprima a matriz H(N) na console. A dimensão desta matriz deve ser lida pelo seu programa.");
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

void main(){
    menu();
}
