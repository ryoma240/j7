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
  double tau, x, fk1,fk2,fk3,fk4,X2,X3,X4,en , x_t;
 
  x = 1.0; /* 初期条件の設定 */
 for(n_step = 40; n_step < 5200; n_step = 2*n_step){  /* 分割数の設定 */
   x = 1.0;
  tau = (T_e - T_s)/n_step; /* 刻み幅の計算 */
  //printf("%f\t%f\n", T_s, x); /* 初期時刻と初期値の出力 */
  for ( n = 0; n < n_step; n++ )   /* オイラー法の計算 */  
    {
      fk1 = tau*f(T_s + n*tau, x);
      X2 = x + 0.5*fk1;
      fk2 = tau*f(T_s + n*tau + 0.5*tau, X2);
      X3 = x + 0.5*fk2;
      fk3 = tau*f(T_s + n*tau + 0.5*tau, X3);
      X4 = x + fk3;
      fk4 = tau*f(T_s + n*tau + tau, X4);
      x = x + (1.0/6.0)*(fk1 + 2*fk2 + 2*fk3 + fk4);

      x_t = result((n+1)*tau);

      if(en < fabs(x_t - x)){
	en = fabs(x_t - x);
      }
    }
 printf("%.3e\n", en);
 en = 0;
  }
}
