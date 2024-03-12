#include "../s21_matrix.h"

// Воспоминание молчит,

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_validate_matrix(A) || s21_validate_matrix(B) || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int status_code = OK;
  status_code = s21_create_matrix(A->rows, B->columns, result);
  if (!status_code) {
    for (int i = 0; i < result->rows && status_code == OK; i++) {
      for (int j = 0; j < result->columns && status_code == OK; j++) {
        result->matrix[i][j] = s21_mult_matrix_res(i, j, A, B);
        if (!isfinite(result->matrix[i][j])) {
          status_code = CALCULATION_ERROR;
        }
      }
    }
  }

  return status_code;
}
