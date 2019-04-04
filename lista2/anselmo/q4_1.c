#include <stdio.h>

int main(void) {

  char s[100];

  scanf("%s",s);

  int t = 0;

  for(t=0; s[t]!= '\0'; t++);

  int p = 1;
  t--;
  for(int i = 0; i < t; i++) {
    if (s[i] != s[t]) {
      p = 0;
      break;
    }
    t--;
  }

  if (p) {
    printf("Sim");
  } else {
    printf("Não");
  }

  return 0;
}