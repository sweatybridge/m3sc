#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef INSTRUMENT
extern long long add_sub_count, div_count, mul_count;
#endif

double *Gauss(double **A, double *y, int N);
double *BGauss(double **C, double *y, int N, int B);

typedef struct {
  // 0 = rought, 1 = smooth
  double max_phi[2];
  double max_x[2];
  double max_y[2];
  double exec_time_gauss;
  double exec_time_bgauss;
  unsigned long long total_inst_gauss;
  unsigned long long total_inst_bgauss;
} Result;

void printContour(double **phi, int N) {
  double delta = 1. / N;

  // header
  for (int i = 0; i < 33; ++i) {
    printf("%.4lf %.4lf %.4lf\n", 0., i / (double) 32, 0.);
  }
  printf("\n");

  // body
  for (int i = 1; i < N; ++i) {
    if (i % (N / 32) == 0) {
      printf("%.4lf %.4lf %.4lf\n", delta * i, 0., 0.);
    }
    for (int j = 1; j < N; ++j) {
      if (i % (N / 32) == 0 && j % (N / 32) == 0) {
        printf("%.4lf %.4lf %.4lf\n", delta * i, delta * j, phi[i][j]);
      }
    }
    if (i % (N / 32) == 0) {
      printf("%.4lf %.4lf %.4lf\n", delta * i, 1., 0.);
      printf("\n");
    }
  }

  // footer
  for (int i = 0; i < 33; ++i) {
    printf("%.4lf %.4lf %.4lf\n", 1., i / (double) 32, 0.);
  }
}

double p(double x, double y, int isSmooth) {
  if (isSmooth) {
    if ((x == 0.25 && y == 0.25) ||
        (x == 0.25 && y == 0.5) ||
        (x == 0.5 && y == 0.25) ||
        (x == 0.5 && y == 0.5)) {
      return 25;
    }
    if ((y == 0.25 && 0.25 < x && x < 0.5) ||
        (x == 0.25 && 0.25 < y && y < 0.5) ||
        (y == 0.5 && 0.25 < x && x < 0.5) ||
        (x == 0.5 && 0.25 < y && y < 0.5)) {
      return 50;
    }
  }
  return (0.25 <= x && x <= 0.5 && 0.25 <= y && y <= 0.5) ? 100 : 0;
}

