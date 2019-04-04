#include <stdio.h>

int main(void) {

  char s[100];
  char r[100];

  scanf("%s",s);
  scanf("%s",r);

  int ns[] = {0,0,0,0,0,0,0,0,0,0};
  int k;

  for(int i = 0; s[i] != '\0'; i++) {
    k = s[i]%9;
    ns[k]++;
  }

  for(int i = 0; r[i] != '\0'; i++) {
    k = r[i]%9;
    ns[k]--;
  }

  int p = 1;

  for(int i = 0; i < 10; i++) {
    if (ns[i] != 0) {
      p = 0;
      break;
    }
  }

  if (p) {
    printf("Sim");
  } else {
    printf("Não");
  }

  return 0;
}