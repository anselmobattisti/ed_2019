#include <stdio.h>
#include <stdlib.h>

char* concatena (char* s1, char* s2);

int main(void) {

  char *s1 = "PUC";
  char *s2 = "RIO";

  printf("%s",concatena(s1,s2));

  return 0;
}

char* concatena (char* s1, char* s2) {
  int t = 0;

  for (int i = 0; s1[i] != '\0'; i++)
    t++;

  for (int i = 0; s2[i] != '\0'; i++)
    t++;

  char *s = (char*) malloc(sizeof(char)*t);

  t = 0;
  for (int i = 0; s1[i] != '\0'; i++){
    s[t] = s1[i];
    t++;
  }
  s[t] = '-';
  t++;
  for (int i = 0; s2[i] != '\0'; i++){
    s[t] = s1[i];
    t++;
  }

  return s;
}