#include <stdio.h>

int main() {

  char *seps = "\n\t\v\b\r\f\a\\\?\'\"";

  while (*seps != '\0') {
    printf("\nHello%cWorld!\n\n", *seps);
    seps++;
  }

  printf("%20s: Han, Qiao\n", "Name");
  printf("%20s: 00729653\n", "CID");
  printf("%20s: 0246473100\n", "LIBRARY NO");
  printf("%20s: qh812@imperial.ac.uk\n", "Email Address");
  printf("%20s: DOC\n", "Course Code");
  printf("%20s: %s\n", "Time", __TIME__);
  printf("%20s: %s\n", "Date", __DATE__);

  return 0;
}
