#include <stdio.h>

int lin_root(double *, double *);
int quad_roots(double *, double *);
int rcubic_roots(double *, double *);

int main() {
  int num_roots;

  printf("\n*** Testing lin_root ***\n");
  double lin_a[] = {1, 2};
  double lin_r[2];

  num_roots = lin_root(lin_a, lin_r);
  printf("a[0] = %.15lf, a[1] = %.15lf\n", lin_a[0], lin_a[1]);
  printf("number of linear root = %d\n", num_roots);
  printf("r[1] = %.15lf\n", lin_r[1]);

  printf("\n*** Testing quad_roots ***\n");
  double quad_a[] = {1, 2, 1};
  double quad_r[3];

  num_roots = quad_roots(quad_a, quad_r);
  printf("a[0] = %.15lf, a[1] = %.15lf, a[2] = %.15lf\n", quad_a[0], quad_a[1], quad_a[2]);
  printf("number of quad roots = %d\n", num_roots);
  printf("r[1] = %.15lf, r[2] = %.15lf\n", quad_r[1], quad_r[2]);

  printf("\n*** Testing rcubic_roots ***\n");
  double cubic_a[] = {1, 2, 1};
  double cubic_r[4];

  num_roots = rcubic_roots(cubic_a, cubic_r);
  printf("a[0] = %.15lf, a[1] = %.15lf, a[2] = %.15lf\n", cubic_a[0], cubic_a[1], cubic_a[2]);
  printf("number of cubic roots = %d\n", num_roots);
  printf("r[1] = %.15lf, r[2] = %.15lf, r[3] = %.15lf\n", cubic_r[1], cubic_r[2], cubic_r[2]);

  return 0;
}
