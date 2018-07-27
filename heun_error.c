#include <stdio.h>
#include <math.h> 
#define T_s      0.0   /* 始点 */ 
#define T_e     10.0   /* 終点 */ 

double f(double t, double x)  /* f(t, x) を定義する */
{ 
  return cos(t)*x*(2.0-x);
}
double result(double t){
  return 2/(1+exp(-2*sin(t)));
}

main()
{
  int    n, n_step; 
  double tau, x, fk1,fk2, X, en, x_t;
  en = 0; 
  x = 1.0; /* 初期条件の設定 */
  for(n_step = 40; n_step < 5200; n_step = 2*n_step){  /* 分割数の設定 */
x = 1.0; /* 初期条件の設定 */
  tau = (T_e - T_s)/n_step; /* 刻み幅の計算 */
  for ( n = 0; n < n_step; n++ )   /* オイラー法の計算 */  
    {
      fk1 = tau*f(T_s + n*tau, x);
      X = x+fk1;
      fk2=tau*f(T_s + (n+1)*tau, X);
      x = x + 0.5 * (fk1 + fk2); 
      x_t = result((n+1)*tau);

      if(en < fabs(x_t - x)){
	en = fabs(x_t - x);
      }
    }
 printf("%.3e\n", en);
 en = 0;
  }
}
