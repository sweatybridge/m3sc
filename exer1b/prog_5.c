#include <stdio.h>

int main() {
  printf("\n What is this? : \234 ");
//  printf("\n What is this? : \u20AC ");
  printf("\n What is this? : %s ", __TIME__);
  printf("\n What is this? : %s ", __DATE__);
  printf("\n \n");
  return(0);
}
