#include <stdio.h>

int main(void) {
  short i1 = 44;
  short i2 = 55;
  short i3;

  i3 = i1 + i2;
  printf("\n");
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  i3 = i1 * i2;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  i3 = i1 / i2;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  i3 = i2 / i1;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  i1 = 44444, i2 = 55555;
  i3 = i1 + i2;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  printf("99999 - 2^16 = %d \n", 99999 - 65536);
  printf("\n");

  i3 = i1 * i2;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  i3 = i1 / i2;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  i3 = i2 / i1;
  printf("i1, i2, i3 = %d %d %d \n", i1, i2, i3);
  printf("\n");

  return 0;
}
