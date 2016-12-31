#include <stdio.h>
#include <math.h>
#include <float.h>

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

  // correct underflow by setting coeff to 0 when too small (relative to other coeffs)
  if (fabs(a2) < 1) {
    double ceiling = fabs(a2) * 1 / sqrt(DBL_MIN);
    if (ceiling < fabs(a1) || ceiling < fabs(a0)) {
      *r1 = 0;
      lin_root(a1, a0, r2);

      // positive root is r1
      if (*r2 > 0) {
        *r1 = *r2;
        *r2 = 0;
      }
      return 2;
    }
  }
  if (fabs(a1) < 1) {
    double ceiling = fabs(a1) * sqrt(DBL_MIN);
    if (ceiling < fabs(a2) || ceiling < fabs(a0)) {
      a1 = 0;
    }
  }
  if (fabs(a0) < 1) {
    double ceiling = fabs(a0) * sqrt(DBL_MIN);
    if (ceiling < fabs(a2) || ceiling < fabs(a1)) {
      a0 = 0;
    }
  }

  double discriminant, r;
  if (fabs(a1) > sqrt(DBL_MAX)) {
    // a1*a1 overflow
    discriminant = 1 - 4 * (a2 / a1) * (a0 / a1);
    if (discriminant < 0) {
      // complex solution
      r = fabs(a1) * sqrt(-discriminant);
    } else {
      r = fabs(a1) * sqrt(discriminant);
    }
  } else if ((fabs(a2) > 1 / 4 && DBL_MAX / 4 / fabs(a2) < fabs(a0))
      || ((fabs(a0) > 1 / 4 && DBL_MAX / 4 / fabs(a0) < fabs(a2)))
      || DBL_MAX - a1 * a1 < -4 * a2 * a0) {
    // 4*a2*a0 overflows or discriminant overflows, not possible to underflow
    // if a2 < 1/sqrt(DBL_MAX) then a0 > DBL_MAX => not possible, so a1/a2 does not overflow
    discriminant = (fabs(a1) / fabs(a2)) * (fabs(a1) / fabs(a0));
    if ((a2 > 0 && a0 > 0) || (a2 < 0 && a0 < 0)) {
      discriminant -= 4;
    } else {
      discriminant += 4;
    }
    if (discriminant < 0) {
      // complex solution
      r = sqrt(fabs(a2)) * sqrt(fabs(a0)) * -discriminant;
    } else {
      r = sqrt(fabs(a2)) * sqrt(fabs(a0)) * discriminant;
    }
  } else {
    // no overflow
    discriminant = a1 * a1 - 4 * a2 * a0;
    if (discriminant < 0) {
      // complex solution
      r = sqrt(-discriminant);
    } else {
      r = sqrt(discriminant);
    }
  }

  // one solution
  if (r == 0) {
    *r1 = -a1 / (2 * a2);
    *r2 = *r1;
    return 1;
  }

  // required for r1 >= r2
  r = a2 < 0 ? -r : r;

  *r1 = (-a1 + r) / (2 * a2);
  *r2 = (-a1 - r) / (2 * a2);

  // handle summation of opposite sign with equal magnitude
  if (a1 < 0 && *r1 != 0 && *r2 != 0) {
    *r2 = a0 / a2 / *r1;
  } else {
    *r1 = a0 / a2 / *r2;
  }

  return discriminant < 0 ? 0 : 2;
}

int main() {
  double a2, a1, a0, r1, r2;

  printf("Enter coefficients of Quadratic Equation a2*x^2+a1*x+a0=0 \n");
  printf("in the order a2, a1, a0, separated by spaces\n");
  scanf("%lf %lf %lf", &a2, &a1, &a0);

  int num_roots = quad_roots(a2, a1, a0, &r1, &r2);
  switch (num_roots) {
    case 2:
      printf("r1 = %lf, r2 = %lf\n", r1, r2);
      break;
    case 1:
      printf("r = %lf\n", r1);
      break;
    case 0:
      printf("Complex solution.");
      break;
    case -1:
      printf("r = %lf\n", r1);
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
