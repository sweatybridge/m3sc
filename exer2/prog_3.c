#include <stdlib.h>
#include <stdio.h>

#ifdef INSTRUMENT
extern long add_sub_count, div_count, mul_count;
#endif

double *BGauss(double **C, double *y, int N, int B);

int main(void) {
  double A0[] = {0, 0, 0, 0};
  double A1[] = {0, 0, -2, 1};
  double A2[] = {0, 1, -2, 1};
  double A3[] = {0, 1, -2, 0};
  double *A[4] = {A0, A1, A2, A3};
  double y[] = {0, 2, 2, 2};
  int N = 3;

  int i;
  double *x = BGauss(A, y, N, 1);
  for (i = 0; i < N; i++) {
    printf("x[%d] = %lf\n", i + 1, x[i + 1]);
  }
  free(x);

#ifdef INSTRUMENT
  printf("add / sub = %lu, mul = %lu, div = %lu\n", add_sub_count, mul_count, div_count);
#endif

  printf("\n");

  double B0[] = {0, 0, 0, 0, 0, 0};
  double B1[] = {0, 0, 0, 5, -4, 1};
  double B2[] = {0, 0, -4, 6, -4, 1};
  double B3[] = {0, 1, -4, 6, -4, 1};
  double B4[] = {0, 1, -4, 6, -4, 1};
  double B5[] = {0, 1, -4, 6, -4, 1};
  double B6[] = {0, 1, -4, 6, -4, 1};
  double B7[] = {0, 1, -4, 7, -4, 0};
  double B8[] = {0, 2, -8, 6, 0, 0};
  double *B[9] = {B0, B1, B2, B3, B4, B5, B6, B7, B8};
  double by[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  N = 8;

  x = BGauss(B, by, N, 2);
  for (i = 0; i < N; i++) {
    printf("x[%d] = %lf\n", i + 1, x[i + 1]);
  }
  free(x);

#ifdef INSTRUMENT
  printf("add / sub = %lu, mul = %lu, div = %lu\n", add_sub_count, mul_count, div_count);
#endif

  return 0;
}
