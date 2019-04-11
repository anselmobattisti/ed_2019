/*
Guilherme adora brincar com pipas, pipas de várias cores,
formas e tamanhos. Ele tem percebido que para as pipas
possuírem maior estabilidade, e dessa forma voarem mais alto,
elas devem possuir um barbante bem esticado ligando todos
os pares de pontas não vizinhas.

Apesar de ser uma criança bastante criativa e astuta,
Guilherme não sabe como determinar a quantidade de barbantes
que ele terá que utilizar para tornar uma pipa de n lados,
estável. Você pode ajudá-lo?.

Entrada
A entrada será composta por uma única linha, que contém um
inteiro 3 ≤ n ≤ 105, representando o número de lados da pipa.

Saída
Imprima um número inteiro, que será a quantidade de barbantes que Guilherme terá que utilizar para tornar a pipa de n lados estável.
*/
#include <stdio.h>

int main(void) {

  int n;
  double s = 0;

  scanf("%d",&n);

  n -= 2;

  while ( n > 1) {
    s += n;
    n--;
  }

  printf("%.0lf\n",s);
  return 0;
}