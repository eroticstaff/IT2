#include "module.h"

int main() {
  int n, m;
  puts("Enter size of matrix(n and m):");
  scanf("%d %d", &n, &m);
  int **matrix = create_matrix(n, m);
  print_matrix(matrix, n, m);
  puts("-------------");
  n = process_matrix(matrix, n ,m);
  print_matrix(matrix, n, m);
  return 0;
}
