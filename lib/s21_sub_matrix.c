#include "../s21_matrix.h"

// Мне бы все тайны пробудить

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (s21_validate_matrix(A) || s21_validate_matrix(B) || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    return CALCULATION_ERROR;
  }

  int status_code = OK;
  status_code = s21_create_matrix(A->rows, A->columns, result);
  if (!status_code) {
    for (int i = 0; i < A->rows && status_code == OK; i++) {
      for (int j = 0; j < A->columns && status_code == OK; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return status_code;
}
