#include <stdio.h>
#include <stdlib.h>

int m[3][3] = {
  {1,3,4},
  {8,6,2},
  {7,0,5}
};

int zi, zj, di, dj;

void find_zero(int *zi, int *zj);
int verifica();
void imprime();
void calc_dist(int pos);
void move(int pos);
void e();
void d();
void c();
void b();

int main() {

  find_zero(&zi, &zj);

  for(int i = 0; i < 9; i++) {
    move(i);
  }

  printf("\nTerminou!");
  imprime();

}

void move(int pos) {
  calc_dist(pos);
  printf("%d (%d,%d)\n",pos,di,dj);
}
void calc_dist(int pos) {

  int fi, fj, ai, aj;

  int mf[3][3] = {
    {1,2,3},
    {8,0,4},
    {7,6,5}
  };

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (mf[i][j] == pos) {
        fi = i;
        fj = j;
      }

      if (m[i][j] == pos) {
        ai = i;
        aj = j;
      }
    }
  }

  di = fi-ai;
  dj = fj-aj;
}

int verifica() {
  return
       m[0][0] == 1
    && m[0][1] == 2
    && m[0][2] == 3
    && m[1][0] == 8
    && m[1][1] == 0
    && m[1][2] == 4
    && m[2][0] == 7
    && m[2][1] == 6
    && m[2][2] == 5;
}

void find_zero(int *zi, int *zj) {
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if (m[i][j] == 0) {
        *zi = i;
        *zj = j;
      }
    }
  }
}

void e() {
  if (zj != 0) {
    m[zi][zj] = m[zi][zj-1];
    m[zi][zj-1] = 0;
    zj--;
  }
}

void d() {
  if (zj != 2) {
    m[zi][zj] = m[zi][zj+1];
    m[zi][zj+1] = 0;
    zj++;
  }
}

void c() {
  if (zi != 0) {
    m[zi][zj] = m[zi-1][zj];
    m[zi-1][zj] = 0;
    zi--;
  }
}

void b() {
  if (zi != 2) {
    m[zi][zj] = m[zi+1][zj];
    m[zi+1][zj] = 0;
    zi++;
  }
}

void imprime() {
  for(int i = 0; i < 3; i++) {
    printf("\n");
    for(int j = 0; j < 3; j++) {
      printf("| %d |",m[i][j]);
    }
  }
  printf("\n");
}