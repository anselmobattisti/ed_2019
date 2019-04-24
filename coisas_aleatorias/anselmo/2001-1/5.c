#include <stdio.h>
#include <stdlib.h>

char *fecha(char *s);

int main(void) {

  char s[] = "anselmo da silva";

  printf("\n%s\n",fecha(s));

}

char *fecha(char *s) {
  int t;
  for(t = 0; s[t] != '\0'; t++);
  t += 2;

  char *aux = (char*) malloc(sizeof(char)*t);
  aux[0] = '[';
  aux[t-1] = ']';
  for(int i = 1; i < t-1; i++) {
    aux[i] = s[i-1];
  }
  return aux;
}