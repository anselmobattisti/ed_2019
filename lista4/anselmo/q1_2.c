#include <stdio.h>

int main(void) {
  int n;
  int instancia = 0;
  int num;

  scanf("%d",&n);
  while(n > 0) {
    instancia++;
    n--;
    int  m[9][9];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        scanf("%d",&num);
        m[i][j] = num;
      }
    }

    int sol = 1;

    // verifica se existe algum número repetido em alguma linha
    // ou em alguma coluna
    for (int i = 0; i < 9; i++) {
      int aux_c[9] = {0,0,0,0,0,0,0,0,0};
      int aux_l[9] = {0,0,0,0,0,0,0,0,0};
      for(int j = 0; j < 9; j++) {
        aux_l[m[i][j]%9] += 1;
        aux_c[m[j][i]%9] += 1;
      }
      for(int k = 0; k < 9; k++) {
        if(aux_l[k] != 1 || aux_c[k] != 1) {
          sol = 0;
          break;
        }
      }
    }

    if (sol) {
      for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
          int aux[9] = {0,0,0,0,0,0,0,0,0};
          // verifca dentro de cada um dos quadrantes.
          for (int k = i; k < i+3; k++) {
            for (int w = j; w < j+3; w++) {
              aux[m[k][w]%9] += 1;
            }
          }
          for(int k = 0; k < 9; k++) {
            if(aux[k] != 1){
              sol = 0;
              break;
            }
          }
        }
      }
    }

    printf("Instancia %d",instancia);
    if (sol) {
      printf("\nSIM\n\n");
    } else {
      printf("\nNAO\n\n");
    }
  }

  return 0;
}