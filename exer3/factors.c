#include <math.h>
#include <stdlib.h>

int powerof2(int x) {
  return x && !(x & (x - 1));
}

// N is powers of 2
double *SFactors(int N) {
  if (N < 2) {
    return NULL;
  }

  int p = 1;
  if (N % 3 == 0 && powerof2(N / 3)) {
    p = 3;
  } else if (N % 5 == 0 && powerof2(N / 5)) {
    p = 5;
  } else if (!powerof2(N)) {
    // unsupported N
    return NULL;
  }

  // handle memory allocation for N = 3 and 5
  int space = (N + 1) / 2;
  double *result = malloc(space * sizeof(double));
  result[0] = 1.;
  int idx = 1;

  for (int bot = p; bot <= N; bot *= 2) {
    for (int top = 1; top * 2 < bot; top += 2) {
      result[idx] = sin(top * M_PI / bot);
      idx++;
    }
    // handle special case p == 5
    if (bot == 5) {
      result[idx] = sin(2 * M_PI / bot);
      idx++;
    }
  }
  return result;
}
