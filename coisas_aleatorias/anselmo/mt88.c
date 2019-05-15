#include <stdio.h>
#include <stdlib.h>

void conta(int *vet, int n);
int *soma_grande(int *v1, int *v2, int n);

int main() {

/*
  int n = 0;
  scanf("%d",&n);
  int aux = n;
  int *vet = (int*) malloc(sizeof(int)*n);
  while(aux--) {
    scanf("%d",&vet[aux]);
  }
  conta(vet, n);
*/

  int n = 3;
  int v1[] = {1,1,1};
  int v2[] = {1,1,1};

  int *vr = soma_grande(v1,v2,n);

  printf("\n");
  for(int i = 0; i < n+1; i++) {
    printf("%d",vr[i]);
  }
  printf("\n");
}

void conta(int *vet, int n) {
  for(int i = 0; i < n; i++) {
    int c = 0;
    int comp = vet[i];
    if (comp >= 0) {
      for(int j = i+1; j < n; j++) {
        if (vet[i] == vet[j]) {
          c++;
          vet[j] = -1;
        }
      }
      printf("\nO número %d aparece %d vezez", comp, c);
    }
  }
}

int *soma_grande(int *v1, int *v2, int n) {
  int* vr = (int*) malloc(sizeof(int)*(n+1));
  int aux = 0;
  for (int i = n-1; i >= 0; i--){
    int s = v1[i] + v2[i] + aux;
    if (s <= 9) {
      vr[i+1] = s;
      aux = 0;
    } else {
      vr[i+1] = s-10;
      aux = 1;
    }
  }

  if (aux) {
    vr[0] = 1;
  } else {
    vr[0] = 0;
  }

  return vr;
}
