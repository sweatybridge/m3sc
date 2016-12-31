#include <math.h>
#include <gtest/gtest.h>

extern "C" {
double *SFactors(int N);
int FastSN(double *x, double *y, double *w, double *S, int N, int skip);
}

TEST(FastSNTest, index) {
  // {8, 4, 9, 2, 10, 5, 11, 1, 12, 6};
  int N = 32;
  for (int k = 1; k < N / 2; ++k) {
    int i = k;
    int b = N / 4;
    while (b > 0) {
      if (i % 2 == 1) {
        i = b + i / 2;
        break;
      }
      i >>= 1;
      b /= 2;
    }
    printf("%d\n", i);
  }
}

TEST(FastSNTest, p1) {
  for (int N = 4; N < 9000; N <<= 1) {
    double x[N], y[N], w[N];
    double *S = SFactors(N);

    for (int i = 1; i < N; ++i) {
      y[i] = i;
    }

    // solve DST
    FastSN(x, y, w, S, N, 1);
    free(S);

    for (int i = 1; i < N; ++i) {
      double expected = 0;
      for (int j = 1; j < N; ++j) {
        if (i * j % N != 0) {
          expected += y[j] * sin(i * j * M_PI / N);
        }
      }
      ASSERT_NEAR(expected, x[i], fabs(expected * 1e-7));
    }
  }
}

TEST(FastSNTest, p3) {
  for (int N = 3; N < 9000; N <<= 1) {
    double x[N], y[N], w[N];
    double *S = SFactors(N);

    for (int i = 1; i < N; ++i) {
      y[i] = i;
    }

    // solve DST
    FastSN(x, y, w, S, N, 1);
    free(S);

    for (int i = 1; i < N; ++i) {
      double expected = 0;
      for (int j = 1; j < N; ++j) {
        if (i * j % N != 0) {
          expected += y[j] * sin(i * j * M_PI / N);
        }
      }
      ASSERT_NEAR(expected, x[i], fabs(expected * 1e-7));
    }
  }
}

TEST(FastSNTest, p5) {
  for (int N = 5; N < 9000; N <<= 1) {
    double x[N], y[N], w[N];
    double *S = SFactors(N);

    for (int i = 1; i < N; ++i) {
      y[i] = i;
    }

    // solve DST
    FastSN(x, y, w, S, N, 1);
    free(S);

    for (int i = 1; i < N; ++i) {
      double expected = 0;
      for (int j = 1; j < N; ++j) {
        if (i * j % N != 0) {
          expected += y[j] * sin(i * j * M_PI / N);
        }
      }
      ASSERT_NEAR(expected, x[i], fabs(expected * 1e-7));
    }
  }
}
