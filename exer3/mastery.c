#include <stdio.h>
#include <stdlib.h>

double *SFactors(int N);
int FastSN(double *x, double *y, double *w, double *S, int N, int skip);

int main(int argc, char *argv[]) {
  int N = 20;

  if (argc > 1) {
    N = atoi(argv[1]);
  }

  double x[N], y[N], w[N];
  double *S = SFactors(N);

  for (int i = 1; i < N; ++i) {
    y[i] = i;
  }

  // solve DST
  FastSN(x, y, w, S, N, 1);

  printf("N = %d\n", N);
  for (int i = 1; i < N; ++i) {
    printf("y[%d] = %.1lf, x[%d] = %.15lf\n", i, y[i], i, x[i]);
  };

  free(S);
  return 0;
}
