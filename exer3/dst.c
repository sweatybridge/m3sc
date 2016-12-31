int FastTN(double *x, double *y, double *w, double *S, int N, int skip);

int FastUN(double *x, double *y, double *w, double *S, int N, int skip) {
  // illegal argument
  if (N < 1 || skip < 1) {
    return -1;
  }
  // base case
  if (N == 1) {
    x[1] = S[1] * y[1];
    return 0;
  }
  // improves efficiency by reducing function calls
  if (N == 2) {
    x[1] = S[2] * y[1] + S[3] * y[2];
    x[1 + skip] = S[3] * y[1] - S[2] * y[2];
    return 0;
  }
  // p = 3
  if (N == 3) {
    // 1 5 9
    double x12 = S[4] * y[2];
    x[1] = S[3] * y[1] + x12 + S[5] * y[3];
    x[1 + skip] = S[4] * y[1] + x12 - S[4] * y[3];
    x[1 + 2 * skip] = S[5] * y[1] - x12 + S[3] * y[3];
    return 0;
  }
  // p = 5
  if (N == 5) {
    double x13 = S[7] * y[3];
    x[1] = S[5] * y[1] + S[6] * y[2] + x13 + S[8] * y[4] + S[9] * y[5];
    x[1 + skip] = S[6] * y[1] + S[9] * y[2] + x13 - S[5] * y[4] - S[8] * y[5];
    x[1 + 2 * skip] = S[7] * y[1] + S[7] * y[2] - x13 - S[7] * y[4] + S[7] * y[5];
    x[1 + 3 * skip] = S[8] * y[1] - S[5] * y[2] - x13 + S[9] * y[4] - S[6] * y[5];
    x[1 + 4 * skip] = S[9] * y[1] - S[8] * y[2] + x13 - S[6] * y[4] + S[5] * y[5];
    return 0;
  }
  // calculate directly
  if (N % 2 == 0) {
    // 1 5 9 13
    // ui = yN+1-2i –yN-2i , vi =y2i +y2i+1
    // u1 = y3 - y2, v1 = y2 + y3
    // u2 = y1, v2 = y4
    // skip = 1, N = 4
    // init vector z (even components)
    for (int j = 1; j < N / 2; ++j) {
      // w = u = a
      w[j] = y[N + 1 - 2 * j] - y[N - 2 * j];
    }
    w[N / 2] = y[1];
    // recursively solve for even components a = Tn/2 * u
    FastTN(x + skip, w, w + N / 2, S, N / 2, skip * 2);

    // init vector s (odd components)
    // erase a since it's no longer used
    for (int j = 1; j <= N / 2; ++j) {
      // w = v = b
      w[j] = y[2 * j] + y[2 * j + 1];
    }
    w[N / 2] = y[N];
    // solve for odd components b = Tn/2 * v
    FastTN(x, w, w + N / 2, S, N / 2, skip * 2);

    // combine a and b to solve x
    for (int j = 1; j <= N / 2; ++j) {
      int idx = 1 + (j - 1) * skip * 2;
      double b = x[idx];
      double a = x[idx + skip];

      // b
      w[j] = -S[N + j - 1] * b;
      // a
      if (j % 2 == 0) {
        w[j] -= S[2 * N - j] * a;
      } else {
        w[j] += S[2 * N - j] * a;
      }

      x[(j - 1) * skip + 1] = S[2 * N - j] * b;
      if (j % 2 == 0) {
        x[(j - 1) * skip + 1] -= S[N + j - 1] * a;
      } else {
        x[(j - 1) * skip + 1] += S[N + j - 1] * a;
      }
    }
    for (int j = 1; j <= N / 2; ++j) {
      x[(N - j) * skip + 1] = w[j];
    }
    return 0;
  }
  // odd case
  return -1;
}

