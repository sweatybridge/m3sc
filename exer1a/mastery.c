#include <stdio.h>
#include <math.h>
#include <float.h>
#include <complex.h>

int lin_root(double complex a1, double complex a0, double complex *r) {
  *r = -a0 / a1;

  if (a1 == 0) {
    return a0 == 0 ? 0 : -1;
  }

  return 1;
}

int quad_roots(double complex a2, double complex a1, double complex a0, double complex *r1, double complex *r2) {
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
    if (creal(*r2) > 0) {
      *r1 = *r2;
      *r2 = 0;
    }

    return 2;
  }

  double complex discriminant = a1 * a1 - 4 * a2 * a0;

  // remove negative 0
  if (cimag(discriminant) == 0) {
    discriminant = creal(discriminant);
  }

  // one solution
  if (discriminant == 0) {
    *r1 = -a1 / (2 * a2);
    *r2 = *r1;
    return 1;
  }

  // required for r1 >= r2
  double complex r = creal(a2) < 0 ? -csqrt(discriminant) : csqrt(discriminant);

  *r1 = (-a1 + r) / (2 * a2);
  *r2 = (-a1 - r) / (2 * a2);

  // accurate version
  if (creal(a1) < 0) {
    *r2 = a0 / a2 / *r1;
  } else {
    *r1 = a0 / a2 / *r2;
  }

  return 2;
}

int main() {
  printf("%6s %14s %14s %14s %14s\n", "j", "Re(Wj+)", "Im(Wj+)", "Re(Wj-)", "Im(Wj-)");
  int j;
  for (j = 0; j <= 80; j++) {
    double complex z, r1, r2;
    double real = cos(j / 40.0 * M_PI);
    double imag = sin(j / 40.0 * M_PI);

    z = (fabs(real) < DBL_EPSILON ? 0 : real) + (fabs(imag) < DBL_EPSILON ? 0 : imag) * I;
    quad_roots(12, -9 * z * z, 24 * z - 8 * z * z - 12, &r1, &r2);
    printf("%6d %14.7g %14.7g %14.7g %14.7g\n", j, creal(r1), cimag(r1), creal(r2), cimag(r2));
  }

  return 0;
}
