#include <math.h>
#include <float.h>

// used for comparing two calculated double value
int doubleEqual(double a, double b) {
  if (a == 0 || b == 0) {
    return a == b;
  }
  return (((fabs(a) <= 1 && fabs(b) <= 1) || (fabs(a) > 1 && fabs(b) > 1))
      && fabs(a / b - 1) < DBL_EPSILON * 1e2);
}

void swap(double *a, double *b) {
  double tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSort(double *root, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 1; j < size - i; j++) {
      if (root[j - 1] < root[j]) {
        swap(&root[j - 1], &root[j]);
      }
    }
  }
}

int a1_overflow(double *a) {
  return fabs(a[1]) > sqrt(DBL_MAX);
}

int a1_underflow(double *a) {
  return fabs(a[1]) > 0 && fabs(a[1]) < 1
      && fabs(a[1]) / sqrt(DBL_MIN) < fabs(a[2])
      && fabs(a[1]) / sqrt(DBL_MIN) < fabs(a[0]);
}

int a2a0_overflow(double *a) {
  return (fabs(a[2]) > 1 / 4. && fabs(a[0]) > DBL_MAX / 4. / fabs(a[2]))
      || (fabs(a[0]) > 1 / 4. && fabs(a[2]) > DBL_MAX / 4. / fabs(a[0]));
  // 4*a[2]*a[0] might underflow
}

int a2a0_underflow(double *a) {
  return (fabs(a[2]) > 0 && fabs(a[2]) < 1 / 4. && fabs(a[0]) < DBL_MIN / fabs(a[2]) / 4.)
      || (fabs(a[0]) > 0 && fabs(a[0]) < 1 / 4. && fabs(a[2]) < DBL_MIN / fabs(a[2]) / 4.);
  // 4*a[2]*a[0] might overflow
}

int lin_root(double *a, double *r) {
  if (a[1] == 0) {
    r[1] = 0;
    return a[0] == 0 ? 0 : -1;
  }
  r[1] = -a[0] / a[1];
  return 1;
}

// returns number of roots or negative number if error
int quad_roots(double *a, double *r) {
  // a[1]x + a[0] = 0
  if (a[2] == 0) {
    int num_roots = lin_root(a, r);
    if (r[1] > 0) {
      r[2] = 0;
    } else {
      r[2] = r[1];
      r[1] = 0;
    }
    return num_roots - 2;
  }

  // x(a[2]x + a[1]) = 0
  if (a[0] == 0) {
    r[1] = 0;
    lin_root(a + 1, r + 1);

    // only one root
    if (a[1] == 0) {
      return 1;
    }

    // positive root is r1
    if (r[2] > 0) {
      r[1] = r[2];
      r[2] = 0;
    }

    return 2;
  }

  // correct underflow by setting coeff to 0 when too small (relative to other coeffs)
  if (a1_underflow(a)) {
    a[1] = 0;
  }

  double discriminant, ra;
  if (!a2a0_underflow(a) && !a2a0_overflow(a) && !a1_overflow(a)) {
    // no overflow
    discriminant = a[1] * a[1] - 4 * a[2] * a[0];
    if (discriminant < 0) {
      // complex solution
      ra = sqrt(-discriminant) / a[2];
    } else {
      ra = sqrt(discriminant) / a[2];
    }
  } else if (a1_overflow(a)) {
    if (a2a0_underflow(a)) {
      discriminant = 1;
      ra = fabs(a[1]) / a[2];
    } else {
      // we don't know if a[2]a[0] will overflow but we dont care
      // refactor a[1] out of sqrt, a[1] is big
      // gg if 4 * (a[2] / a[1]) * (a[0] / a[1]) < DBL_EPSILON
      discriminant = 1 - 4 * (a[2] / a[1]) * (a[0] / a[1]);
      if (discriminant < 0) {
        // complex solution
        ra = fabs(a[1]) / a[2] * sqrt(-discriminant);
      } else {
        ra = fabs(a[1]) / a[2] * sqrt(discriminant);
      }
    }
  } else {
    // we know at this point that a[1] does not overflow, a[1] might be zero if it underflow
    if (a2a0_underflow(a) && fabs(a[1]) > sqrt(DBL_MIN)) {
      discriminant = a[1] * a[1];
      ra = fabs(a[1]) / a[2];
    } else {
      discriminant = (fabs(a[1]) / fabs(a[2])) * (fabs(a[1]) / fabs(a[0]));
      if ((a[2] > 0 && a[0] > 0) || (a[2] < 0 && a[0] < 0)) {
        discriminant -= 4;
      } else {
        discriminant += 4;
      }

      if (discriminant < 0) {
        // complex solution
        ra = sqrt(fabs(a[2])) * sqrt(fabs(a[0])) / a[2] * sqrt(-discriminant);
      } else {
        ra = sqrt(fabs(a[2])) * sqrt(fabs(a[0])) / a[2] * sqrt(discriminant);
      }
    }
  }

  // one solution
  if (ra == 0) {
    r[1] = -a[1] / a[2] / 2;
    r[2] = r[1];
    return 1;
  }

  if (discriminant < 0) {
    // complex solution
    r[1] = -a[1] / a[2] / 2;
    // use the positive conjugate as required by spec
    r[2] = fabs(ra) / 2;
    return 0;
  }

  // required for r1 >= r2
  r[1] = (-a[1] / a[2] + ra) / 2;
  r[2] = (-a[1] / a[2] - ra) / 2;

  // handle summation of opposite sign with equal magnitude
  if ((fabs(a[0]) >= 1 && fabs(a[2]) >= 1)
      || (fabs(a[0]) <= 1 && fabs(a[2]) <= 1)) {
    if (a[1] < 0 && r[1] != 0) {
      r[2] = a[0] / a[2] / r[1];
    } else if (r[2] != 0) {
      r[1] = a[0] / a[2] / r[2];
    }
  }

  bubbleSort(r + 1, 2);

  return discriminant < 0 ? 0 : 2;
}

