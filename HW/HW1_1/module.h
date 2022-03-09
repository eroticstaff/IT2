#ifndef HW1_1__MODULE_H_
#define HW1_1__MODULE_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **create_matrix(int n, int m);
void print_matrix(int **matrix, int n, int m);
void delete_row(int **matrix, int row_i, int n, int m);
int process_matrix(int **matrix, int n, int m);

#endif //HW1_1__MODULE_H_
