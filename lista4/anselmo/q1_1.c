#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int **m = (int**) malloc(sizeof(int*) * 9);
  for (int i = 0; i < 9; i++) {
    m[i] = (int*) malloc(sizeof(int)*9);
  }

 // gera entrada com sucesso
  int aux[9][9] = {
      {5,3,4,6,7,8,9,1,2},
      {6,7,2,1,9,5,3,4,8},
      {1,9,8,3,4,2,5,6,7},
      {8,5,9,7,6,1,4,2,3},
      {4,2,6,8,5,3,7,9,1},
      {7,1,3,9,2,4,8,5,6},
      {9,6,1,5,3,7,2,8,4},
      {2,8,7,4,1,9,6,3,5},
      {3,4,5,2,8,6,1,7,9}
  };

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      m[i][j] = aux[i][j];
    }
  }
  ///////////////////////////////

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

  if (!sol) {
    printf("\n\nNão \n\n");
    return 0;
  }

  // verifica dentro de cada um dos 9 quadrantes:
  // (0,0) (0,3) (0,6)
  // (3,0) (3,3) (3,6)
  // (6,0) (6,3) (6,6)
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

  if (sol) {
    printf("\n\nSim\n\n");
  } else {
    printf("\n\nNão\n\n");
  }

  return 0;
}