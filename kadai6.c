#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3

typedef double matrix[N][N];
typedef double vector[N];

void make_matrix(matrix m){
  m[0][0] = 5;  m[0][1] = -7; m[0][2] = -7;
  m[1][0] = -4; m[1][1] = 8;  m[1][2] = 7;
  m[2][0] = 4;  m[2][1] = -10;m[2][2] = -9;

}
//適当に選択
void make_vector(vector v){
  v[0] = 1;
  v[1] = 2;
  v[2] = 3;
}
//内積
void ip(matrix m, vector v,vector y){
  int i,j;
for(i = 0; i < N; i++){
    y[i] = 0;
    for(j = 0; j < N; j++){
      y[i] += m[i][j]*v[j];
    }
  }
}

double eip(vector y, vector x){
  return y[0]*x[0]+y[1]*x[1]+y[2]*x[2];
}

double norm(vector v){
  return sqrt(eip(v,v));
}

void remake_x(vector x, vector y){
  int i;
  for(i = 0; i < N; i++){
    x[i] = y[i]/norm(y);
  }
}



double  power_method(matrix m, vector x, double e){
  int i = 0;
  vector y;
  ip(m,x,y);
  
  while(fabs(e - eip(y,x)) > 1.0e-11){
    remake_x(x, y);
    ip(m,x,y);
    i++;
    printf("%d ,%le\n",i, fabs(e - eip(y,x)));
    
  }
  return eip(y,x);
}

int main(void){
  
  matrix A;
  vector x;
  int i;
  make_matrix(A);
  make_vector(x);
  double e = 5;
  double e_k;
  e_k = power_method(A, x, e);
  printf("last %le\n", e_k);
  for(i = 0; i < 3; i++)
    printf("%le\n",x[i]);
  return 0;
}
