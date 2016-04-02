#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef INSTRUMENT
extern unsigned long long add_sub_count, div_count, mul_count;
#endif

typedef struct {
  // 0 = rought, 1 = smooth
  double max_phi[2];
  double max_x[2];
  double exec_time_gauss;
  double exec_time_bgauss;
  unsigned long long total_inst_gauss;
  unsigned long long total_inst_bgauss;
} Result;

double *Gauss(double **A, double *y, int N);
double *BGauss(double **C, double *y, int N, int B);

double p(double x, int isSmooth) {
  if (isSmooth) {
    if (x == 0.25 || x == 0.5) {
      return 40;
    }
  }
  return 0.25 <= x && x <= 0.5 ? 80 : 0;
}

Result solvePoisson(int N, int skipGauss) {
  int j, k, m;
  double delta, **A, *y, *phi;
  clock_t tStart;
  Result result = {{0}, {0}, 0, 0, 0, 0};

  m = 3;
  delta = 1. / N;

  A = malloc(N * sizeof(double *));
  y = malloc(N * sizeof(double));
  for (j = 0; j < N; j++) {
    A[j] = malloc((m + 1) * sizeof(double));
  }

  // 0 = rough, 1 = smooth
  for (k = 0; k < 2; k++) {
    // initialise banded matrix
    // 0 0  0 0
    // 0 0 -2 1
    // 0 1 -2 1
    // 0 1 -2 1
    // 0 1 -2 0
    for (j = 1; j < N; j++) {
      A[j][1] = 1;
      A[j][2] = -2;
      A[j][3] = 1;
    }
    A[1][1] = 0;
    A[N - 1][3] = 0;

    for (j = 1; j < N; j++) {
      y[j] = -delta * delta * p(j * delta, k);
    }

    tStart = clock();
    phi = BGauss(A, y, N - 1, (m - 1) / 2);
    result.exec_time_bgauss += (clock() - tStart) / (double) CLOCKS_PER_SEC;

#ifdef INSTRUMENT
    result.total_inst_bgauss += add_sub_count + mul_count + div_count;
#endif

    // find max and print
    for (j = 1; j < N; j++) {
      if (phi[j] > result.max_phi[k]) {
        result.max_phi[k] = phi[j];
        result.max_x[k] = delta * j;
      }
    }

    free(phi);
  }

  // Gauss
  if (!skipGauss) {
    for (j = 0; j < N; j++) {
      free(A[j]);
      A[j] = calloc((size_t) N, sizeof(double));
    }

    for (k = 0; k < 2; k++) {
      // initialise full matrix
      A[1][1] = -2;
      A[1][2] = 1;
      for (j = 2; j < N - 1; j++) {
        A[j][j - 1] = 1;
        A[j][j] = -2;
        A[j][j + 1] = 1;
      }
      A[N - 1][N - 2] = 1;
      A[N - 1][N - 1] = -2;

      for (j = 1; j < N; j++) {
        y[j] = -delta * delta * p(j * delta, k);
      }

      tStart = clock();
      phi = Gauss(A, y, N - 1);
      result.exec_time_gauss += (clock() - tStart) / (double) CLOCKS_PER_SEC;

#ifdef INSTRUMENT
      result.total_inst_gauss += add_sub_count + mul_count + div_count;
#endif

      free(phi);
    }
  }
  for (j = 0; j < N; j++) {
    free(A[j]);
  }
  free(A);
  free(y);
  return result;
}

int main(void) {
  /* Han, Qiao: 00729653 */
  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");
  printf("%20s: %s\n", "Time", __TIME__);
  printf("%20s: %s\n", "Date", __DATE__);

  printf("%12s %17s %17s %17s %17s %12s %12s %12s %12s\n",
         "N",
         "Max Phi_r",
         "x_rough",
         "Max Phi_s",
         "x_smooth",
         "time_gauss",
         "speed_guass",
         "time_bgauss",
         "speed_bguass");

  int i, N, skipGauss;
  skipGauss = 0;
  Result result;

  for (i = 3; i < 31; i++) {
    N = 1 << i;

    result = solvePoisson(N, skipGauss);

    printf("%12d %.15lf %.15lf %.15lf %.15lf ",
           N,
           result.max_phi[0],
           result.max_x[0],
           result.max_phi[1],
           result.max_x[1]);

#ifdef INSTRUMENT
    if (skipGauss) {
      printf("%12s %12s ", "> 100s", "N.A.");
    } else {
      printf("%12g %12g ", result.exec_time_gauss, result.total_inst_gauss / result.exec_time_gauss * 1e-9);
    }
    printf("%12g %12g ", result.exec_time_bgauss, result.total_inst_bgauss / result.exec_time_bgauss * 1e-9);
#endif

    printf("\n");

    if (result.exec_time_gauss > 100) {
      skipGauss = 1;
    }

    if (result.exec_time_bgauss > 100) {
      break;
    }
  }

  return 0;
}
