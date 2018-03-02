/**************************************************************************
/
/ simpsons-rule.c
/
/ A program in C to calculate the area under a curve by using Simpson's
/ Rule.  This is also called a 2nd Degree Closed Newton-Cotes
/ Formula.
/
/ Paul Soper
/
/ March 2, 2018
/
/*************************************************************************/

#include "stdio.h"

/*************************************************************************
/
/ double f(double x)
/ 
/ We need to define the curve by an algebraic function.  We will use 
/ a polynomial here, but the function could be any continuous function
/
/*************************************************************************/

double f(double x)
{
  /* use 5x^3 - 12x^2 + 7x - 3 as the polynomial function */
  return (5.0*x*x*x - 12.0*x*x + 7.0*x - 3.0);
}

int main()
{
  int n = 20;        /* n = the number of segments */
  int i = 0;         /* a counter */
  double area = 0;   /* this will hold the area under the curve
    		as we sum over the areas of each segment */

  /* We will be calculating the area under the curve y = f(x)
     from x = a to x = b, using n segments, and using Simpson's Rule */

  double x1 = 2.0;   /* x1 and x2 are the endpoints for the whole calculation */
  double x2 = 6.0;

  double width = (x2 - x1)/(float)n;

  double a;          /* a and b are the endpoints for each segment */
  double b;

  for (i = 0; i < n; ++i)
  {
    a = x1 + i * width;
    b = x1 + (i + 1) * width;

    area = area + ((b-a)/6.0) * (f(a) + 4.0 * f((a+b)/2.0) + f(b));
  }
  
  printf ("Area = %8.2f\n", area);

  /* We can easily check our answer, because f is just a 
     polynomial and is easily integrated, so we can solve the problem
     analytically rather than numerically.

     The integral is g(x) = (5/4)x^4 - (12/3)x^3 + (7/2)x^2 -3x + C

     The definite integral (which is the area under the curve, is
     g(b) - g(a).

     In our case that is  864 - (-4) = 868.0 */

  printf ("Analytic solution:  area =  868.00\n");

  return (0);
}
