#include <stdio.h>
#include <stdlib.h>

int *arrGen(int sizeOfArr) // generates nameless 1-D Array
{
  int *newArr = (int *)malloc(sizeof(int) * sizeOfArr);
  return newArr;
}

// Function to sort processes by arrival time
void sortByArrivalTime(int *arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j][1] > arr[j + 1][1]) {
        // Swap the pointers to the arrays
        int *temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
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
    printf("Arrival Time for process P%d:", i);
    scanf("%d", &arr[i][1]);
  }
  
  // Sort processes by arrival time
  sortByArrivalTime(arr, processes);
  
  printf("\n");
  
  // Calculate Completion Time first
  int currentTime = 0;
  for (int i = 0; i < 3; i++) {
    // If process hasn't arrived yet, update current time
    if (currentTime < arr[i][1]) {
      currentTime = arr[i][1];
    }
    
    // Process executes for its burst time
    currentTime += arr[i][0];
    
    // Completion time is when the process finishes
    arr[i][3] = currentTime;
    
    printf("Completion Time for process P%d:", i);
    printf("%d\n", arr[i][3]);
  }
  
  // Now calculate Turnaround Time
  for (int i = 0; i < 3; i++) {
    // Turnaround Time = Completion Time - Arrival Time
    arr[i][2] = arr[i][3] - arr[i][1];
    
    printf("Turn Around Time for process P%d:", i);
    printf("%d\n", arr[i][2]);
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
  
  // Free allocated memory
  for (int i = 0; i < processes; i++) {
    free(arr[i]);
  }
  
  return 0;
}
