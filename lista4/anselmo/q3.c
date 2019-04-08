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
char** s2ss_2(char *str);
char** s2ss_3(char *str);

int main(void) {

  char s[] = "/Fla/Flu/Bota/";

  //char** s2 = s2ss(s);
  char** s2 = s2ss_3(s);

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

char** s2ss_2(char *str) {
  int q = 0, t = 0, ant = 0, i, j, k;

  for( t = 0; str[t] != '\0'; t++) {
    if (str[t] == '/') q++;
  }

  char **x = (char**) malloc(sizeof(char*)*(q+1));

  int c = 0;

  for(i = 0; i < t; i++) {
    if(str[i] == '/') {
      ant = i+1;
      for(j = ant; (j < t && str[j] != '/');j++);
      int ts = j - ant;
      if (ts > 1) {
        x[c] = (char*) malloc(sizeof(char)*(ts+1));
        int p = 0;
        for(k = ant; k < j; k++) {
          x[c][p] = str[k];
          p++;
        }
        c++;
      }
      i = j-1;
    }
  }
  return x;
}

char** s2ss_3(char *str) {
  int j, qtd = 0;
  char **aux;
  for(int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '/') {
      qtd++;
      if (qtd == 1) {
        aux = (char**) malloc(sizeof(char*)*qtd);
      } else {
        aux = (char**) realloc(aux, sizeof(char*)*qtd);
      }
      for(j = i+1; (str[j] != '/' && str[j] != '\0' );j++);
      int ts = j - i;
      if (ts > 1) {
        aux[qtd-1] = (char*) malloc(sizeof(char)*(ts+1));
        int p = 0;
        for(int k = i+1; k < j; k++) {
          aux[qtd-1][p] = str[k];
          p++;
        }
      }
      i = j-1;
    }
  }
  return aux;
}
