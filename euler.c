#include <stdio.h>
#include <math.h> 
#define T_s      0.0   /* 始点 */ 
#define T_e     10.0   /* 終点 */ 

double f(double t, double x)  /* f(t, x) を定義する */
{ 
  return cos(t)*x*(2.0-x);
}

main()
{
  int    n, n_step; 
  double tau, x, fk1; 
  x = 1.0; /* 初期条件の設定 */
  n_step = 5120;  /* 分割数の設定 */
  tau = (T_e - T_s)/n_step; /* 刻み幅の計算 */
  printf("%f\t%f\n", T_s, x); /* 初期時刻と初期値の出力 */
  for ( n = 0; n < n_step; n++ )   /* オイラー法の計算 */  
    {
      fk1 = f(T_s + n*tau, x);
      x = x + tau*fk1; 
      printf("%f\t%f\n", T_s + (n+1)*tau, x); /* 時刻と解の出力 */
    }
}
