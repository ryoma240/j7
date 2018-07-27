#include <stdio.h>

#define N 2000

typedef double matrix[N][N];
typedef double vector[N];

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
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%f\\",a[i][j]);
	}
    printf("\n");
  }
 


}

void solve(matrix a, vector b, int n){
  int i,j;
  for(i = 1; i < n; i++){ 
    for(j = 0; j <= i-1; j++){
      b[i] = b[i] - a[i][j]*b[j];
    }
  }

  for(i = n-1; i >= 0; i--){
    for(j = i+1; j < n; j++){
      b[i] = b[i] - a[i][j]*b[j];
	}
    b[i] = b[i]/a[i][i];
  }


}

void make_matrix(matrix a){
  a[0][0] =  4; a[0][1] =  -7; a[0][2] =  -7; a[0][3] = 5;
  a[1][0] = -4; a[1][1] = 7; a[1][2] = 7; a[1][3] = 6;
  a[2][0] = 4; a[2][1] = -10; a[2][2] = -10; a[2][3] = 7;
  a[3][0] = 11; a[3][1] = 10; a[3][2] =  9; a[3][3] = 8;
}

void make_vector(vector b){
  b[0] = 0.0;
  b[1] = 0.0;
  b[2] = 0.0;
  b[3] = 0.0;
}

void show_vector(vector b, int n){
  int i;

  for(i=0; i<n; i++)
    printf("%2d %e\n", i+1, b[i]);

}

int main(void){
  static matrix a;
  vector b;
  int n = 3;

  make_matrix(a);
  make_vector(b);

  decomp(a, n);
  solve(a, b, n);

  show_vector(b, n);

  return 0;
}
