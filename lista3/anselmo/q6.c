/*
Q6) Escreva um programa que receba, como parâmetro de entrada, uma string, e verifique se esta
string é uma “boa” senha. Entende-se por “boa” senha uma senha com as seguintes características de
formação: (i) ela deve possuir, no mínimo, oito caracteres; (ii) ela deve ter, no mínimo, um caracter
entre '0' a '9'; (iii) ela deve possuir, no mínimo, uma letra maiúscula; (iv) ela deve ter, no mínimo, uma
letra minúscula; e (v) ela deve ter, pelo menos, um caracter do conjunto formato pelos demais
caracteres do teclado.
*/
#include <stdio.h>

int boa_senha(char * s);

int main(void) {

  char s[] = "1abcdef.A";

  if (boa_senha(s)) {
    printf("\n\nSenha Forte\n\n");
  } else {
    printf("\n\nSenha Fraca\n\n");
  }

  return 0;
}

/*
  1 - a senha é boa
  0 - a senha não é boa
*/
int boa_senha(char * s) {

  /*
  (a) ela deve possuir, no mínimo, oito caracteres;
  (b) ela deve ter, no mínimo, um caracter entre '0' a '9';
  (c) ela deve possuir, no mínimo, uma letra maiúscula;
  (d) ela deve ter, no mínimo, uma letra minúscula;
  (e) ela deve ter, pelo menos, um caracter do conjunto formato pelos demais caracteres do teclado.
  */
  int a = 0, b = 0, c = 0, d = 0, e = 0;

  int i = 0;
  for(i = 0; s[i] != '\0'; i++) {
    // numeros 48 - 57
    if (s[i] >= 48 && s[i] <= 57) {
      b = 1;
      continue;
    }

    // A - Z
    if (s[i] >= 65 && s[i] <= 90) {
      c = 1;
      continue;
    }

    // a - z
    if (s[i] >= 97 && s[i] <= 122) {
      d = 1;
      continue;
    }

    // só vai chegar aqui se for qualquer outra coisa
    e = 1;
  }

  if (i >= 8) {
    a = 1;
  }

  if (!a || !b || !c || !d || !e) {
    return 0;
  }
  return 1;
}

