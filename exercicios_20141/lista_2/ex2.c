/**
 * ERRADO
 * Substring
 *
 * Encontrar dentro da string S2 a maior substring de S1
 *
 * A ideia é criar uma variável t = 2 e a partir dai pegar
 * cada uma das sustring de tamanho 2 de S1 e comparar com
 * cada possível substring de tamanho 2 em S2, assim até que
 * a variável t for igual ao tamanho da string s1, dessa forma
 * garante-se que todas as possíveis substring serão comparadas.
 *
 * a variavel max indica o tamanho máximo já encontrado e
 * p1 e p2 em quais posições de S1 e S2 essa string máxima foi
 * encontrada
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  /**
   * ts = tamanho da string em cada interação
   * p1 e p2 são as posições da string em s1 e s2
   * max é o tamanho máximo da substring
   * */
  int t = 10, max = 0, p1 = 0, p2 = 0, ts = 2;

  char s1[] = "ACCTTTTGAA";
  char s2[] = "CACCCTTTTA";

  int lim = t-ts;

  for(int i = 0; i < lim; i++) {
    // pega a substring da string s1
    char sub_s1[ts];
    for (int k = 0; k < ts; k++) {
      sub_s1[k] = s1[k+i];
    }

    printf("Sub S1: %s TS: %d I: %d\n",sub_s1, ts, i);

    for(int j = 0; j < lim; j++) {
      // pega a substring da string s2
      char sub_s2[ts];

      for (int k = 0; k < ts; k++) {
        sub_s2[k] = s2[k+j];
      }

      // verifica se sub_s1 e sub_s2 são iguais
      int iguais = 1;
      for(int x = 0; x < ts; x++){
        if (sub_s1[x] != sub_s2[x]) {
          iguais = 0;
        }
      }

      if (iguais && (ts >= max)){
        max = ts;
        p1 = i;
        p2 = j;
      }
    }
    ts++;
  }

  printf("\nA maior sub-string tem %d caracteres e começa em S1 na posição %d e começa em S2 na posição %d.\n",max, p1, p2);
  for (int i = p1; i <= max; i++) {
    printf("%c",s1[i]);
  }
  printf("\n\n");


  return 0;
}