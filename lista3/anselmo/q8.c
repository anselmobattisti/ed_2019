/*
Q8) Escreva uma função que dadas duas strings, retorne UM se a primeira contém a segunda,
ignorando maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: int
cic (char *str1, char *str2).
*/
#include <stdio.h>
#include <stdlib.h>

int cic (char *str1, char *str2);

int main(void) {

  char str1[] = "meu nome";
  char str2[] = "Nome";

  if (cic(str1,str2)) {
    printf("\n\nSim\n\n");
  } else {
    printf("\n\nNão\n\n");
  }

  return 0;
}

/*
 * Intervalo das letras
 * A = 65
 * Z = 90
 * a = 97
 * z = 122
 */
int cic (char *str1, char *str2) {

  int tam1, tam2;

  for(tam1=0; str1[tam1] != '\0'; tam1++){
    // converte em minúscula as maiúsculas
    if(str1[tam1] >= 65 && str1[tam1] <= 90) {
      str1[tam1] += 32;
    }
  }

  for(tam2=0; str2[tam2] != '\0'; tam2++){
    if(str2[tam2] >= 65 && str2[tam2] <= 90) {
      str2[tam2] += 32;
    }
  }

  if (tam2 > tam1) return 0;

  int i,j, igual;
  for (i = 0; i <= (tam1-tam2); i++) {
    igual = 1;
    for (j = 0; j < tam2; j++) {
      if(str1[i+j] != str2[j]){
        igual = 0;
        break;
      }
    }
    if (igual) {
      return 1;
    }
  }

  return 0;
}