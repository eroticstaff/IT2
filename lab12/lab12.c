#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int **A, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%4d ", *(*(A + i) + j));
    }
    printf("\n");
  }
}

int main() {
  int n, m;
  int **A;
  puts("Enter n and m:");
  scanf("%d %d", &n, &m);
  A = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    *(A + i) = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; j++) {
      *(*(A + i) + j) = rand() % 50;
    }
  }
  printf("Matrix:\n");
  print_matrix(A, n, m);
  for (int j = 0; j < m; j++) {
    int sum = 0;
    int *last;
    for (int i = 0; i < n; i++) {
      sum += *(*(A + i) + j);
      last = *(A + i) + j;
    }
    sum /= n;
    printf("Mean of %d column is %d\n", j, sum);
    printf("Last element of %d column is %d with adress %p\n", j, *last, last);
    *last = sum;
  }
  puts("New matrix:");
  print_matrix(A, n, m);
  return 0;
}
