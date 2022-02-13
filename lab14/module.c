#include "module.h"

void print_matrix(int **A, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%4d", *(*(A + i) + j));
    }
    printf("\n");
  }
}

void calculate_row(int **A, int m, int i) {
  int sum = 0;
  int count = 0;
  for (int j = 0; j < m; j++) {
    if (*(*(A + i) + j) < 0) {
      sum += *(*(A + i) + j);
      count++;
    }
  }
  if (count == 0)
    printf("There is no negative numbers in %d row\n", i);
  else {
    sum /= count;
    printf("Mean for %d row is %d\n", i, sum);
  }
  printf("Last element of %d row adress is %p\n", i, *(A + i) + m - 1);
  *(*(A + i) + m - 1) = sum;
}
