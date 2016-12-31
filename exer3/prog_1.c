#include <stdio.h>
#include <stdlib.h>

double *SFactors(int N);

int main(int argc, char *argv[]) {
  int max = 4;

  if (argc > 1) {
    max = atoi(argv[1]);
  }

  double *factors;
  int p = 3;
  for (int i = 0; i < max; i++) {
    int N = p << i;
    if (N == 1) {
      continue;
    }
    factors = SFactors(N);
    printf("p = %d, N = %d\n", p, N);
    for (int j = 0; j < (N + 1) / 2; j++) {
      printf("S[%d] = %.15lf\n", j, factors[j]);
    }
    printf("\n");
    free(factors);
  }
}
