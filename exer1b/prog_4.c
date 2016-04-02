#include <stdio.h>

int rcubic_roots(double a2, double a1, double a0, double *r1, double *r2, double *r3);

int main(void) {
  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");
  printf("%20s: %s\n", "Time", __TIME__);
  printf("%20s: %s\n", "Date", __DATE__);

  double r = 0.0820578;
  double b = 0.01709;
  double a = 0.2135;

  double r1, r2, r3, t, p;
  printf("%14s %14s %14s %14s %14s %14s\n", "T (Kelvin)", "P (atm)", "Vi (liters)", "V1", "V2", "V3");
  for (t = 40; t <= 50; t += 5) {
    for (p = 1; p <= 30; p += 0.5) {
      double a2 = - (b + r * t / p);
      double a1 = a / p;
      double a0 = - a * b / p;

      double v = r * t / p;
      int num_roots = rcubic_roots(a2, a1, a0, &r1, &r2, &r3);

      printf("%14.7g %14.7g %14.7g ", t, p, v);
      switch (num_roots) {
        case 3:
          printf("%14.7g %14.7g %14.7g\n", r1, r2, r3);
          break;
        case 0:
          printf("%14.7g\n", r1);
          break;
        default:
          break;
      }
    }
  }

  return 0;
}