int FastTN(double *x, double *y, double *w, double *S, int N, int skip) {
  // illegal argument
  if (N < 1 || skip < 1) {
    return -1;
  }
  // base case
  if (N == 1) {
    x[1] = y[1];
    return 0;
  }
  // improves efficiency by reducing function calls
  if (N == 2) {
    double x11 = S[1] * y[1];
    double x12 = S[0] * y[2];
    x[1] = x11 + x12;
    x[1 + skip] = x11 - x12;
    return 0;
  }
  // p = 3
  if (N == 3) {
    // 1 3 5 7 9 11
    // 3 7 11
    double x11 = S[2] * y[1];
    double x12 = S[1] * y[2];
    x[1] = x11 + x12 + y[3];
    x[1 + skip] = y[1] - y[3];
    x[1 + 2 * skip] = x11 - x12 + y[3];
    return 0;
  }
  // p = 5
  if (N == 5) {
    // 3 1 4 2 0
    double x11 = S[3] * y[1];
    double x12 = S[1] * y[2];
    double x13 = S[4] * y[3];
    double x14 = S[2] * y[4];
    double x21 = S[4] * y[1];
    double x22 = S[2] * y[2];
    double x23 = S[3] * y[3];
    double x24 = S[1] * y[4];
    x[1] = x11 + x12 + x13 + x14 + y[5];
    x[1 + skip] = x21 + x22 + x23 - x24 - y[5];
    x[1 + 2 * skip] = y[1] - y[3] + y[5];
    x[1 + 3 * skip] = x21 - x22 + x23 + x24 - y[5];
    x[1 + 4 * skip] = x11 - x12 + x13 - x14 + y[5];
    return 0;
  }
  // calculate directly
  if (N % 2 == 0) {
    // 1 3 5 7 9 11 13 15
    // 3 7 11 15
    // 7 15
    // 15
    // 1 3 5 7
    // 3 7
    // 3
    for (int j = 1; j <= N / 2; ++j) {
      w[j] = y[2 * j];
    }
    FastTN(x + skip, w, w + N / 2, S, N / 2, skip * 2);

    for (int j = 1; j <= N / 2; ++j) {
      w[j] = y[2 * j - 1];
    }
    FastUN(x, w, w + N / 2, S, N / 2, skip * 2);

    // combine z to find x
    for (int j = 1; j <= N / 2; ++j) {
      int idx = 1 + (j - 1) * skip * 2;
      w[j] = x[idx] - x[idx + skip];
      x[(j - 1) * skip + 1] = x[idx] + x[idx + skip];
    }
    for (int j = 1; j <= N / 2; ++j) {
      x[(N - j) * skip + 1] = w[j];
    }
  }
  // N is odd
  return -1;
}

int FastSN(double *x, double *y, double *w, double *S, int N, int skip) {
  // illegal argument
  if (N < 1 || skip < 1) {
    return -1;
  }
  // do nothing as x is of size 0
  if (N == 1) {
    return 0;
  }
  // calculate directly
  if (N == 2) {
    x[skip] = y[1];
    return 0;
  }
  // N is 3 * 2^m
  if (N == 3) {
    // 1 2 3 4 5 6 7 8 9 10 11
    // 2 4 6 8 10
    // 4 8
    double x11 = S[1] * y[1];
    double x12 = S[1] * y[2];
    x[skip] = x11 + x12;
    x[skip * 2] = x11 - x12;
    return 0;
  }
  // strong efficiency case
  if (N == 4) {
    double x1113 = S[1] * (y[1] + y[3]);
    x[1] = x1113 + y[2];
    x[1 + skip] = y[1] - y[3];
    x[1 + 2 * skip] = x1113 - y[2];
  }
  // 5 * 2^m
  if (N == 5) {
    double x11 = S[1] * y[1];
    double x12 = S[2] * y[2];
    double x13 = S[2] * y[3];
    double x14 = S[1] * y[4];
    double x21 = S[2] * y[1];
    double x22 = S[1] * y[2];
    double x23 = S[1] * y[3];
    double x24 = S[2] * y[4];
    x[skip] = x11 + x12 + x13 + x14;
    x[2 * skip] = x21 + x22 - x23 - x24;
    x[3 * skip] = x21 - x22 - x23 + x24;
    x[4 * skip] = x11 - x12 + x13 - x14;
    return 0;
  }
  // N is power of 2
  if (N % 2 == 0) {
    // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
    // 2 4 6 8 10 12 14
    // 4 8 12
    // 8
    // skip = 1, N = 4
    // init vector a (even components)
    for (int j = 1; j < N / 2; ++j) {
      // w = a
      w[j] = y[j] - y[N - j];
    }
    // recursively solve for even components x[2i] = Sn/2 * a
    FastSN(x, w, w + N / 2 - 1, S, N / 2, skip * 2);

    // init vector s (odd components)
    // erase a since it's no longer used
    for (int j = 1; j < N / 2; ++j) {
      // w = s
      w[j] = y[j] + y[N - j];
    }
    w[N / 2] = y[N / 2];
    // solve for odd components x[2i - 1] = Tn/2 * s
    FastTN(x + skip - 1, w, w + N / 2, S, N / 2, skip * 2);
    return 0;
  }
  // N is odd
  return -1;
}
