#include <math.h>
#include <float.h>

int lin_root(double a1, double a0, double *r);

void sortDescend(double *r1, double *r2) {
  if (*r1 < *r2) {
    double tmp = *r1;
    *r1 = *r2;
    *r2 = tmp;
  }
}

int a1_overflow(double a1) {
  return fabs(a1) > sqrt(DBL_MAX);
}

int a1_underflow(double a2, double a1, double a0) {
  return fabs(a1) > 0 && fabs(a1) < 1
      && fabs(a1) / sqrt(DBL_MIN) < fabs(a2)
      && fabs(a1) / sqrt(DBL_MIN) < fabs(a0);
}

int a2a0_overflow(double a2, double a0) {
  return (fabs(a2) > 1 / 4. && fabs(a0) > DBL_MAX / 4. / fabs(a2))
      || (fabs(a0) > 1 / 4. && fabs(a2) > DBL_MAX / 4. / fabs(a0));
  // 4*a2*a0 might underflow
}

int a2a0_underflow(double a2, double a0) {
  return (fabs(a2) > 0 && fabs(a2) < 1 / 4. && fabs(a0) < DBL_MIN / fabs(a2) / 4.)
      || (fabs(a0) > 0 && fabs(a0) < 1 / 4. && fabs(a2) < DBL_MIN / fabs(a2) / 4.);
  // 4*a2*a0 might overflow
}

// returns number of roots or negative number if error
int quad_roots(double a2, double a1, double a0, double *r1, double *r2) {
  // a1x + a0 = 0
  if (a2 == 0) {
    int num_roots = lin_root(a1, a0, r1);
    if (*r1 > 0) {
      *r2 = 0;
    } else {
      *r2 = *r1;
      *r1 = 0;
    }
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
  if (a1_underflow(a2, a1, a0)) {
    a1 = 0;
  }

  double discriminant, ra;
  if (!a2a0_underflow(a2, a0) && !a2a0_overflow(a2, a0) && !a1_overflow(a1)) {
    // no overflow
    discriminant = a1 * a1 - 4 * a2 * a0;
    if (discriminant < 0) {
      // complex solution
      ra = sqrt(-discriminant) / a2;
    } else {
      ra = sqrt(discriminant) / a2;
    }
  } else if (a1_overflow(a1)) {
    if (a2a0_underflow(a2, a0)) {
      discriminant = 1;
      ra = fabs(a1) / a2;
    } else {
      // we don't know if a2a0 will overflow but we dont care
      // refactor a1 out of sqrt, a1 is big
      discriminant = 1 - 4 * (a2 / a1) * (a0 / a1);
      if (discriminant < 0) {
        // complex solution
        ra = fabs(a1) / a2 * sqrt(-discriminant);
      } else {
        ra = fabs(a1) / a2 * sqrt(discriminant);
      }
    }
  } else {
    // we know at this point that a1 does not overflow, a1 might be zero if it underflow
    if (a2a0_underflow(a2, a0) && fabs(a1) > sqrt(DBL_MIN)) {
      discriminant = a1 * a1;
      ra = fabs(a1) / a2;
    } else {
      discriminant = (fabs(a1) / fabs(a2)) * (fabs(a1) / fabs(a0));
      if ((a2 > 0 && a0 > 0) || (a2 < 0 && a0 < 0)) {
        discriminant -= 4;
      } else {
        discriminant += 4;
      }

      if (discriminant < 0) {
        // complex solution
        ra = sqrt(fabs(a2)) * sqrt(fabs(a0)) / a2 * sqrt(-discriminant);
      } else {
        ra = sqrt(fabs(a2)) * sqrt(fabs(a0)) / a2 * sqrt(discriminant);
      }
    }
  }

  // one solution
  if (ra == 0) {
    *r1 = -a1 / a2 / 2;
    *r2 = *r1;
    return 1;
  }

  if (discriminant < 0) {
    // complex solution
    *r1 = -a1 / a2 / 2;
    // use the positive conjugate as required by spec
    *r2 = fabs(ra) / 2;
    return 0;
  }

  // required for r1 >= r2
  *r1 = (-a1 / a2 + ra) / 2;
  *r2 = (-a1 / a2 - ra) / 2;
  sortDescend(r1, r2);

  // handle summation of opposite sign with equal magnitude
  if (*r1 != 0 && *r2 != 0
      && fabs(a0) > DBL_MIN * fabs(a2)
      && fabs(a2) < 1 && fabs(a0) < DBL_MAX * fabs(a2)) {
    if (a1 < 0) {
      *r2 = a0 / a2 / *r1;
    } else {
      *r1 = a0 / a2 / *r2;
    }
  }

  return discriminant < 0 ? 0 : 2;
}
