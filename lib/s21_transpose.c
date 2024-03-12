#include "../s21_matrix.h"

// И сердце вновь укажет путь вперед.

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) {
    return INCORRECT_MATRIX;
  }

  int status_code = OK;
  status_code = s21_create_matrix(A->columns, A->rows, result);
  if (!status_code) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }

  return status_code;
}