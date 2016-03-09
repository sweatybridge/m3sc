#include <stdio.h>
#include <math.h>

int lin_root(double a1, double a0, double *r) {
  *r = -a0 / a1;

  if (a1 == 0) {
    return a0 == 0 ? 0 : -1;
  }

  return 1;
}

// returns number of roots or negative number if error
int quad_roots(double a2, double a1, double a0, double *r1, double *r2) {
  // a1x + a0 = 0
  if (a2 == 0) {
    int num_roots = lin_root(a1, a0, r1);
    *r2 = NAN;
    return num_roots - 2;
  }

  // x(a2x + a1) = 0
  if (a0 == 0) {
    *r1 = 0;
    lin_root(a2, a1, r2);

    // only one root
    if (a1 == 0) {
      return 1;
    }

    // positive root is r1
    if (*r2 > 0) {
      *r1 = *r2;
      *r2 = 0;
    }

    return 2;
  }

  double discriminant = a1 * a1 - 4 * a2 * a0;
  // one solution
  if (discriminant == 0) {
    *r1 = -a1 / (2 * a2);
    *r2 = *r1;
    return 1;
  }

  // complex solution
  if (discriminant < 0) {
    *r1 = NAN;
    *r2 = NAN;
    return 0;
  }

  // required for r1 >= r2
  double r = a2 < 0 ? -sqrt(discriminant) : sqrt(discriminant);

  *r1 = (-a1 + r) / (2 * a2);
  *r2 = (-a1 - r) / (2 * a2);

  return 2;
}

int main(void) {
  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");

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
