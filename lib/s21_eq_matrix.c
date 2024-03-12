#include "../s21_matrix.h"

// Ты так бессилен, а мир велик,

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_is_matrix_same_size(A, B) || s21_validate_matrix(A) ||
      s21_validate_matrix(B)) {
    return FAILURE;
  }

  int comparison_status = SUCCESS;
  if(A->rows != B->rows || A->columns != B->columns) {
  	comparison_status = FAILURE;
  } else {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((fabs(A->matrix[i][j] - B->matrix[i][j])) > 0) {
        comparison_status = FAILURE;
      }
    }
  }
  }
  return comparison_status;
}
