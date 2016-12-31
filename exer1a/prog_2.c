#include <stdio.h>
#include <math.h>

#define len(x) (int) (sizeof(x) / sizeof((x)[0]))

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

// TEST ME PLEASE
int quad_roots_accurate(double a2, double a1, double a0, double *r1, double *r2) {
  int num_roots = quad_roots(a2, a1, a0, r1, r2);

  if (a1 < 0) {
    *r2 = a0 / a2 / *r1;
  } else {
    *r1 = a0 / a2 / *r2;
  }

  return num_roots;
}

int main(void) {
  // http://nssdc.gsfc.nasa.gov/planetary/factsheet/plutofact.html
  double radius[] = {1187000, 606000};
  double distance[] = {1, 100, 1000, 100000};

  double a2, a1, a0, r1, r2;
  a2 = 1;
  int i, j;

  printf("%8s %24s %24s \n", "", "Pluto (R = 1187 km)", "Charon (R = 606 km)");
  printf("%8s %12s %12s %12s %12s \n", "d (m)", "H Acc (m)", "H Trad (m)", "H Acc (m)", "H Trad (m)");
  for (i = 0; i < len(distance); i++) {
    double d = distance[i];
    a0 = -d * d;

    printf("%8.lf ", d);
    for (j = 0; j < len(radius); j++) {
      double r = radius[j];
      a1 = 2 * r;

      quad_roots_accurate(a2, a1, a0, &r1, &r2);
      printf("%12g ", r1);

      quad_roots(a2, a1, a0, &r1, &r2);
      printf("%12g ", r1);
    }
    printf("\n");
  }

  return 0;
}
