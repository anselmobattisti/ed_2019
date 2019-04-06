/*
Q3) Escreva uma função que dada uma string composta por substrings separadas por “/”, retorne
todas as suas substrings da string original. Por exemplo, a string /Fla/Flu/Bota/ será decomposta
em:
Fla
Flu
Bota
Esta função não deve modificar a string original. O protótipo da função é o seguinte: char** s2ss
(char *str). Isto é, a resposta desta função será uma matriz de caracteres alocada
dinamicamente.
*/
#include <stdio.h>
#include <stdlib.h>

char** s2ss(char *str);

int main(void) {

  char s[] = "/Fla/Flu/Bota/";

  char** s2 = s2ss(s);

  for (int i = 0; i < 3; i++){
    printf("\n");
    for (int j = 0; s2[i][j] != '\0'; j++){
      printf("%c",s2[i][j]);
    }
    printf("\n");
  }

  return 0;
}

char** s2ss(char *str) {
  // contar quantas \ existem
  int oc = 0;
  for(int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '/'){
      oc++;
    }
  }
  char** n = (char**) malloc(sizeof(char*)*oc);

  // criar dinamicamente dentro de cada linha o número de elementos necessarios
  // /Fla/Flu/Bota/
  int i = 0;
  int j = 0;
  int k = 0;
  while (str[i] != '\0') {
    // achou uma barra
    if (str[i] == '/') {

      // acha a próxima barra
      for (j = i+1; str[j] != '/' && str[j] != '\0'; j++);

      n[k] = (char*) malloc(sizeof(char) * (j-i));
      int tmp = 0;
      for (int p = i+1; p < j; p++) {
        n[k][tmp] = str[p];
        tmp++;
      }

      k++;
    }
    i++;
  }
  return n;
}