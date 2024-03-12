#include "s21_helper_functions.h"

// И каждый шаг тяжел до слез, но

void s21_fill_matrix_with(matrix_t *matrix, int number_of_arguments, ...) {
  va_list valist;
  va_start(valist, number_of_arguments);
  for (int r = 0; r < matrix->rows; r++) {
    for (int c = 0; c < matrix->columns; c++) {
      matrix->matrix[r][c] = (double)va_arg(valist, int);
    }
  }
  va_end(valist);
}

void s21_print_matrix(matrix_t *matrix) {
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      printf(j + 1 < matrix->columns ? "%lf " : "%lf", matrix->matrix[i][j]);
    }
    printf("\n");
  }
}

double **alloc_2d(int row, int column) {
  double **arr = malloc(row * column * sizeof(double) + row * sizeof(double *));
  double *ptr = (double *)(arr + row);
  for (int i = 0; i < row; i++) {
    arr[i] = ptr + i * column;
  }
  return arr;
}

int s21_validate_matrix(matrix_t *matr) {
  int status_code = OK;
  if (matr == NULL || matr->matrix == NULL || matr->rows < 1 ||
      matr->columns < 1) {
    status_code = INCORRECT_MATRIX;
  }
  return status_code;
}

int s21_is_matrix_same_size(matrix_t *M1, matrix_t *M2) {
  int status_code = CALCULATION_ERROR;
  if (M1 == NULL || M2 == NULL) {
    status_code = INCORRECT_MATRIX;
  } else if (M1->rows == M2->rows && M1->columns == M2->columns) {
    status_code = SUCCESS;
  }
  return status_code;
}

double s21_mult_matrix_res(int i, int j, matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL) {
    return 0;
  }

  double res = 0;

  for (int k = 0; k < B->rows; k++) {
    res += A->matrix[i][k] * B->matrix[k][j];
  }

  return res;
}

matrix_t *s21_create_minor(int excluded_row, int excluded_column, matrix_t *A) {
  if (A == NULL || A->matrix == NULL) {
    return NULL;
  }

  matrix_t *minor = calloc(1, sizeof(matrix_t));
  if (minor != NULL) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor) == OK) {
      for (int i = 0, minor_row = 0; i < A->rows; i++) {
        if (i != excluded_row) {
          for (int j = 0, minor_column = 0; j < A->columns; j++) {
            if (j != excluded_column) {
              minor->matrix[minor_row][minor_column] = A->matrix[i][j];
              minor_column++;
            }
          }
          minor_row++;
        }
      }
    }
  }

  return minor;
}

int s21_is_matrix_square(matrix_t *A) {
  return A != NULL ? A->rows == A->columns ? 1 : 0 : 0;
}
