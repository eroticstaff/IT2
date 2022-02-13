#include <math.h>
#include <stdio.h>

int main() {
  double x, y, y1, y2;
  x = 10;
  printf("x=%20.16f\n", x);
  printf("-------------------\n");
  y1 = cosh(x);
  printf("Correct ch(x) = %20.16f\n", y1);
  y2 = sinh(x);
  printf("Correct sh(x) = %20.16f\n", y2);
  printf("Correct ch^2(x)-sh^2(x)=%d\n", 1);
  printf("-------------------\n");
  y1 = (exp(x) + exp(-x)) / 2;
  printf("y1=ch(x)=%20.16f\n", y1);
  printf("y1 absolute error ap = %20.16f\n", fabs(y1 - cosh(x)));
  printf("y1 relative error op = %20.16f\n", fabs(y1 - cosh(x)) / cosh(x));
  y2 = (exp(x) - exp(-x)) / 2;
  printf("y2=sh(x)=%20.16f\n", y2);
  printf("y2 absolute error ap = %20.16f\n", fabs(y2 - sinh(x)));
  printf("y2 relative error op = %20.16f\n", fabs(y2 - sinh(x)) / sinh(x));
  y = y1 * y1 - y2 * y2;
  printf("y=ch^2(x)-sh^2(x)=%20.16f\n", y);
  printf("y absolute error %20.16f\n", fabs(y - 1));
  printf("y relative error %20.16f\n", fabs(y - 1) / 1);
}
