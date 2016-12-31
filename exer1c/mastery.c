#include <math.h>
#include <complex.h>
#include <float.h>
#include <stdio.h>

int doubleEqual(double complex a, double complex b) {
  if (a == 0 || b == 0) {
    return a == b;
  }
  return cabs(a / b - 1) < DBL_EPSILON * 1e2;
}

void swap(double complex *a, double complex *b) {
  double complex tmp = *a;
  *a = *b;
  *b = tmp;
}

// PRE: roots are sorted
int countReal(double complex *r) {
  if (r[0] == r[1] && r[1] == r[2] && r[2] == r[3]) {
    return 1;
  } else if ((r[0] == r[1] && r[1] == r[2])
      || (r[1] == r[2] && r[2] == r[3])) {
    return 1;
  } else if (r[0] == r[1] && r[2] == r[3]) {
    return 2;
  } else if (r[0] == r[1] || r[1] == r[2] || r[2] == r[3]) {
    return 3;
  } else {
    return 4;
  }
}

int lin_root(double complex *a, double complex *r) {
  if (a[1] == 0) {
    return a[0] == 0 ? -1 : 0;
  } else {
    r[0] = -a[0] / a[1];
    return 1;
  }
}

int quad_roots(double complex *a, double complex *r) {
  // a[1]x + a0 = 0
  if (a[2] == 0) {
    int num_roots = lin_root(a, r);
    return num_roots - 2;
  }

  // x(a[2]x + a[1]) = 0
  if (a[0] == 0) {
    r[0] = 0;
    lin_root(a, r + 1);

    // only one root
    if (a[1] == 0) {
      return 1;
    }
    return 2;
  }

  double complex discriminant = a[1] * a[1] - 4 * a[2] * a[0];

  // remove negative 0
  if (cimag(discriminant) == 0) {
    discriminant = creal(discriminant);
  }

  // one solution
  if (discriminant == 0) {
    r[0] = -a[1] / (2 * a[2]);
    r[1] = r[0];
    return 1;
  }

  // required for r1 >= r2
  double complex root = csqrt(discriminant);

  r[0] = (-a[1] + root) / (2 * a[2]);
  r[1] = (-a[1] - root) / (2 * a[2]);

  return 2;
}

int countDistinct(double complex *r) {
  if (r[0] == r[1] && r[1] == r[2]) {
    return 1;
  } else if (r[0] == r[1] || r[1] == r[2]) {
    return 2;
  } else {
    return 3;
  }
}

int rcubic_roots(double complex *a, double complex *r) {
  if (a[0] == 0) {
    r[0] = 0;
    double complex b[] = {a[1], a[2], 1};
    quad_roots(b, r + 1);
  } else if (a[2] == 0 && a[1] == 0) {
    // roots of unity
    r[0] = cpow(-a[0], 1.0 / 3);
    r[1] = r[0] * (-0.5 + sqrt(3) / 2 * I);
    r[2] = r[0] * (-0.5 - sqrt(3) / 2 * I);
  } else if (a[0] == a[1] * a[2]) {
    // factorize as (x^2 + a[1])(x + a[2])
    r[0] = -a[2];
    r[1] = csqrt(-a[1]);
    r[2] = -r[1];
  } else if (3 * a[1] == a[2] * a[2] && 27 * a[0] == a[2] * a[2] * a[2]) {
    // factorize as (x + a[2] / 3) ^ 3
    r[0] = -a[2] / 3;
    r[1] = r[0];
    r[2] = r[0];
  } else {
    // x = alpha y + beta
    double complex beta = -a[2] / 3;
    double complex alpha = -cpow(a[0] - (a[1] * a[2] / 3) + (2 * a[2] * a[2] * a[2] / 27), 1.0 / 3);
    if (alpha == 0) {
      // x = beta
      r[0] = beta;
      double complex b[] = {a[1] - a[2] * a[2] / 3, 0, 1};
      quad_roots(b, r + 1);
      r[1] += beta;
      r[2] += beta;
    } else {
      double complex p = (a[2] * a[2] / 3 - a[1]) / (alpha * alpha);
      if (p == 0) {
        // y^3 - 1 = 0 => roots of unity
        r[0] = alpha + beta;
        r[1] = alpha * (-0.5 + sqrt(3) / 2 * I) + beta;
        r[2] = alpha * (-0.5 - sqrt(3) / 2 * I) + beta;
      } else {
        // use Newton-Raphson method
        double complex y = 1.0 + 1.0 * I;
        int n;
        for (n = 0; n < 10000; n++) {
          // y_next = y - f(y) / f'(y), simplified
          double complex y_next = 2 * y / 3 + (2 * p * y + 3) / (9 * y * y - 3 * p);
          if (cabs(y_next - y) < DBL_EPSILON) {
            break;
          }
          y = y_next;
        }
        r[0] = alpha * y + beta;
        double complex b[] = {-a[0] / r[0], a[2] + r[0], 1};
        quad_roots(b, r + 1);
      }
    }
  }
  return countDistinct(r);
}

