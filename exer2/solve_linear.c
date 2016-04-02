#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#ifdef INSTRUMENT
unsigned long long div_count, mul_count, add_sub_count;
#endif

double *copy(double *y, int N) {
  /* Han, Qiao: 00729653 */
  double *x = malloc((N + 1) * sizeof(double));
  int i;
  for (i = 1; i <= N; i++) {
    x[i] = y[i];
  }
  return x;
}

double *Gauss(double **A, double *y, int N) {
  /* Han, Qiao: 00729653 */
#ifdef INSTRUMENT
  div_count = 0, mul_count = 0, add_sub_count = 0;
#endif

  int i, j, k;
  // forward elimination
  for (k = 1; k <= N; k++) {
    // normalize first column of every row
    for (i = k; i <= N; i++) {
      double coeff = A[i][k];
      if (coeff != 0) {
        for (j = k; j <= N; j++) {
          A[i][j] /= coeff; // div_count
#ifdef INSTRUMENT
          div_count++;
#endif
        }
        y[i] /= coeff; // div_count
#ifdef INSTRUMENT
        div_count++;
#endif
      }
    }

    // reduce all rows by first row
    for (i = k + 1; i <= N; i++) {
      if (A[i][k] != 0) {
        for (j = k; j <= N; j++) {
          A[i][j] -= A[k][j]; // sub
#ifdef INSTRUMENT
          add_sub_count++;
#endif
        }
        y[i] -= y[k]; // sub
#ifdef INSTRUMENT
        add_sub_count++;
#endif
      }
    }
  }

  // backward substitution
  for (i = N; i > 0; i--) {
    for (j = 1; j < i; j++) {
      if (A[j][i] != 0) {
        y[j] -= A[j][i] * y[i]; // sub, mul_count
#ifdef INSTRUMENT
        add_sub_count++;
        mul_count++;
#endif
        A[j][i] = 0;
      }
    }
  }

  return copy(y, N);
}

void luDecompose(double **a, int m, int n) {
  /* Han, Qiao: 00729653 */
  int g, h, i, j, k;
  int r = (m + 1) / 2;

  for (k = 1; k <= n; k++) {
    if (fabs(a[k][r]) < DBL_EPSILON) {
      return;
    }
    a[k][r] = 1. / a[k][r];
#ifdef INSTRUMENT
    // 1 to N = N
    div_count++;
#endif
    h = r - 1;
    i = k + 1;
    L10:
    if (h < 1 || i > n) {
      continue;
    }
    if (a[i][h] == 0 || a[k][r] == 0) {
      a[i][h] = 0;
    } else {
      a[i][h] *= a[k][r];
#ifdef INSTRUMENT
      mul_count++;
#endif
    }
    j = h + 1;
    g = r + 1;
    L30:
    if (g > m || j > r + n - i) {
      goto L40;
    }
    if (a[i][h] != 0 && a[k][g] != 0) {
      a[i][j] -= a[i][h] * a[k][g];
#ifdef INSTRUMENT
      mul_count++;
      add_sub_count++;
#endif
    }
    j++;
    g++;
    goto L30;
    L40:
    i++;
    h--;
    goto L10;
  }
}

void solve(double **a, double *b, int m, int n) {
  /* Han, Qiao: 00729653 */
  int i, j, k;
  int r = (m + 1) / 2;

  // forward elimination
  for (k = 1; k < n; k++) {
    i = k + 1;
    j = r - 1;
    L110:
    if (j < 1 || i > n) {
      continue;
    }
    b[i] -= a[i][j] * b[k];
#ifdef INSTRUMENT
    mul_count++;
    add_sub_count++;
#endif
    i++;
    j--;
    goto L110;
  }

  // backward substitution
  for (k = n; k > 0; k--) {
    i = k + 1;
    j = r + 1;
    L130:
    if (j > m || i > n) {
      goto L140;
    }
    if (a[k][j] != 0 && b[i] != 0) {
      b[k] -= a[k][j] * b[i];
#ifdef INSTRUMENT
      mul_count++;
      add_sub_count++;
#endif
    }
    i++;
    j++;
    goto L130;
    L140:
    if (b[k] == 0 || a[k][r] == 0) {
      b[k] = 0;
    } else {
      b[k] *= a[k][r];
#ifdef INSTRUMENT
      mul_count++;
#endif
    }
  }
}

double *BGauss(double **C, double *y, int N, int B) {
  /* Han, Qiao: 00729653 */
#ifdef INSTRUMENT
  div_count = 0, mul_count = 0, add_sub_count = 0;
#endif

  int m = B * 2 + 1;
  luDecompose(C, m, N);
  solve(C, y, m, N);

  return copy(y, N);
}
