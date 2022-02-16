#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *nums, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", *(nums + i));
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  int n;
  int *nums;
  puts("Enter n:");
  scanf("%d", &n);
  nums = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    *(nums + i) = rand() % 50 - 15;
  }
  puts("Array:");
  print_array(nums, n);
  double sum = 0;
  double count = 0;
  for (int i = 0; i < n; i++) {
    if (*(nums + i) % 2 == 0) {
      printf("%d element with adress %p is %d and it is ::2\n", i, nums + i,
             *(nums + i));
      sum += *(nums + i);
      count++;
    }
  }
  if (count == 0) {
    printf("There is no numbers ::2!\n");
  } else {
    sum /= count;
    printf("Mean is %lf\n", sum);
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (*(nums + i) < 0 && !flag) {
        printf("First negative number is %d with adress %p\n", *(nums + i),
               nums + i);
        flag = 1;
        *(nums + i) = sum;
      }
    }
    if (!flag) {
      printf("There is no negative numbers!\n");
    } else {
      printf("New array:\n");
      print_array(nums, n);
    }
  }
  return 0;
}
