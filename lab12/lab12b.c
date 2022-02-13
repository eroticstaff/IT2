#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int **A;
  int M;
  int n, m;
  puts("Enter size of matrix(n and m):");
  scanf("%d %d", &n, &m);
  puts("Enter M:");
  scanf("%d", &M);
  A = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    *(A + i) = (int *)malloc(sizeof(int) * m);
    for (int j = 0; j < m; j++) {
      *(*(A + i) + j) = rand() % 50;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < M; k++) {
      printf("    ");
    }
    for (int j = 0; j < m; j++) {
      printf("%4d", *(*(A + i) + j));
    }
    printf("\n");
    M--;
  }
  return 0;
}