Result solvePoisson(int N, int skipGauss) {
  int j, jj, k, m, a_size, idx;
  double delta, **A, *y, *phi;
  clock_t tStart;
  Result result = {{0}, {0}, {0}, 0, 0, 0, 0};

  delta = 1. / N;
  m = 2 * N - 1;
  a_size = (N - 1) * (N - 1) + 1;

  A = malloc(a_size * sizeof(double *));
  y = malloc(a_size * sizeof(double));

  // 0 = rough, 1 = smooth
  for (k = 0; k < 2; k++) {
    A[0] = calloc((size_t) (m + 1) * a_size, sizeof(double));
    // initialise banded matrix
    // 0  0  0 -4  1  0  1
    // 0  0  1 -4  1  0  1
    // 0  0  1 -4  0  0  1
    // 1  0  0 -4  1  0  1
    // 1  0  1 -4  1  0  1
    // 1  0  1 -4  0  0  1
    // 1  0  0 -4  1  0  0
    // 1  0  1 -4  1  0  0
    // 1  0  1 -4  0  0  0
#pragma omp parallel for schedule(static)
    for (j = 1; j < a_size; j++) {
      A[j] = A[0] + j * (m + 1);

      A[j][1] = j < N ? 0 : 1;
      A[j][N - 1] = j % (N - 1) == 1 ? 0 : 1;
      A[j][N] = -4;
      A[j][N + 1] = j % (N - 1) == 0 ? 0 : 1;
      A[j][m] = j > a_size - N ? 0 : 1;

      y[j] = -delta * delta * p((j / (N - 1) + 1) * delta, j % (N - 1) * delta, k);
    }

    tStart = clock();
    phi = BGauss(A, y, a_size - 1, N - 1);
    result.exec_time_bgauss += (clock() - tStart) / (double) CLOCKS_PER_SEC;

#ifdef INSTRUMENT
    result.total_inst_bgauss += add_sub_count + div_count + mul_count;
#endif

//#pragma omp parallel for collapse(2) schedule(static) reduction(max: max_phi)
    for (j = 1; j < N; j++) {
      for (jj = 1; jj < N; jj++) {
        if (result.max_phi[k] > phi[(j - 1) * (N - 1) + jj]) {
          continue;
        }
        result.max_phi[k] = phi[(j - 1) * (N - 1) + jj];
        result.max_x[k] = delta * j;
        result.max_y[k] = delta * jj;
      }
    }

    free(A[0]);
    free(phi);
  }

  // Gauss
  if (!skipGauss) {
    for (k = 0; k < 2; k++) {
      A[0] = calloc((size_t) a_size * a_size, sizeof(double));
      // initialise full matrix
      // 00 11 12 13 21 22 23 31 32 33
      //  0 -4  1  0  1  0  0  0  0  0 = 11
      //  0  1 -4  1  0  1  0  0  0  0 = 12
      //  0  0  1 -4  0  0  1  0  0  0 = 13
      //  0  1  0  0 -4  1  0  1  0  0 = 21
      //  0  0  1  0  1 -4  1  0  1  0 = 22
      //  0  0  0  1  0  1 -4  0  0  1 = 23
      //  0  0  0  0  1  0  0 -4  1  0 = 31
      //  0  0  0  0  0  1  0  1 -4  1 = 32
      //  0  0  0  0  0  0  1  0  1 -4 = 33
#pragma omp parallel for schedule(static)
      for (j = 1; j < a_size; j++) {
        A[j] = A[0] + j * a_size;

        idx = j + 1 - N;
        if (idx > 0) {
          A[j][idx] = 1;
        }
        idx = j - 1;
        if (idx > 0) {
          A[j][idx] = j % (N - 1) == 1 ? 0 : 1;
        }
        A[j][j] = -4;
        idx = j + 1;
        if (idx < a_size) {
          A[j][idx] = j % (N - 1) == 0 ? 0 : 1;
        }
        idx = j + N - 1;
        if (idx < a_size) {
          A[j][idx] = 1;
        }

        y[j] = -delta * delta * p((j / (N - 1) + 1) * delta, j % (N - 1) * delta, k);
      }

      tStart = clock();
      phi = Gauss(A, y, a_size - 1);
      result.exec_time_gauss += (clock() - tStart) / (double) CLOCKS_PER_SEC;

#ifdef INSTRUMENT
      result.total_inst_gauss += add_sub_count + div_count + mul_count;
#endif

      free(A[0]);
      free(phi);
    }
  }

  free(A);
  free(y);

  return result;
}

int main(void) {
  // print table header
  printf("%12s %17s %17s %17s %17s %17s %17s %12s %12s %12s %12s\n",
         "N",
         "Max Phi_r",
         "x_rough",
         "y_rough",
         "Max Phi_s",
         "x_smooth",
         "y_smooth",
         "time_gauss",
         "speed_guass",
         "time_bgauss",
         "speed_bguass");

  int skipGauss = 0;
  int N = 4;
  int i;
  Result result;

  for (i = 4; i < 31; i++) {
    if (i < 6) {
      N += 4;
    } else {
      N += 1 << (i / 3);
    }

    result = solvePoisson(N, skipGauss);

    printf("%12d %.15lf %.15lf %.15lf %.15lf %.15lf %.15lf ",
           N,
           result.max_phi[0],
           result.max_x[0],
           result.max_y[0],
           result.max_phi[1],
           result.max_x[1],
           result.max_y[1]);

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
