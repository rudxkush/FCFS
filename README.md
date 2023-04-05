# FCFS
#include <stdio.h>
#include <stdlib.h>

int *arrGen(int sizeOfArr) // generates nameless 1-D Array
{
  int *newArr = (int *)malloc(sizeof(int) * sizeOfArr);
  return newArr;
}

int main(void) {
  int processes = 3;
  int *arr[processes];

  arr[0] = arrGen(4);
  arr[1] = arrGen(4);
  arr[2] = arrGen(4);

  for (int i = 0; i < 3; i++) {
    printf("Burst time for process P%d:", i);
    scanf("%d", &arr[i][0]);
  }

  printf("\n");

  for (int i = 0; i < 3; i++) {
    printf("Arrival Time for process p%d:", i);
    scanf("%d", &arr[i][1]);
  }

  printf("\n");

  for (int i = 0; i < 3; i++) {
    printf("Turn Around Time for process p%d:", i); // C.T = A.T + B.T
    // COMPUTE
    arr[i][2] = arr[i][0] + arr[i][1];
    printf("%d\n", arr[i][2]);
  }
  for (int i = 0; i < 3; i++) {
    printf("Completion Time for process p%d:", i); // T.A.T = C.T - A.T
    // COMPUTE
    arr[i][3] = arr[i][2] - arr[i][1];
    printf("%d\n", arr[i][3]);
  }

  printf("\n BT  AT  TT  CT\n");

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      if (arr[i][j] < 10) {
        printf(" 0%d ", arr[i][j]);
      } else {
        printf(" %d ", arr[i][j]);
      }
    }
    printf("\n");
  }
  return 0;
}

