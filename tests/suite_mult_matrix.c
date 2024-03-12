#include "s21_matrix_tests.h"

// Can wear down my illusion

START_TEST(incorrect_matr) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  s21_fill_matrix_with(&A, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(diff_size) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(uninit_values) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
    s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(normal_case) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_fill_matrix_with(&A, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  s21_create_matrix(3, 3, &B);
  s21_fill_matrix_with(&B, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_fill_matrix_with(&eq_matrix, 9, 30, 36, 42, 66, 81, 96, 102, 126, 150);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
    s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *test_mult_matrix(void) {
  Suite *suite = suite_create("s21_mult_matrix");
  TCase *tc_core = tcase_create("core_of_mult_matrix");
  tcase_add_test(tc_core, incorrect_matr);
  tcase_add_test(tc_core, diff_size);
  tcase_add_test(tc_core, uninit_values);
  tcase_add_test(tc_core, normal_case);
  suite_add_tcase(suite, tc_core);

  return suite;
}
