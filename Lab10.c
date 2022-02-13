#include <math.h>
#include <stdio.h>

long double y, ap, op;

int main() {
  y = 1;
  printf("Before y=%20.16Lf\n", y);
  y = y / 3;
  printf("1/3 in memory y=%20.15Lf\n", y);
  printf("correct 1/3 = %20.16f\n", 1.0 / 3.0);
  ap = fabs(1.0 / 3 - y);
  op = ap / fabs(1.0 / 3);
  printf("Absoulte error ap=%20.16Lf\n", ap);
  printf("Relative error op=%20.16Lf\n", op);
  y = y / 6000;
  y = exp(y);
  y = sqrt(y);
  y = y / 14;
  y = 14 * y;
  y = pow(y, 2);
  y = log(y);
  y = 6000 * y;
  y = y * 3;
  printf("After transformation y=%20.16Lf\n", y);
  ap = fabs(1 - y);
  op = ap / 1;
  printf("Absoulte error ap=%20.16Lf\n", ap);
  printf("Relative error op=%20.16Lf\n", op);
  return 0;
}
