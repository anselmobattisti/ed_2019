#include <stdio.h>

void shift_troca_string(char *str);

int main(void) {
  char str[] = "AmorA";
  shift_troca_string(str);
  printf("\n\n%s\n\n",str);
  return 0;
}

void shift_troca_string(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'A') {
      str[i] = 'z';
      continue;
    }

    if (str[i] == 'z') {
      str[i] = 'A';
      continue;
    }

    if (str[i] >= 'B' && str[i] <= 'Z') {
      str[i] += 31;
      continue;
    }

    if (str[i] >= 'a' && str[i] <= 'y') {
      str[i] -= 33;
      continue;
    }
  }
}