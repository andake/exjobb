#include "snipmath.h"
#include <math.h>
#include <stdio.h>
#include "functionalsafety.h"

/* The printf's may be removed to isolate just the math calculations */

int math(int, int, int, int);
int args[] = {10, -105, 320, -300};

int main(void)
{
    init(0);
    int (*foo)(int, int, int, int);
    foo = &math;
    functionalsafety(foo, 0, args);
    result();
    return 0;
}

int math (int a, int b, int c, int d){
    double  x[3];
    double X;
    int     solutions;
    int i;
    unsigned long l = 0x3fed0169L;
    struct int_sqrt q;
    long n = 0;

    /* solve some cubic functions */
    printf("********* CUBIC FUNCTIONS ***********\n");
    /* should get 3 solutions: 2, 6 & 2.5   */
    SolveCubic(a, b, c, d, &solutions, x);  
    printf("Solutions:");
    for(i=0;i<solutions;i++)
    printf(" %f",x[i]);
    printf("\n");
    /* should get 1 solution: 2.5           */
    
    /* Now solve some random equations */
    for(a=10;a<100;a+=10) {
    for(b=100;b>0;b-=10) {
      for(c=50;c<150;c+=5) {//was +.5 before
    for(d=-10;d>-110;d-=10) {
      SolveCubic(a, b, c, d, &solutions, x);  
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
    for (i = 0; i < 1001; ++i)
    {
      usqrt(i, &q);
            // remainder differs on some machines
     // printf("sqrt(%3d) = %2d, remainder = %2d\n",
     printf("sqrt(%3d) = %2d\n",
         i, q.sqrt);
    }
    usqrt(l, &q);
    //printf("\nsqrt(%lX) = %X, remainder = %X\n", l, q.sqrt, q.frac);
    printf("\nsqrt(%lX) = %X\n", l, q.sqrt);


    printf("********* ANGLE CONVERSION ***********\n");
    /* convert some rads to degrees */
    for (X = 0.0; X <= 360.0; X += 1.0)
    printf("%3.0f degrees = %.12f radians\n", X, deg2rad(X));
    puts("");
    for (X = 0.0; X <= (2 * PI + 1e-6); X += (PI / 180))
    printf("%.12f radians = %3.0f degrees\n", X, rad2deg(X));


    return 0;
}
