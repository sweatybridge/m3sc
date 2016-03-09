#include <stdio.h>

int main(void) {
  int high = 160;
  int step = 2;
  int C = -40;
  float F;

  printf("%6s %10s %6s %10s \n", "C", "K", "F", "R");
  while (C <= high) {
    F = 32 + 9 * C / 5.0f;
    printf("%6d %10.2f %6.1f %10.2f \n", C, C + 273.15, F, F + 459.67);
    C += step;
  }

  return 0;
}
