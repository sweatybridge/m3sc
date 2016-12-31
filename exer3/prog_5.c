#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#else
#include <omp.h>
#endif

int powerof2(int x);
double *SFactors(int N);
int FastSN(double *x, double *y, double *w, double *S, int N, int skip);

typedef struct {
  double max_phi_fd;
  double max_x_fd;
  double max_y_fd;
  double max_phi_a;
  double max_x_a;
  double max_y_a;
  double exec_time;
} Result;

void printContour(double **phi, int N) {
  int columns = 256;
  double delta = 1. / N;

  // header
  for (int i = 0; i <= columns; ++i) {
    printf("%.4lf %.4lf %.4lf\n", 0., i / (double) columns, 0.);
  }
  printf("\n");

  // body
  for (int i = 1; i < N; ++i) {
    if (i % (N / columns) == 0) {
      printf("%.4lf %.4lf %.4lf\n", delta * i, 0., 0.);
    }
    for (int j = 1; j < N; ++j) {
      if (i % (N / columns) == 0 && j % (N / columns) == 0) {
        printf("%.4lf %.4lf %.4lf\n", delta * i, delta * j, phi[i][j]);
      }
    }
    if (i % (N / columns) == 0) {
      printf("%.4lf %.4lf %.4lf\n", delta * i, 1., 0.);
      printf("\n");
    }
  }

  // footer
  for (int i = 0; i <= columns; ++i) {
    printf("%.4lf %.4lf %.4lf\n", 1., i / (double) columns, 0.);
  }
}

double p_smooth(double x, double y) {
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
  return (0.25 <= x && x <= 0.5 && 0.25 <= y && y <= 0.5) ? 100 : 0;
}

// convert cos(i pi / N) to S[k]
int cos2sin(int i, int N) {
  int k = 0;
  int b = N / 4;
  while (b > 0) {
    if (i % 2 == 1) {
      k = b + i / 2;
      break;
    }
    i >>= 1;
    b /= 2;
  }
  // map all invalid index to S[0]
  return k;
}

// N = 2^n + 1
Result calcPhi(int N) {
  double *S = SFactors(N);
  double delta = 1. / N;
  double *x[N];
  double *pkl[N];
  double *phi[N];
  struct timespec start, end;

#pragma omp parallel for schedule(static)
  for (int i = 0; i < N; ++i) {
    x[i] = malloc(N * sizeof(double));
    pkl[i] = malloc(N * sizeof(double));
    phi[i] = malloc(N * sizeof(double));
    for (int j = 1; j < N; ++j) {
      pkl[i][j] = p_smooth(i * delta, j * delta);
    }
  }

#ifdef __MACH__
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  start.tv_sec = mts.tv_sec;
  start.tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_REALTIME, &start);
#endif

  // init pkl matrix
#pragma omp parallel for schedule(static)
  for (int i = 1; i < N; ++i) {
    double w[N];
    FastSN(x[i], pkl[i], w, S, N, 1);
  }
#pragma omp parallel for schedule(static)
  for (int i = 1; i < N; ++i) {
    double w[N], p[N];
    for (int j = 1; j < N; ++j) {
      p[j] = x[j][i];
    }
    FastSN(pkl[i], p, w, S, N, 1);
    for (int j = 1; j < N; ++j) {
      pkl[i][j] *= 4. / N / N;
    }
  }

  // calculate phi_fd
#pragma omp parallel for schedule(static)
  for (int l = 1; l < N; ++l) {
    double c1 = 0;
    if (powerof2(N)) {
      int j = N / 2 - l;
      if (j != 0) {
        c1 = j < 0 ? -S[cos2sin(-j, N)] : S[cos2sin(j, N)];
      }
    } else {
      c1 = cos(l * M_PI / N);
    }
    for (int k = 1; k < N; ++k) {
      double c2 = 0;
      if (powerof2(N)) {
        int i = N / 2 - k;
        if (i != 0) {
          c2 = i < 0 ? -S[cos2sin(-i, N)] : S[cos2sin(i, N)];
        }
      } else {
        c2 = cos(k * M_PI / N);
      }
      phi[l][k] = delta * delta * pkl[l][k] / (4 - 2 * c1 - 2 * c2);
    }
    double w[N];
    FastSN(x[l], phi[l], w, S, N, 1);
  }
#pragma omp parallel for schedule(static)
  for (int k = 1; k < N; ++k) {
    double w[N], p[N];
    for (int l = 1; l < N; ++l) {
      p[l] = x[l][k];
    }
    FastSN(phi[k], p, w, S, N, 1);
  }

#ifdef __MACH__
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  end.tv_sec = mts.tv_sec;
  end.tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_REALTIME, &end);
#endif

  Result result = {0, 0, 0, 0, 0, 0, 0};
  result.exec_time = ((double) end.tv_sec + 1e-9 * end.tv_nsec) - ((double) start.tv_sec + 1e-9 * start.tv_nsec);

  printContour(phi, N);

  // phi_ij
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      if (phi[i][j] > result.max_phi_fd) {
        result.max_phi_fd = phi[i][j];
        result.max_x_fd = i * delta;
        result.max_y_fd = j * delta;
      }
    }
  }

  // calculate analytic phi
#pragma omp parallel for schedule(static)
  for (int l = 1; l < N; ++l) {
    double w[N];
    for (int k = 1; k < N; ++k) {
      phi[l][k] = pkl[l][k] / ((k * (double) k + l * (double) l) * M_PI * M_PI);
    }
    FastSN(x[l], phi[l], w, S, N, 1);
  }
#pragma omp parallel for schedule(static)
  for (int k = 1; k < N; ++k) {
    double w[N], p[N];
    for (int l = 1; l < N; ++l) {
      p[l] = x[l][k];
    }
    FastSN(phi[k], p, w, S, N, 1);
  }

  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      if (phi[i][j] > result.max_phi_a) {
        result.max_phi_a = phi[i][j];
        result.max_x_a = i * delta;
        result.max_y_a = j * delta;
      }
    }
  }

  free(S);
#pragma omp parallel for schedule(static)
  for (int i = 0; i < N; ++i) {
    free(x[i]);
    free(pkl[i]);
    free(phi[i]);
  }
  return result;
}

int main(int argc, char *argv[]) {
  int max = 1048576;

  if (argc > 1) {
    max = atoi(argv[1]);
  }

  printf("%6s %17s %17s %17s %17s %17s %17s %12s\n",
         "N",
         "Phi_FD max",
         "Phi_FD x",
         "Phi_FD y",
         "Phi_a max",
         "Phi_a x",
         "Phi_a y",
         "Time");
  for (int N = 3; N < max; ++N) {
    // skip non permitted values
    if (!powerof2(N)) {
      if (N % 3 != 0 || !powerof2(N / 3)) {
        if (N % 5 != 0 || !powerof2(N / 5)) {
          continue;
        }
      }
    }

    Result result = calcPhi(N);

    printf("%6d %.15lf %.15lf %.15lf %.15lf %.15lf %.15lf %12g\n",
           N,
           result.max_phi_fd,
           result.max_x_fd,
           result.max_y_fd,
           result.max_phi_a,
           result.max_x_a,
           result.max_y_a,
           result.exec_time);
    if (result.exec_time > 60 * 5) {
      break;
    }
  }
  return 0;
}
