#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int streams = (rand() % 6) + 10;
  printf("%d\n", streams);
  int i;
  for (i = 0; i < streams; i++) {
    int start = rand() % 24;  //Start at any hour
    int length = rand() % (24 - start) + 1; //Last at least one hour
    int rating = (rand() % 5) + 1;  //Rating 1-5
    printf("%d %d %d\n", start, length, rating);
  }
}
