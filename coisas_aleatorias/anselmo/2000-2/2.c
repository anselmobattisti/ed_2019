#include <stdio.h>
#include <stdlib.h>

void troca_digitos(char *s);

int main(void) {
  char s[] = "abs 12df345 def";

  troca_digitos(s);

  printf("%s\n",s);
  return 0;
}

void troca_digitos(char *s) {
  for(int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= '0' && s[i] <= '9')
      s[i] = '*';
  }
}
