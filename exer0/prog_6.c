#include <stdio.h>

int main() {
  double a1, a0;

  printf("Enter coefficients of Linear Equation a1*x+a0=0 \n");
  printf("in the order a1, a0, separated by spaces\n");
  scanf("%lf %lf", &a1, &a0);

  if (a1 == 0) {
    if (a0 == 0) {
      printf("Infinite solutions to linear equation a1*x+a0=0");
    } else {
      printf("No solution to linear equation a1*x+a0=0");
    }
    return 0;
  }

  double x = -a0 / a1;
  printf("x = %lf", x);

  return 0;
}
