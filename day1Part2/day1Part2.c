#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
  FILE *file = fopen("input.txt", "r");
  char str[6];

  if (file == NULL) {
    printf("Error opening the file");
    return 0;
  }

  int nr1;
  int nr2;
  int nrList1[9000];
  int nrList2[9000];

  int numberAmount = 0;

  while (fscanf(file, "%d %d", &nr1, &nr2) == 2) {
    nrList1[numberAmount] = nr1;
    nrList2[numberAmount] = nr2;

    numberAmount++;
  }

  fclose(file);

  qsort(nrList1, numberAmount, sizeof(int), comp);
  qsort(nrList2, numberAmount, sizeof(int), comp);

  int sum = 0;

  for (int i = 0; i < numberAmount; i++) {
    int count = 0;
    int foundSame = 0;

    for (int j = 0; j < numberAmount; j++) {
      if (nrList1[i] == nrList2[j]) {
        count++;
        foundSame = 1;
      } else if (foundSame == 1) {
        break;
      }
    }

    sum += nrList1[i] * count;
  }

  printf("%d", sum);

  return 0;
}
