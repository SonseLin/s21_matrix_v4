#ifndef S21_HELPER_FUNCTIONS
#define S21_HELPER_FUNCTIONS

// Starfall HSI

#include "../s21_matrix.h"

void s21_fill_matrix_with(matrix_t* matrix, int number_of_arguments, ...);
void s21_print_matrix(matrix_t* matrix);
double** alloc_2d(int row, int column);
int s21_validate_matrix(matrix_t* matr);
int s21_is_matrix_same_size(matrix_t* M1, matrix_t* M2);
double s21_mult_matrix_res(int i, int j, matrix_t* A, matrix_t* B);
matrix_t* s21_create_minor(int excluded_row, int excluded_column, matrix_t* A);
int s21_is_matrix_square(matrix_t* A);
#endif  // S21_HELPER_FUNCTIONS
