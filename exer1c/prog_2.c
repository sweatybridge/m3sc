#include <stdio.h>

int rquartic_roots(double *a, double *root);

int main(void) {
  /* Han, Qiao: 00729653 */
  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");
  printf("%20s: %s\n", "Time", __TIME__);
  printf("%20s: %s\n", "Date", __DATE__);

  double a[] = {210, -47, -39, 3};
  double r[5];

  int num_roots = rquartic_roots(a, r);

  printf("Solutions for x4 + 3 x3 - 39 x2 – 47 x + 210 = 0\n");
  switch (num_roots) {
    case 0:
      printf("Complex roots.");
      printf("real(r1) = %.15lf, imag(r1) = %.15lf, real(r2) = %.15lf, imag(r2) = %.15lf\n", r[1], r[2], r[3], r[4]);
      break;
    case 1:
      printf("Triple or quadruple roots.");
      printf("r1 = %.15lf, r2 = %.15lf\n", r[1], r[4]);
      break;
    case 2:
      printf("Two real, two complex.");
      printf("r1 = %.15lf, r2 = %.15lf, real(r3) = %.15lf, imag(r3) = %.15lf\n", r[1], r[2], r[3], r[4]);
      break;
    case 3:
      printf("One repeated root.");
      printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf, r4 = %.15lf\n", r[1], r[2], r[3], r[4]);
      break;
    case 4:
      printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf, r4 = %.15lf\n", r[1], r[2], r[3], r[4]);
      break;
    default:
      break;
  }

  return 0;
}
