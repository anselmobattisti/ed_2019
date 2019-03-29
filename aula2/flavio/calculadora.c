#include <stdio.h>

// declaração dos cabeçalhos das funções, não precisa no nome da variável, apenas a indicação do tipo
float soma(float, float);

float subtracao(float, float);

// função principal
int main(void) {

  float a, b;
  char c;

  printf("Digite a expressão: ");

  // não importa se coloca ou não espaço na string do scanf, funciona igual
  scanf("%f %c %f",&a, &c, &b);

  // a avaliação da expressão do switch tem que ser um inteiro, no caso um char
  switch(c) {
    case '+':
      printf("A soma é %.2f\n\n",soma(a,b));
      break;
    case '-':
      printf("A subtracao é %.2f\n\n",subtracao(a,b));
      break;
    default:
      printf("\n\nOpção inválida %c\n\n",c);
  }

  return 0;
}

// implementação das funções
float soma(float a, float b){
  return (float) a+b;
}

float subtracao(float a, float b){
  return (float) a-b;
}