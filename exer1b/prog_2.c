#include <stdio.h>

int rcubic_roots(double a2, double a1, double a0, double *r1, double *r2, double *r3);

int main(void) {
  double r1, r2, r3;
  int num_roots;

  // Test your program on the three cubic equations:
  num_roots = rcubic_roots(2, -5, -6, &r1, &r2, &r3);
  printf("no. of distinct real roots = %d\n", num_roots);
  printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf\n\n", r1, r2, r3);

  num_roots = rcubic_roots(5, 3, -9, &r1, &r2, &r3);
  printf("no. of distinct real roots = %d\n", num_roots);
  printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf\n\n", r1, r2, r3);

  num_roots = rcubic_roots(1, -1, -15, &r1, &r2, &r3);
  printf("no. of distinct real roots = %d\n", num_roots);
  printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf\n\n", r1, r2, r3);
}
