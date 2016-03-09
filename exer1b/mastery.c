#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <float.h>

int lin_root(double complex a1, double complex a0, double complex *r) {
  if (a1 == 0) {
    *r = 0;
    return a0 == 0 ? 0 : -1;
  }
  *r = -a0 / a1;
  return 1;
}

int quad_roots(double complex a2, double complex a1, double complex a0, double complex *r1, double complex *r2) {
  // a1x + a0 = 0
  if (a2 == 0) {
    int num_roots = lin_root(a1, a0, r1);
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
  double complex r = csqrt(discriminant);

  *r1 = (-a1 + r) / (2 * a2);
  *r2 = (-a1 - r) / (2 * a2);

  return 2;
}

int countDistinct(double complex *r1, double complex *r2, double complex *r3) {
  if (*r1 == *r2 && *r2 == *r3) {
    return 1;
  } else if (*r1 == *r2 || *r2 == *r3) {
    return 2;
  } else {
    return 3;
  }
}

int rcubic_roots(double complex a2,
                 double complex a1,
                 double complex a0,
                 double complex *r1,
                 double complex *r2,
                 double complex *r3) {
  if (a0 == 0) {
    *r1 = 0;
    quad_roots(1.0, a2, a1, r2, r3);
  } else if (a2 == 0 && a1 == 0) {
    // roots of unity
    *r1 = cpow(-a0, 1.0 / 3);
    *r2 = *r1 * (-0.5 + sqrt(3) / 2 * I);
    *r3 = *r1 * (-0.5 - sqrt(3) / 2 * I);
  } else if (a0 == a1 * a2) {
    // factorize as (x^2 + a1)(x + a2)
    *r1 = -a2;
    *r2 = csqrt(-a1);
    *r3 = -*r2;
  } else if (3 * a1 == a2 * a2 && 27 * a0 == a2 * a2 * a2) {
    // factorize as (x + a2 / 3) ^ 3
    *r1 = -a2 / 3;
    *r2 = *r1;
    *r3 = *r1;
  } else {
    // x = alpha y + beta
    double complex beta = -a2 / 3;
    double complex alpha = -cpow(a0 - (a1 * a2 / 3) + (2 * a2 * a2 * a2 / 27), 1.0 / 3);
    if (alpha == 0) {
      // x = beta
      *r1 = beta;
      quad_roots(1.0, 0.0, a1 - a2 * a2 / 3, r2, r3);
      *r2 += beta;
      *r3 += beta;
    } else {
      double complex p = (a2 * a2 / 3 - a1) / (alpha * alpha);
      if (p == 0) {
        // y^3 - 1 = 0 => roots of unity
        *r1 = alpha + beta;
        *r2 = alpha * (-0.5 + sqrt(3) / 2 * I) + beta;
        *r3 = alpha * (-0.5 - sqrt(3) / 2 * I) + beta;
      } else {
        // use Newton-Raphson method
        double complex y = 1.0 + 1.0 * I;
        for (int n = 0; n < 10000; n++) {
          // y_next = y - f(y) / f'(y), simplified
          double complex y_next = 2 * y / 3 + (2 * p * y + 3) / (9 * y * y - 3 * p);
          if (cabs(y_next - y) < DBL_EPSILON) {
            break;
          }
          y = y_next;
        }
        *r1 = alpha * y + beta;
        quad_roots(1.0, a2 + *r1, -a0 / *r1, r2, r3);
      }
    }
  }
  return countDistinct(r1, r2, r3);
}

int main(void) {
  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");
  printf("%20s: %s\n", "Time", __TIME__);
  printf("%20s: %s\n", "Date", __DATE__);

  // z3 + c2z2 + c1z + c0 = 0
  double complex c2, c1, c0, r1, r2, r3, s;

  printf("%6s %14s %14s %14s %14s %14s %14s\n", "j", "Re(z1)", "Im(z1)", "Re(z2)", "Im(z2)", "Re(z3)", "Im(z3)");
  for (int j = 0; j <= 100; j++) {
    double real = cos(j / 50. * M_PI);
    double imag = sin(j / 50. * M_PI);
    s = (fabs(real) < 2 * DBL_EPSILON ? 0 : real) + (fabs(imag) < 2 * DBL_EPSILON ? 0 : imag) * I;
    c0 = 18 * (s * s - s) / (3 * s - 1);
    c1 = (30 * s + 6) / (3 * s - 1);
    c2 = -(8 * s + 4) / (3 * s - 1);

    int num_roots = rcubic_roots(c2, c1, c0, &r1, &r2, &r3);
//    printf("%6d %14.7g %14.7g %14.7g %14.7g %14.7g %14.7g\n", j,
//           creal(c2),
//           cimag(c2),
//           creal(c1),
//           cimag(c1),
//           creal(c0),
//           cimag(c0));

    printf("%6d", j);
    switch (num_roots) {
      case 3:
        printf("%14.7g %14.7g %14.7g %14.7g %14.7g %14.7g",
               creal(r1),
               cimag(r1),
               creal(r2),
               cimag(r2),
               creal(r3),
               cimag(r3));
        break;
      case 2:
        printf("%14.7g %14.7g %14.7g %14.7g", creal(r1), cimag(r1), creal(r2), cimag(r2));
        break;
      case 1:
        printf("%14.7g %14.7g", creal(r1), cimag(r1));
        break;
      default:
        break;
    }
    printf("\n");
  }

  return 0;
}