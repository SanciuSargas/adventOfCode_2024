#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
  FILE *file = fopen("input.txt", "r");
  char line[100];


  if (file == NULL) {
    printf("Error opening the file");
    return 0;
  }


  int count = 0;

  while (fgets(line, sizeof(line), file)) {
    int previousNr = -1;
    int isIncr = -1; // 0 - decreasing, 1 - increasing
    int safe = 1;

    char *ptr = line;
    char *endptr;

    while (*ptr) {
      int currentNumber = strtol(ptr, &endptr, 10);
      if (currentNumber == 0) {
        break;
      }
      printf("%d", currentNumber);

      if (ptr == endptr) {
        break;
      }


      int diff = currentNumber - previousNr;
      /* printf("%d \n", diff); */

      if (previousNr == -1) {
        previousNr = currentNumber;
      } else if (isIncr == -1 && abs(diff) <= 3 && abs(diff) >=1) {
        isIncr = (diff > 0);
      } else if ((isIncr == 0 && abs(diff) <= 3 && abs(diff) >=1 && diff > 0)
                 || (isIncr == 1 && abs(diff) <= 3 && abs(diff) >=1 && diff < 0)
                 || (abs(diff) > 3 || abs(diff) < 1)) {

        if (safe == 1) {
          safe = 0;
        } else {
          safe = -1;
          break;
        }
      }

      previousNr = currentNumber;
      ptr = endptr;
    }

    if (safe != -1) {
      count++;
      printf("safe\n");
    }
  }

  fclose(file);




  printf("%d", count);

  return 0;
}
