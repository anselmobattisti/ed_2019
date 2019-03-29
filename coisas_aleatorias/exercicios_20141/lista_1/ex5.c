/*
  Parece simples mas se cair isso na prova dá trabalho
  e a chance de errar é grande!

  A ideia aqui é ir recebendo número inteiros,
  para quando receber um número negativo;

  A cada interação verificar se o número recebido é maior
  do que o último valor maior, se sim, incrementa um contador
  que define o tamanho da maior sequência, caso contrário
  esse contador deve ser setado para 1;

  Ao final imprime o número do contador
*/

#include <stdio.h>

int main(void) {
  int n = 0;
  int tmp = -1;
  int c = 0;
  int max = 0;

  while (n >= 0) {
    printf("\nDigite o valor: ");
    scanf("%d",&n);

    if (tmp < n) {
      tmp = n;
      c++;
    } else {
      // atualiza o valor máximo
      if (c > max) {
        max = c;
      }

      // zera o contador
      if (n >= 0) {
        c = 0;
        tmp = -1;
      }
    }
    // printf("n=%d tmp=%d c=%d max=%d", n, tmp, c, max);
  }

  printf("\nA maior sequência teve %d números.\n\n", max);
}