int rquartic_roots(double complex *a, double complex *r) {
  if (a[0] == 0) {
    // cubic equation
    rcubic_roots(a + 1, r + 1);
    r[0] = 0;
  } else if (a[3] == 0 && a[2] == 0 && a[1] == 0) {
    // roots of unity
    r[0] = csqrt(csqrt(-a[0]));
    r[1] = -r[0];
    r[2] = csqrt(-csqrt(-a[0]));
    r[3] = -r[2];
  } else if (a[3] == 0 && a[1] == 0) {
    // quadratic equation
    double complex coeff[] = {a[0], a[2], 1.0};
    quad_roots(coeff, r + 2);
    r[0] = csqrt(r[2]);
    r[1] = -csqrt(r[2]);
    r[2] = csqrt(r[3]);
    r[3] = -csqrt(r[3]);
  } else {
    double complex b[3];
    b[2] = -a[2];
    b[1] = a[1] * a[3] - 4 * a[0];
    b[0] = 4 * a[0] * a[2] - a[1] * a[1] - a[0] * a[3] * a[3];

    rcubic_roots(b, r);

    double complex p[3], q[3];

    // {(+,+),(-,-)}
    p[2] = 1.0;
    p[1] = a[3] / 2. + csqrt(a[3] * a[3] / 4. + r[0] - a[2]);
    p[0] = r[0] / 2. + csqrt(r[0] * r[0] / 4. - a[0]);
    q[2] = 1.0;
    q[1] = a[3] / 2. - csqrt(a[3] * a[3] / 4. + r[0] - a[2]);
    q[0] = r[0] / 2. - csqrt(r[0] * r[0] / 4. - a[0]);

    if (!doubleEqual(q[1] * p[0], a[1] - p[1] * q[0])) {
      // use {(+,-),(-,+)}
      p[2] = 1.0;
      p[1] = a[3] / 2. + csqrt(a[3] * a[3] / 4. + r[0] - a[2]);
      p[0] = r[0] / 2. - csqrt(r[0] * r[0] / 4. - a[0]);
      q[2] = 1.0;
      q[1] = a[3] / 2. - csqrt(a[3] * a[3] / 4. + r[0] - a[2]);
      q[0] = r[0] / 2. + csqrt(r[0] * r[0] / 4. - a[0]);
    }

    quad_roots(p, r);
    quad_roots(q, r + 2);
  }
  return countReal(r);
}

int main() {
  printf("%6s %14s %14s %14s %14s\n", "j", "Re(z1)", "Im(z1)", "Re(z2)", "Im(z2)");
  printf("%6s %14s %14s %14s %14s\n", "j", "Re(z3)", "Im(z3)", "Re(z4)", "Im(z4)");
  // z4 + c3z3 + c2z2 + c1z + c0 = 0
  // d4 z4 + d3 z3 + d2 z2 +d1 z + d0 = 0
  double complex r[4];
  double complex d[5];
  double complex s;
  int j;
  for (j = 0; j <= 80; j++) {
    double real = cos(j / 80. * M_PI);
    double imag = sin(j / 80. * M_PI);
    s = (fabs(real) < 2 * DBL_EPSILON ? 0 : real) + (fabs(imag) < 2 * DBL_EPSILON ? 0 : imag) * I;

    d[4] = 4 * s - 2;
    d[0] = -27 * s * (s - 1) / d[4];
    d[1] = -9 * (5 * s + 1) / d[4];
    d[2] = 3 * (5 * s + 1) / d[4];
    d[3] = -(2 + 4 * s) / d[4];

    rquartic_roots(d, r);

    int i;
    printf("%6d", j);
    for (i = 0; i < 2; i++) {
      printf(" %14.7g %14.7g", creal(r[i]), cimag(r[i]));
    }
    printf("\n");

    printf("%6d", j);
    for (i = 2; i < 4; i++) {
      printf(" %14.7g %14.7g", creal(r[i]), cimag(r[i]));
    }
    printf("\n");
  }

  return 0;
}
