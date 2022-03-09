#include "module.h"

int **create_matrix(int n, int m) {
  srand(time(NULL));
  int **matrix = (int **) malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    *(matrix + i) = (int *) malloc(sizeof(int) * m);
    for (int j = 0; j < m; j++) {
      *(*(matrix + i) + j) = rand() % 50 * 2;
    }
  }
  return matrix;
}

void print_matrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%4d", *(*(matrix + i) + j));
    }
    puts("");
  }
}

void delete_row(int **matrix, int row_i, int n, int m) {
  for (int i = row_i; i < n-1; i++) {
    for (int j = 0; j < m; j++) {
      *(*(matrix + i) + j) = *(*(matrix + i + 1) + j);
    }
  }
  free(*(matrix + n - 1));
}

int process_matrix(int **matrix, int n, int m){
  int c = 0;
  for(int i = 0; i < n-c; i++){
    int count = 0;
    for(int j = 0; j < m; j++){
      if(*(*(matrix+i)+j) % 4 == 0)
        count++;
    }
    if(count >= 3){
      printf("Line %d is deleted!\n", i+c+1);
      delete_row(matrix, i, n-c, m);
      i--;
      c++;
    }
  }
  return n - c;
}
