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
//内積
double eip(vector y, vector x){
  return y[0]*x[0]+y[1]*x[1]+y[2]*x[2];
}
//norm
double norm(vector v){
  return sqrt(eip(v,v));
}
//xの更新
void remake_x(vector x, vector y){
  int i;
  for(i = 0; i < N; i++){
    x[i] = y[i]/norm(y);
  }
}

//lu
void decomp(matrix a, int n){
  int k,i,j;
  for(k = 0; k < n; k++){
    for(i = k+1; i < n; i++){
      a[i][k] = a[i][k]/a[k][k];
	for(j = k+1; j < n; j++){
	  a[i][j] = a[i][j] - a[i][k]*a[k][j];
	}
    }
  } 
 
}

//keisan
void solve(matrix a, vector b,vector y, int n){
  int i,j;
  vector tmp,tmp2;        //元の行列を変えないため
  for(i = 1; i < n; i++){ 
    for(j = 0; j <= i-1; j++){
      tmp[i] = b[i] - a[i][j]*b[j];
    }
  }

  for(i = n-1; i >= 0; i--){
    for(j = i+1; j < n; j++){
      tmp2[i] = tmp[i] - a[i][j]*tmp[j];
	}
    y[i] = tmp2[i]/a[i][i];
  }


}
//逆羃乗
double  power_method(matrix m, vector x, double e){
  int i = 0;
  int n = 3;
  vector y;
  decomp(m, n);
  solve(m, x, y, n);
   while(fabs(e - (1/eip(y,x))) > 1.0e-11){
    remake_x(x, y);
    solve(m, x, y, n);
    i++;
    printf("%d ,%le\n",i, fabs(e - (1/eip(y,x))));
    
  }
  return (1/eip(y,x));
}

int main(void){
  
  matrix A;
  vector x;
  make_matrix(A);
  make_vector(x);
  double e = 1;
  double e_k;
  e_k = power_method(A, x, e);
  printf("last %le\n", e_k);
  return 0;
}
