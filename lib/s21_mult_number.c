#include "../s21_matrix.h"

// Но не забыто в самом деле:

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (!isfinite(number)) {
    return CALCULATION_ERROR;
  }

  int status_code = OK;
  status_code = s21_create_matrix(A->rows, A->columns, result);
  if (!status_code) {
    for (int i = 0; i < A->rows && status_code == OK; i++) {
      for (int j = 0; j < A->columns && status_code == OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
        if (!isfinite(result->matrix[i][j])) {
          status_code = CALCULATION_ERROR;
        }
      }
    }
  }

  return status_code;
}