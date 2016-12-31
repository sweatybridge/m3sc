#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int powerof2(int x);
double *SFactors(int N);
int FastSN(double *x, double *y, double *w, double *S, int N, int skip);

int main(int argc, char *argv[]) {
  int max = 1048576;

  if (argc > 1) {
    max = atoi(argv[1]);
  }

  printf("%6s %17s %17s %12s\n", "N", "FastSN Time", "SlowSN Time", "Ratio");
  for (int N = 3; N < max; ++N) {
    // skip non permitted values
    if (!powerof2(N)) {
      if (N % 3 != 0 || !powerof2(N / 3)) {
        continue;
      }
    }

    double x[N], y[N], w[N];
    double *S = SFactors(N);

    for (int i = 1; i < N; ++i) {
      y[i] = i;
    }

    // solve DST
    clock_t fast = clock();
    FastSN(x, y, w, S, N, 1);
    fast = clock() - fast;
    free(S);

    double expected[N];
    clock_t slow = clock();
    for (int i = 1; i < N; ++i) {
      expected[i] = 0;
      for (int j = 1; j < N; ++j) {
        if (i * j % N != 0) {
          expected[i] += y[j] * sin(i * j * M_PI / N);
        }
      }
    }
    slow = clock() - slow;

    printf("%6d %.15lf %.15lf %12g\n",
           N,
           fast / (double) CLOCKS_PER_SEC,
           slow / (double) CLOCKS_PER_SEC,
           slow / (double) fast);
  }
  return 0;
}