int countDistinct(double *r) {
  if (doubleEqual(r[1], r[2]) && doubleEqual(r[2], r[3])) {
    return 1;
  } else if (doubleEqual(r[1], r[2]) || doubleEqual(r[2], r[3]) || doubleEqual(r[1], r[3])) {
    return 2;
  } else {
    return 3;
  }
}

int rcubic_roots(double *a, double *r) {
  if (a[0] == 0) {
    r[1] = 0;
    double coeff[] = {a[1], a[2], 1.0};
    int num_roots = quad_roots(coeff, r + 1);
    if (num_roots == 0) {
      // complex roots
      return 0;
    }
    bubbleSort(r + 1, 3);
    return countDistinct(r);
  } else if (a[2] == 0 && a[1] == 0) {
    // roots of unity
    r[1] = cbrt(-a[0]);
    // complex solution
    r[2] = -r[1] / 2;
    r[3] = fabs(r[1]) * sqrt(3) / 2;
    return 0;
  } else if (doubleEqual(a[0], a[1] * a[2])) {
    // factorize as (x^2 + a[1])(x + a[2])
    r[1] = -a[2];
    if (a[1] <= 0) {
      // 2 more real roots
      r[2] = sqrt(-a[1]);
      r[3] = -r[2];
      bubbleSort(r + 1, 3);
      return countDistinct(r);
    } else {
      // 2 complex roots
      r[2] = 0;
      r[3] = sqrt(a[1]);
      return 0;
    }
  } else if (doubleEqual(3 * a[1], a[2] * a[2]) && doubleEqual(27 * a[0], a[2] * a[2] * a[2])) {
    // factorize as (x + a[2] / 3) ^ 3
    r[1] = -a[2] / 3;
    r[2] = r[1];
    r[3] = r[1];
    return 1;
  } else {
    // x = alpha y + beta
    double beta = -a[2] / 3;
    double alpha = -cbrt(a[0] - (a[1] * a[2] / 3) + (2 * a[2] * a[2] * a[2] / 27));
    if (alpha == 0) {
      // x = beta
      r[1] = beta;
      double coeff[] = {a[1] - a[2] * a[2] / 3, 0.0, 1.0};
      int num_roots = quad_roots(coeff, r + 1);
      if (num_roots == 0) {
        // complex roots
        r[2] += beta;
        // no change to r[3], since it's complex conjugate
        return 0;
      }
      // all real roots
      r[2] += beta;
      r[3] += beta;
      bubbleSort(r + 1, 3);
      return countDistinct(r);
    } else {
      double p = (a[2] * a[2] / 3 - a[1]) / (alpha * alpha);
      // for checking repeated root if any
      double p2 = 3 / cbrt(4.);
      double y2 = -1 / cbrt(2.);
      // p == 0
      if (doubleEqual(a[2] * a[2] / 3, a[1])) {
        // y^3 - 1 = 0 => roots of unity
        r[1] = alpha + beta;
        r[2] = -alpha / 2 + beta;
        r[3] = alpha * sqrt(3) / 2;
        return 0;
      } else if (doubleEqual(p, p2)) {
        r[1] = alpha * y2 + beta;
        r[2] = r[1];
        r[3] = alpha / y2 / y2 + beta;
        // TODO: use quad roots

        if (doubleEqual(r[1] * r[2] + r[3] * r[2] + r[1] * r[3], a[1])) {
          bubbleSort(r + 1, 3);
          return countDistinct(r);
        }
      }
      // use Newton-Raphson method
      // better initial guess
      double y;
      if (p > 11 / 3.) {
        y = sqrt(p);
      } else if (p < -1.92) {
        y = -1.0 / p;
      } else {
        y = 1.0 + p / 3. + pow(p, 3) / 81.;
      }
      double prev_change = 0;
      int n;
      double y_next, change;
      for (n = 0; n < 10000; n++) {
        // y_next = y - f(y) / f'(y), simplified
        y_next = 2 * y / 3 + (2 * p * y + 3) / (9 * y * y - 3 * p);
        change = fabs(y_next - y);
        if (y_next == y ||
            (n > 3 && change > prev_change)) {
          break;
        }
        prev_change = change;
        y = y_next;
      }
      r[1] = alpha * y + beta;

      int num_roots;
      if (r[1] == 0) {
        num_roots = quad_roots(a + 1, r + 1);
      } else {
        double coeff[] = {-a[0] / r[1], a[2] + r[1], 1.0};
        num_roots = quad_roots(coeff, r + 1);
      }

      if (num_roots == 0) {
        // complex solution
        return 0;
      }

      // all real roots
      bubbleSort(r + 1, 3);
      return countDistinct(r);
    }
  }
}
