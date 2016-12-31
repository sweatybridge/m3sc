#include <stdio.h>

int main() {
  float x1 = 1.0e6;
  float x2 = 2.4048255576957728;
  float x3;

  x3 = x1 + x2;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  x3 = x1 * x2;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  x3 = x1 / x2;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  x3 = x2 / x1;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

//  x3 = x1 % x2;
//  printf("x1, x2, x3 = %f %f %f \n", x1, x2, x3);

  x1 = 6.02214e23;
  x2 = 3.e17;

  x3 = x1 + x2;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  x3 = x1 * x2;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  x3 = x1 / x2;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  x3 = x2 / x1;
  printf("x1, x2, x3 = %f %f %f \n\n", x1, x2, x3);

  return 0;
}
