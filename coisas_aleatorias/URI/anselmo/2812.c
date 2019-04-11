#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n, c, n_impar = 0, tmp = 0;

  scanf("%d",&n);

  while (n > 0) {
    scanf("%d",&c);
    int *mat = (int*) malloc(sizeof(int)*c);

    n_impar = 0;
    for (int i = 0; i < c; i++) {
      scanf("%d",&tmp);
      if (tmp%2) {
        mat[n_impar] = tmp;
        n_impar++;
      }
    }

    for (int i = 0; i < n_impar; i++) {
      for (int j = i+1; j < n_impar; j++) {
        if (mat[i] > mat[j]) {
          tmp = mat[i];
          mat[i] = mat[j];
          mat[j] = tmp;
        }
      }
    }

    if (n_impar) {
      int limite = n_impar-1;
      for (int i = 0; i <= n_impar; i++) {
        if (limite < i) break;
        printf("%d",mat[limite]);
        if (limite != i) {
          printf(" %d",mat[i]);
          if ((limite-1) > i) {
            printf(" ");
          }
        }

        limite--;
      }
    }
    printf("\n");

    free(mat);
    n--;
  }
}