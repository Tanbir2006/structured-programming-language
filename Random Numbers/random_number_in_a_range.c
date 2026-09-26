#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int x = rand() % 20;
  printf("%d\n", x);
  return 0;
}
