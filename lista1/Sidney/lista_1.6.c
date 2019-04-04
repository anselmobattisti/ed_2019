/*
Escrito por Sidney Loyola de Sá
 Data: 30/03/2019
 
 Q6) Supondo as seguintes declarações:
int x, y, z;
int teste;
x = 5;
y = x++;
z = x--;
Informe os valores de teste, x, y e z depois da avaliação das seguintes expressões:
(a) teste = !y == !x;
(b) teste = ((x++ > y) || (--z <= y));
(c) teste = ((!x) || (!(!z)));
(d) teste = (((x + y) > z) && (x++));
(e) teste = x && y + !3 || 4; 
 */


#include <stdio.h>

int main(void) {

	int op;
	int x,y,z;
	int teste;
	x = 5;
	y = x++;
	z = x--;

	//Informe os valores de teste, x , y e z depois da avaliação das seguintes expressões
	
	printf("Escolha a opção desejada: \n");
	printf("0 - a \n");
	printf("1 - b \n");
	printf("2 - c \n");
	printf("3 - d \n");
	printf("4 - e \n");

	scanf("%d", &op);

	switch(op){
		case 0:
			teste = !y == !x;
			// resp: teste = 1  x = 5   y =5  z = 6
			break;
		case 1:
			teste = ((x++ > y) || (--z <= y));
			// resp: teste = 1  x = 6   y =5  z = 5
			break;
		case 2:
	
			teste = ((!x) || (!(!z)));
			// resp: teste = 1  x = 5   y =5  z = 6
			break;
		case 3:
			teste = (((x + y) > z) && (x++));
			// resp: teste = 1  x = 6   y =5  z = 6
			break;
		case 4:
			teste = x && y + !3 || 4;
			// resp: teste = 1  x = 5   y =5  z = 6
			break;
	}
	

	
	
	printf("Teste = %d \n", teste);
	printf("x = %d \n", x);
	printf("y = %d \n", y);
	printf("z = %d \n", z);
	
	return 0;
}








