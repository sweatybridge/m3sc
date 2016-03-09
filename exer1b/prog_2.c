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

  double r1, r2, r3;
  int num_roots;

  // Test your program on the three cubic equations:
  num_roots = rcubic_roots(2, -5, -6, &r1, &r2, &r3);
  printf("no. of distinct real roots = %d\n", num_roots);
  printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf\n\n", r1, r2, r3);

  num_roots = rcubic_roots(5, 3, -9, &r1, &r2, &r3);
  printf("no. of distinct real roots = %d\n", num_roots);
  printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf\n\n", r1, r2, r3);

  num_roots = rcubic_roots(1, -1, -15, &r1, &r2, &r3);
  printf("no. of distinct real roots = %d\n", num_roots);
  printf("r1 = %.15lf, r2 = %.15lf, r3 = %.15lf\n\n", r1, r2, r3);
}
