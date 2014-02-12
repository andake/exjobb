#include "snipmath.h"
#include <math.h>
#include <stdio.h>
#include "functionalsafety.h"
#include <stdlib.h>

/* The printf's may be removed to isolate just the math calculations */

int basicmath_large1(int , int , int , int );

int args[] = {10, -105, 320, -300};
double  x[3];
double X;
int solutions;
int i;
unsigned long l = 0x3fed0169L;
struct int_sqrt q;
long n = 0;

int main(void)
{
    init(0);
    int (*foo)(int, int, int, int);
    foo = &basicmath_large1;
    functionalsafety(foo, 0, args);
    result();
    return 0;
}

int basicmath_large1(int a1, int b1, int c1, int d1){


  /* solve some cubic functions */
  printf("********* CUBIC FUNCTIONS ***********\n");
  /* should get 3 solutions: 2, 6 & 2.5   */
  SolveCubic(a1, b1, c1, d1, &solutions, x);  
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = 10; b1 = -45; c1 = 170; d1 = -300;
  /* should get 1 solution: 2.5           */
  SolveCubic(a1, b1, c1, d1, &solutions, x);  
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = 10; b1 = -35; c1 = 220; d1 = -310;
  SolveCubic(a1, b1, c1, d1, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = 10; b1 = -137; c1 = 10; d1 = -350;
  SolveCubic(a1, b1, c1, d1, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = 30; b1 = 1234; c1 = 50; d1 = 120;
  SolveCubic(a1, b1, c1, d1, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = -80; b1 = -6789; c1 = 60; d1 = -236;
  SolveCubic(a1, b1, c1, d1, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = 450; b1 = 867; c1 = 75; d1 = 340;
  SolveCubic(a1, b1, c1, d1, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  a1 = -120; b1 = -17; c1 = 53; d1 = 160;
  SolveCubic(a1, b1, c1, d1, &solutions, x);
  printf("Solutions:");
  for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
  printf("\n");

  /* Now solve some random equations */
  for(a1=1000;a1<10000;a1+=1000) {
    for(b1=10000;b1>0000;b1-=250) {
      for(c1=5000;c1<15000;c1+=610) {
	   for(d1=-1000;d1>-5000;d1-=451) {
		SolveCubic(a1, b1, c1, d1, &solutions, x);  
		printf("Solutions:");
		for(i=0;i<solutions;i++)
		  printf(" %f",x[i]);
		printf("\n");
	   }
      }
    }
  }


  printf("********* INTEGER SQR ROOTS ***********\n");
  /* perform some integer square roots */
  for (i = 0; i < 100000; i+=2)
    {
      usqrt(i, &q);
			// remainder differs on some machines
     // printf("sqrt(%3d) = %2d, remainder = %2d\n",
     printf("sqrt(%3d) = %2d\n",
	     i, q.sqrt);
    }
  printf("\n");
  for (l = 0x3fed0169L; l < 0x3fed4169L; l++)
    {
	 usqrt(l, &q);
	 //printf("\nsqrt(%lX) = %X, remainder = %X\n", l, q.sqrt, q.frac);
	 printf("sqrt(%lX) = %X\n", l, q.sqrt);
    }


  printf("********* ANGLE CONVERSION ***********\n");
  /* convert some rads to degrees */
/*   for (X = 0.0; X <= 360.0; X += 1.0) */
  for (X = 0; X <= 360000000; X += 1000)
    printf("%3.0f degrees = %.12f radians\n", X, deg2rad(X));
  puts("");
/*   for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180)) */
  for (X = 0.0; X <= (2000000 * PI + 1); X += (PI / 5760000000))
    printf("%.12f radians = %3.0f degrees\n", X, rad2deg(X));
  
  
  return 0;
}
