#include <stdio.h>
#include <string.h>

int linhas,colunas,quadrados;
int M[9][9];
int quadrado[10][10],coluna[10][10],linha[10][10];

int main()
{
    int n;
    scanf("%d",&n);
    int k = 1;
    while(n--)
    {
        linhas=1;
        colunas=1;
        quadrados=1;
        memset(quadrado, 0, sizeof quadrado);
        memset(coluna, 0, sizeof coluna);
        memset(linha, 0, sizeof linha);
        int i,j;
        for(i = 1 ; i <= 9 ; i++)
        {
            for(j = 1 ; j <= 9 ; j++)
            {

                scanf("%d",&M[i][j]);
                linha[i][M[i][j]] = 1;
                coluna[j][M[i][j]] = 1;
               
                if(i<=3 && j<=3)
                    quadrado[1][M[i][j]] = 1;
                else if(i<=3 && j<=6)
                    quadrado[2][M[i][j]] = 1;
                else if(i<=3 && j<=9)
                    quadrado[3][M[i][j]] = 1;
                else if(i<=6 && j<=3)
                    quadrado[4][M[i][j]] = 1;
                else if(i<=6 && j<=6)
                    quadrado[5][M[i][j]] = 1;
                else if(i<=6 && j<=9)
                    quadrado[6][M[i][j]] = 1;
                else if(i<=9 && j<=3)
                    quadrado[7][M[i][j]] = 1;
                else if(i<=9 && j<=6)
                    quadrado[8][M[i][j]] = 1;
                else if(i<=9 && j<=9)
                    quadrado[9][M[i][j]] = 1;

            }
        }


        for(i = 1 ; i <= 9 ; i++)
        {
            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;
            for(j = 1 ; j <= 9 ; j++)
            {
                
                if(coluna[i][j]) sum1++;
                if(quadrado[i][j]) sum2++;
                if(linha[i][j]) sum3++;
            }
           // printf("%d %d %d\n", sum1, sum2, sum3);
            if(sum1 != 9) colunas = 0;
            if(sum2 != 9) quadrados = 0;
            if(sum3 != 9) linhas = 0;
        }
        printf("Instancia %d\n",k++);
        if(linhas && colunas && quadrados)
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
    }
    
}

