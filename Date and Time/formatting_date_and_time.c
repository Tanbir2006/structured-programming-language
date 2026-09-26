#include <stdio.h>
#include <time.h>

int main() {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  char buffer[100];

  strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", t);
  printf("Formatted time: %s\n", buffer);
  return 0;
}

