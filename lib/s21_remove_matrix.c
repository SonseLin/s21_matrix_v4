#include "../s21_matrix.h"

// Кого-то нет, но голос все зовет...

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
  free(A->matrix);
  A->matrix = NULL;
  }
}
