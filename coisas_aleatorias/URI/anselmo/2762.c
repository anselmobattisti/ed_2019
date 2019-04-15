#include <stdio.h>
#include <stdlib.h>

int main()
{
  double num;
  scanf("%lf", &num);

  //printf("%lf",num);

  long inteiro = (int) num;
  long decimal = num - inteiro;

  printf("%ld.%ld\n", decimal, inteiro);
  return 0;


    /*
    char n[100];
    char aux[100];
    char d[3];
    char *ptr;
    scanf("%s",n);

    int i;
    for(i = 0; n[i] != '.'; i++);
    d[0] = n[i+1];
    d[1] = n[i+2];
    d[2] = n[i+3];

    for(i = 0; n[i] != '.'; i++) {
      aux[i] = n[i];
    }

    long ret;
    ret = strtol(aux, &ptr, 100);

    printf("%d.%ld\n",atoi(d),ret);
    return 0;
    */
}