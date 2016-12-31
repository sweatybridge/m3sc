#include <stdio.h>

int main() {
  int i1 = 4;
  int i2 = 11111;
  int i3 = 777777777;
  float x1 = 2.0;
  float x2 = 2.4048255576957728;
  float x3 = 6.02214e23;

  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("x1, x2, x3 = %f %f %f \n", x1, x2, x3);
  printf("\n");

  printf("i1, i2, i3 = %8d %8d %8d \n", i1, i2, i3);
  printf("\n");

  printf("i1, i2, i3 = %4d %4d %4d \n", i1, i2, i3);
  printf("\n");

  printf("x1, x2, x3 = %e %e %e \n", x1, x2, x3);
  printf("\n");

  printf("x1, x2, x3 = %E %E %E \n", x1, x2, x3);
  printf("\n");

  printf("x1, x2, x3 = %g %g %g \n", x1, x2, x3);
  printf("\n");

  printf("x1, x2, x3 = %10.2g %20.12g %10.2g \n", x1, x2, x3);
  printf("\n");

  double x11 = 2.0;
  double x22 = 2.4048255576957728;
  double x33 = 6.02214e23;
  printf("x1, x2, x3 = %10.2g %20.12g %10.2g \n", x11, x22, x33);

  return 0;
}
