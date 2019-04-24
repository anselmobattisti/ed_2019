#include <stdio.h>
#include <stdlib.h>

char *dupl(char *s);

int main(void) {
  char s[100];

  scanf("\n%s",s);

  char *r = dupl(s);

  printf("\n%s\n",r);

  return 0;
}

char *dupl(char *s) {

  int t;
  for(t = 0; s[t] != '\0'; t++);

  char *aux = (char*) malloc(sizeof(char)*(t*2));

  for (int i = 0; i < t; i++) {
    aux[i] = s[i];
    aux[i+t] = s[i];
  }

  return aux;

}
