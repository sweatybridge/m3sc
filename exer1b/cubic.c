#include <math.h>
#include <float.h>

int quad_roots(double a2, double a1, double a0, double *r1, double *r2);
void sortDescend(double *r1, double *r2);

// used for comparing two calculated double value
int doubleEqual(double a, double b) {
  if (a == 0 || b == 0) {
    return a == b;
  }
  return (((fabs(a) <= 1 && fabs(b) <= 1) || (fabs(a) > 1 && fabs(b) > 1))
      && fabs(a / b - 1) < DBL_EPSILON / 2);
}

int countDistinct(double *r1, double *r2, double *r3) {
  if (doubleEqual(*r1, *r2) && doubleEqual(*r2, *r3)) {
    return 1;
  } else if (doubleEqual(*r1, *r2) || doubleEqual(*r2, *r3) || doubleEqual(*r1, *r3)) {
    return 2;
  } else {
    return 3;
  }
}

void sortDescend3(double *r1, double *r2, double *r3) {
  sortDescend(r1, r2);
  sortDescend(r2, r3);
  sortDescend(r1, r2);
}

int rcubic_roots(double a2, double a1, double a0, double *r1, double *r2, double *r3) {
  if (a0 == 0) {
    *r1 = 0;
    int num_roots = quad_roots(1.0, a2, a1, r2, r3);
    if (num_roots == 0) {
      // complex roots
      return 0;
    }
    sortDescend3(r1, r2, r3);
    return countDistinct(r1, r2, r3);
  } else if (a2 == 0 && a1 == 0) {
    // roots of unity
    *r1 = cbrt(-a0);
    // complex solution
    *r2 = -*r1 / 2;
    *r3 = fabs(*r1) * sqrt(3) / 2;
    return 0;
  } else if (doubleEqual(a0, a1 * a2)) {
    // factorize as (x^2 + a1)(x + a2)
    *r1 = -a2;
    if (a1 <= 0) {
      // 2 more real roots
      *r2 = sqrt(-a1);
      *r3 = -*r2;
      sortDescend3(r1, r2, r3);
      return countDistinct(r1, r2, r3);
    } else {
      // 2 complex roots
      *r2 = 0;
      *r3 = sqrt(a1);
      return 0;
    }
  } else if (doubleEqual(3 * a1, a2 * a2) && doubleEqual(27 * a0, a2 * a2 * a2)) {
    // factorize as (x + a2 / 3) ^ 3
    *r1 = -a2 / 3;
    *r2 = *r1;
    *r3 = *r1;
    return 1;
  } else {
    // x = alpha y + beta
    double beta = -a2 / 3;
    double alpha = -cbrt(a0 - (a1 * a2 / 3) + (2 * a2 * a2 * a2 / 27));
    if (alpha == 0) {
      // x = beta
      *r1 = beta;
      int num_roots = quad_roots(1.0, 0.0, a1 - a2 * a2 / 3, r2, r3);
      if (num_roots == 0) {
        // complex roots
        *r2 += beta;
        // no change to *r3, since it's complex conjugate
        return 0;
      }
      // all real roots
      *r2 += beta;
      *r3 += beta;
      sortDescend3(r1, r2, r3);
      return countDistinct(r1, r2, r3);
    } else {
      double p = (a2 * a2 / 3 - a1) / (alpha * alpha);
      // for checking repeated root if any
      double p2 = 3 / cbrt(4);
      double y2 = - 1 / cbrt(2);
      // p == 0
      if (doubleEqual(a2 * a2 / 3, a1)) {
        // y^3 - 1 = 0 => roots of unity
        *r1 = alpha + beta;
        *r2 = -alpha / 2 + beta;
        *r3 = alpha * sqrt(3) / 2;
        return 0;
      } else if (doubleEqual(p, p2)) {
        *r1 = alpha * y2 + beta;
        *r2 = *r1;
        *r3 = alpha / y2 / y2 + beta;
        sortDescend3(r1, r2, r3);
        return countDistinct(r1, r2, r3);
      } else {
        // use Newton-Raphson method
        // better initial guess
        double y = fabs(p) < 2 ? (1 - p / 3) : (1 / p);
        double prev_change = 0;
        int n;
        double y_next, change;
        for (n = 0; n < 10000; n++) {
          // y_next = y - f(y) / f'(y), simplified
          y_next = 2 * y / 3 + (2 * p * y + 3) / (9 * y * y - 3 * p);
          change = y_next - y;
          if (doubleEqual(y_next, y) ||
              (n > 3 && change / prev_change > 1)) {
            break;
          }
          prev_change = change;
          y = y_next;
        }
        *r1 = alpha * y + beta;
        int num_roots = quad_roots(1.0, a2 + *r1, -a0 / *r1, r2, r3);
        if (num_roots == 0) {
          // complex solution
          return 0;
        }
        // all real roots
        sortDescend3(r1, r2, r3);
        return countDistinct(r1, r2, r3);
      }
    }
  }
}
