#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef INSTRUMENT
extern long long add_sub_count, div_count, mul_count;
#endif

double *Gauss(double **A, double *y, int N);
double *BGauss(double **C, double *y, int N, int B);

typedef struct {
  double max_phi;
  double max_x;
  double max_y;
  double max_z;
  double exec_time_gauss;
  double exec_time_bgauss;
  unsigned long long total_inst_gauss;
  unsigned long long total_inst_bgauss;
} Result;

double p(double x, double y, double z, int isSmooth) {
  if (isSmooth) {
    if ((x == 0.25 && y == 0.25 && z == 0.25) ||
        (x == 0.25 && y == 0.25 && z == 0.5) ||
        (x == 0.25 && y == 0.5 && z == 0.25) ||
        (x == 0.25 && y == 0.5 && z == 0.5) ||
        (x == 0.5 && y == 0.25 && z == 0.25) ||
        (x == 0.5 && y == 0.25 && z == 0.5) ||
        (x == 0.5 && y == 0.5 && z == 0.25) ||
        (x == 0.5 && y == 0.5 && z == 0.5)) {
      return 25;
    }
    if ((x == 0.25 && y == 0.25 && 0.25 < z && z < 0.5) ||
        (x == 0.25 && z == 0.25 && 0.25 < y && y < 0.5) ||
        (y == 0.25 && z == 0.25 && 0.25 < x && x < 0.5) ||
        (x == 0.5 && y == 0.5 && 0.25 < z && z < 0.5) ||
        (x == 0.5 && z == 0.5 && 0.25 < y && y < 0.5) ||
        (y == 0.5 && z == 0.5 && 0.25 < x && x < 0.5) ||
        (x == 0.25 && y == 0.5 && 0.25 < z && z < 0.5) ||
        (y == 0.5 && z == 0.25 && 0.25 < x && x < 0.5) ||
        (x == 0.25 && z == 0.5 && 0.25 < y && y < 0.5) ||
        (y == 0.25 && z == 0.5 && 0.25 < x && x < 0.5) ||
        (x == 0.5 && y == 0.25 && 0.25 < z && z < 0.5) ||
        (x == 0.5 && z == 0.25 && 0.25 < y && y < 0.5)) {
      return 50;
    }
    if ((x == 0.25 && 0.25 < y && y < 0.5 && 0.25 < z && z < 0.5) ||
        (x == 0.5 && 0.25 < y && y < 0.5 && 0.25 < z && z < 0.5) ||
        (y == 0.25 && 0.25 < x && x < 0.5 && 0.25 < z && z < 0.5) ||
        (y == 0.5 && 0.25 < x && x < 0.5 && 0.25 < z && z < 0.5) ||
        (z == 0.25 && 0.25 < y && y < 0.5 && 0.25 < x && x < 0.5) ||
        (z == 0.5 && 0.25 < y && y < 0.5 && 0.25 < x && x < 0.5)) {
      return 100;
    }
  }
  return (0.25 <= x && x <= 0.5 && 0.25 <= y && y <= 0.5 && 0.25 <= z && z <= 0.5) ? 200 : 0;
}

