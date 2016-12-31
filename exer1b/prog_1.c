#include <stdio.h>

int quad_roots(double a2, double a1, double a0, double *r1, double *r2);

int main() {
  double a2, a1, a0, r1, r2;

  printf("Enter coefficients of Quadratic Equation a2*x^2+a1*x+a0=0 \n");
  printf("in the order a2, a1, a0, separated by spaces\n");
  scanf("%lf %lf %lf", &a2, &a1, &a0);

  int num_roots = quad_roots(a2, a1, a0, &r1, &r2);
  switch (num_roots) {
    case 2:
      printf("r1 = %.15lf, r2 = %.15lf\n", r1, r2);
      break;
    case 1:
      printf("r = %.15lf\n", r1);
      break;
    case 0:
      printf("real = %.15lf, imag = %.15lf\n", r1, r2);
      printf("Complex solution.");
      break;
    case -1:
      printf("r = %.15lf\n", r1);
      printf("Equation is linear.\n");
      break;
    case -2:
      printf("Infinite solution.");
      break;
    case -3:
      printf("No solution.");
      break;
    default:
      printf("Unknown return value.");
      break;
  }

  return 0;
}
