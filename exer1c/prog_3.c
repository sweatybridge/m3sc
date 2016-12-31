#include <stdio.h>
#include <math.h>
#include <float.h>

int doubleEqual(double a, double b);
int rquartic_roots(double *a, double *root);

void calcPhi(double *phi, double *t) {
  int i;
  for (i = 0; i < 4; i++) {
    phi[i] = atan(t[i + 1]) * 2 / M_PI * 180;
  }
}

double findB(double *t, double *phi) {
  double start = 0.40;
  double end = 0.45;
  double x = 3. / 8;
  double y = 1. / 2;

  double a[4];
  double b = 0;
  int num_roots;

  while (start / end + DBL_EPSILON < 1) {
    b = (start + end) / 2;
    a[0] = -1;
    a[1] = (2 * x - 2 + 2 * b * b) / (b * y);
    a[2] = 0;
    a[3] = (2 * x + 2 - 2 * b * b) / (b * y);
    num_roots = rquartic_roots(a, t);

    if (num_roots == 2) {
      end = b;
    } else {
      start = b;
    }
  }

  calcPhi(phi, t);

  return b;
}

void findH(double re, double rp, double x, double y, double *height, double *angle) {
  double b = rp / re;
  double coeff[4];
  coeff[0] = -1;
  coeff[1] = (2 * x / re - 2 + 2 * b * b) / (b * y / re);
  coeff[2] = 0;
  coeff[3] = (2 * x / re + 2 - 2 * b * b) / (b * y / re);
  double t[5];

  int num = rquartic_roots(coeff, t);

  int i;
  double min = DBL_MAX;
  for (i = 0; i < num; i++) {
    double xe = re * cos(atan(t[i + 1]) * 2);
    double ye = rp * sin(atan(t[i + 1]) * 2);
    double rise = y - ye;
    double run = x - xe;
    double norm = sqrt(rise * rise + run * run);
    if (norm < min) {
      min = norm;
      *height = min;
      *angle = atan(rise / run) * 180 / M_PI;
    }
  }
}

int main(void) {
  double x = 3. / 8;
  double y = 1. / 2;

  int i, j;
  printf("%3s %14s %14s %14s %14s\n", "b", "t1", "t2", "t3", "t4");
  for (i = 1; i < 20; i++) {
    double b = i * 0.05;

    double a[4];
    a[0] = -1;
    a[1] = (2 * x - 2 + 2 * b * b) / (b * y);
    a[2] = 0;
    a[3] = (2 * x + 2 - 2 * b * b) / (b * y);
    double r[5];
    int num_roots = rquartic_roots(a, r);

    double phi[4];
    calcPhi(phi, r);

    switch (num_roots) {
      case 0:
        // complex, print nothing
        // because we are only interested in real value of t
        break;
      case 1:
        // triple or quadruple root
        // solve phi with r[0]
        if (r[1] == r[4]) {
          printf("%.2f %14.7g\n", b, r[1]);
        } else {
          printf("%.2f %14.7g %14.7g\n", b, r[1], r[2]);
        }
        break;
      case 2:
        // 2 real roots
        // what if the 2 real roots are also repeated?
        //double phi1 = atan(r[1]) * 2;
        //double phi2 = atan(r[2]) * 2;
        printf("%.2f %14.7g %14.7g\n", b, r[1], r[2]);
        break;
      case 3:
        // one repeated root
        // TODO: solve 3 phi with 3 distinct r
        printf("%.2f", b);
        for (j = 0; j < 4; j++) {
          if (j == 0 || r[j] != r[j + 1]) {
            printf(" %14.7g\n", r[j + 1]);
          }
        }
        printf("\n");
        break;
      case 4:
        // 4 distinct roots
        // solve for phi
        printf("%.2f %14.7g %14.7g %14.7g %14.7g\n", b, r[1], r[2], r[3], r[4]);
        break;
      default:
        break;
    }
  }

  printf("%3s %14s %14s %14s %14s\n", "b", "phi1", "phi2", "phi3", "phi4");
  for (i = 1; i < 20; i++) {
    double b = i * 0.05;

    double a[4];
    a[0] = -1;
    a[1] = (2 * x - 2 + 2 * b * b) / (b * y);
    a[2] = 0;
    a[3] = (2 * x + 2 - 2 * b * b) / (b * y);
    double r[5];
    int num_roots = rquartic_roots(a, r);

    double phi[4];
    calcPhi(phi, r);

    switch (num_roots) {
      case 0:
        // complex, print nothing
        // because we are only interested in real value of t
        break;
      case 1:
        // triple or quadruple root
        // solve phi with r[0]
        if (r[1] == r[4]) {
          printf("%.2f %14.7g\n", b, phi[0]);
        } else {
          printf("%.2f %14.7g %14.7g\n", b, phi[0], phi[1]);
        }
        break;
      case 2:
        // 2 real roots
        // what if the 2 real roots are also repeated?
        printf("%.2f %14.7g %14.7g\n", b, phi[0], phi[1]);
        break;
      case 3:
        // one repeated root
        // TODO: solve 3 phi with 3 distinct r
        printf("%.2f", b);
        for (j = 0; j < 4; j++) {
          if (j == 0 || r[j] != r[j + 1]) {
            printf(" %14.7g\n", phi[j]);
          }
        }
        printf("\n");
        break;
      case 4:
        // 4 distinct roots
        // solve for phi
        printf("%.2f %14.7g %14.7g %14.7g %14.7g\n", b, phi[0], phi[1], phi[2], phi[3]);
        break;
      default:
        break;
    }
  }

  // find maximum b
  double t[5];
  double phi[4];
  double b = findB(t, phi);
  printf("%6s= %14.7g\n", "b ", b);
  printf("%6s: %14.7g %14.7g %14.7g %14.7g\n", "t", t[1], t[2], t[3], t[4]);
  printf("%6s: %14.7g %14.7g %14.7g %14.7g\n", "phi", phi[0], phi[1], phi[2], phi[3]);

  // find height above surface and geodetic latitude
  double height, angle;
  double re, rp;
  printf("%15s %15s %15s\n", "Satellite", "Height (m)", "Geodetic (deg)");

  // GPS
  re = 6378137;
  rp = 6356752;
  x = 4980265.80632;
  y = 4950022.89191;
  findH(re, rp, x, y, &height, &angle);
  printf("%15s %15lf %15lf\n", "Earth GPS", height, angle);

  // Cassini
  re = 60330000;
  rp = 53542792.751;
  x = 47887108.74334894;
  y = 49584769.77356416;
  findH(re, rp, x, y, &height, &angle);
  printf("%15s %15lf %15lf\n", "Cassini Probe", height, angle);

  // CID
  re = 6378137;
  rp = 6356752;
  // 4 d3 d4 d1 d2 d5 d6 , 5 d6 d5 d4 d3 d2 d1
  // 0  7  2  9  6  5  3
  x = 4967253;
  y = 5356927;
  findH(re, rp, x, y, &height, &angle);
  printf("%15s %15lf %15lf\n", "Fake CID", height, angle);

  return 0;
}