Result solvePoisson(int N, int skipGauss) {
  int j, k, jj, jjj;
  Result result = {0, 0, 0, 0, 0, 0, 0, 0};

  double delta = 1. / N;
  int B = (N - 1) * (N - 1);
  int m = 2 * B + 1;

  int a_size = (N - 1) * (N - 1) * (N - 1) + 1;
  double **A = malloc(a_size * sizeof(double *));
  double *y = malloc(a_size * sizeof(double));

  // 0 = rough, 1 = smooth
  for (k = 1; k < 2; k++) {
    A[0] = calloc((size_t) (m + 1) * a_size, sizeof(double));
    // initialise banded matrix
    //  0 -6   1   0   1   0   0   0   0   0   1 = 111
#pragma omp parallel for schedule(static)
    for (j = 1; j < a_size; j++) {
      A[j] = A[0] + j * (m + 1);

      int triple = (j - 1) / (N - 1) % (N - 1);
      A[j][1] = j <= B ? 0 : 1;
      A[j][B - N + 2] = triple == 0 ? 0 : 1;
      A[j][B] = j % (N - 1) == 1 ? 0 : 1;
      A[j][B + 1] = -6;
      A[j][B + 2] = j % (N - 1) == 0 ? 0 : 1;
      A[j][B + N] = triple == (N - 2) ? 0 : 1;
      A[j][m] = j >= a_size - B ? 0 : 1;

      y[j] = -delta * delta
          * p(((j / (N - 1) + 1) / (N - 1) + 1) * delta, (j / (N - 1) + 1) % (N - 1) * delta, j % (N - 1) * delta, k);
    }

    clock_t tStart = clock();
    double *phi = BGauss(A, y, a_size - 1, B);
    result.exec_time_bgauss += (clock() - tStart) / (double) CLOCKS_PER_SEC;

#ifdef INSTRUMENT
    result.total_inst_bgauss += add_sub_count + div_count + mul_count;
#endif

    // find max and print
    for (j = 1; j < N; j++) {
      for (jj = 1; jj < N; jj++) {
        for (jjj = 1; jjj < N; jjj++) {
          int idx = (j - 1) * (N - 1) * (N - 1) + (jj - 1) * (N - 1) + jjj;
          if (result.max_phi > phi[idx]) {
            continue;
          }
          result.max_phi = phi[idx];
          result.max_x = delta * j;
          result.max_y = delta * jj;
          result.max_z = delta * jjj;
        }
      }
    }

    free(A[0]);
    free(phi);
  }

  // Gauss
  if (!skipGauss) {
    for (k = 1; k < 2; k++) {
      A[0] = calloc((size_t) a_size * a_size, sizeof(double));
      // initialise full matrix
      // 00 111 112 113 121 122 123 131 132 133 211 212 213 221 222 223 231 232 233 311 312 313 321 322 323 331 332 333
      // 00 111 112 113 123 122 121 131 132 133 233 232 231 221 222 223 213 212 211 311 312 313 323 322 321 311 312 313
      //  0 -6   1   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 = 111
      //  0  1  -6   1   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 = 112
      //  0  0   1  -6   0   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 = 113
      //  0  1   0   0  -6   1   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0   0 = 121
      //  0  0   1   0   1  -6   1   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0   0 = 122
      //  0  0   0   1   0   1  -6   0   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0   0 = 123
      //  0  0   0   0   1   0   0  -6   1   0   0   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0   0 = 131
      //  0  0   0   0   0   1   1   1  -6   1   0   0   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0   0 = 132
      //  0  0   0   0   0   0   1   0   1  -6   0   0   0   0   0   0   0   0   1   0   0   0   0   0   0   0   0   0 = 133
      //  0  1   0   0   0   0   0   0   0   0  -6   1   0   1   0   0   0   0   0   1   0   0   0   0   0   0   0   0 = 211
#pragma omp parallel for schedule(static)
      for (j = 1; j < a_size; j++) {
        A[j] = A[0] + j * a_size;

        int triple = (j - 1) / (N - 1) % (N - 1);
        int idx = j - B;
        if (idx > 0) {
          A[j][idx] = 1;
        }
        idx = j - (N - 1);
        if (idx > 0) {
          A[j][idx] = triple == 0 ? 0 : 1;
        }
        idx = j - 1;
        if (idx > 0) {
          A[j][idx] = j % (N - 1) == 1 ? 0 : 1;
        }
        A[j][j] = -6;
        idx = j + 1;
        if (idx < a_size) {
          A[j][idx] = j % (N - 1) == 0 ? 0 : 1;
        }
        idx = j + (N - 1);
        if (idx < a_size) {
          A[j][idx] = triple == (N - 2) ? 0 : 1;
        }
        idx = j + B;
        if (idx < a_size) {
          A[j][idx] = 1;
        }

        y[j] = -delta * delta
            * p(((j / (N - 1) + 1) / (N - 1) + 1) * delta, (j / (N - 1) + 1) % (N - 1) * delta, j % (N - 1) * delta, k);
      }

      clock_t tStart = clock();
      double *phi = Gauss(A, y, a_size - 1);
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
  /* Han, Qiao: 00729653 */
  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");
  printf("%20s: %s\n", "Time", __TIME__);
  printf("%20s: %s\n", "Date", __DATE__);

  // print table header
  printf("%12s %17s %17s %17s %17s %12s %12s %12s %12s\n",
         "N",
         "Max Phi_s",
         "x_smooth",
         "y_smooth",
         "z_smooth",
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

    printf("%12d %.15lf %.15lf %.15lf %.15lf ",
           N,
           result.max_phi,
           result.max_x,
           result.max_y,
           result.max_z);

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
