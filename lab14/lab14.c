#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "module.h"

int main() {
  int **A;
  int n, m;

  srand(time(NULL));
  puts("Enter size of matrix(n and m):");
  scanf("%d %d", &n, &m);
  A = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    *(A + i) = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; j++) {
      *(*(A + i) + j) = rand() % 50 - 25;
    }
  }
  puts("Source matrix:");
  print_matrix(A, n, m);
  for (int i = 0; i < n; i++) {
    calculate_row(A, m, i);
  }
  puts("New matrix:");
  print_matrix(A, n, m);
}
