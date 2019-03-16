#include <stdio.h>

int fat(int);

int main(void){
  printf("\n\n");
  printf("Fatorial de 5 é: %d", fat(5));
  printf("\n\n");
  return 0;
}

int fat(int n) {

  if (n == 0) {
    return 1;
  } else {
    return n*fat(n-1);
  }
}