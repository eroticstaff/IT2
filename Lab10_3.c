#include <math.h>
#include <stdio.h>

int main() {
  float x, y1, y2, y;
  x = 25;
  printf("x=%20.16f\n", x);
  y1 = sin(x);
  printf("y1=sin(x)=%20.16f\n", y1);
  y2 = cos(x);
  printf("y2=cos(x)=%20.16f\n", y2);
  y = y1 * y1 + y2 * y2;
  printf("y=sin^2(x)+cos^2(x)=%20.16f\n", y);
  printf("y absolute error ap=%20.16f\n", fabs(y - 1));
  printf("y relative error op=%20.16f\n", fabs(y - 1) / 1);
}
