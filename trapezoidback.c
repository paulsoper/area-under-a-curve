/**************************************************************************
/
/ area-under-a-curve-trapezoids.c
/
/ A program in C to calculate the area under a curve by using multiple
/ trapezoids.  This is also called a 1st Degree Closed Newton-Cotes
/ Formula.
/
/ for Paul's Code Book - www.paulscodebook.net - April, 2014
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
  int n = 20;        /* n = the number of trapezoids */
  int i = 0;         /* a counter */
  double area = 0;   /* this will hold the area under the curve
    		as we sum over the areas of each trapezoid */

  /* We will be calculating the area under the curve y = f(x)
     from x = a to x = b, using n trapezoids */

  double a = 2.0;
  double b = 6.0;
  double width = (b - a)/(double)n; /* the width of each trapezoid */

  /* The area of each trapezoid will equal 
     width * (my_function(left) + my_function(right) / 2 */

  for (i = 0; i < n; ++i)
  {
    area = area + (width * (f(a + i*width) + f(a + (i+1)*width))/2);
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
