/**
 * Calculadora
 *
 * OK ---------- R1: Para quando os dois valores são iguais a 0;
 * OK ---------- R2: operadores diferentes de + - * / "operação inválida"
 * OK ---------- R3: quando operador igual / e op2 = 0 "operação inválida"
 **/
#include <stdio.h>

int main(void) {
  float a, b;
  char op = ' ';

  printf("\n-------------------\n");
  printf("\nCalculadora\n");
  printf("\nDigite 0 + 0 para sair\n");
  printf("\n-------------------\n");

  while (1) {
    printf("\nDigite a expressão:");
    scanf("%f %c %f",&a,&op,&b);
    switch(op) {
      case '+':
        printf("%.2f",a+b);
        break;
      case '-':
        printf("%.2f",a-b);
        break;
      case '*':
        printf("%.2f",a*b);
        break;
      case '/':
        if (b==0) {
          printf("\nDivisão por zero.");
        } else {
          printf("%.2f",a/b);
        }
        break;
      default:
        // R3
        printf("\nOperação inválida");
        break;
    }
    if (a == 0 && b ==0) {
      break;
    }
  }
}