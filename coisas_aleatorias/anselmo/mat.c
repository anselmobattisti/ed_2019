#include <stdio.h>
#include<stdlib.h>

char* itoa(int i, char b[]);

int main() {

  for (int l = 2; l < 10; l++) {

    char val[l];
    char val2[l];
    for(int i = 0; i < l; i++) {
      val[i] = '1';
      val2[i] = '9';
    }

    for(int i = 0; i < l; i++) {
      printf("%c", val2[i]);
    }

    int result = atoi (val);
    int result2 = atoi (val2);

    int v[10];
    for(int i = 0; i < 10; i++) {
      v[i] = result * i;
    }

    char snum[l];
    char snum2[l];
    for(int i = 1; i < result2; i++) {
      int s = l*i;
      for(int k = 1; k <= 9; k++) {
        if (v[k] == s) {
          itoa(s, snum);
          itoa(i, snum2);
          int ok = 1;
          for (int j = 0; j < l; j++) {
            if (snum[j] != snum2[l-1]) {
              ok = 0;
            }
          }
          if (ok)
            printf("\n%d - %d\n",l,i);
        }
      }
    }
  }
}

char* itoa(int i, char b[]){
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}