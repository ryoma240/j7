#include <stdio.h>
#include <math.h> 
#define T_s      0.0   /* ���� */ 
#define T_e     10.0   /* ���� */ 

double f(double t, double x)  /* f(t, x) ��������� */
{ 
  return cos(t)*x*(2.0-x);
}

main()
{
  int    n, n_step; 
  double tau, x, fk1; 
  x = 1.0; /* ����������� */
  n_step = 5120;  /* ʬ��������� */
  tau = (T_e - T_s)/n_step; /* ������η׻� */
  printf("%f\t%f\n", T_s, x); /* �������Ƚ���ͤν��� */
  for ( n = 0; n < n_step; n++ )   /* �����顼ˡ�η׻� */  
    {
      fk1 = f(T_s + n*tau, x);
      x = x + tau*fk1; 
      printf("%f\t%f\n", T_s + (n+1)*tau, x); /* ����Ȳ�ν��� */
    }
}