#include "s21_matrix_tests.h"

// Blown away, the white petals

START_TEST(incorrect_matr) {
  matrix_t A = {};
  double det = 0;
  ck_assert_int_eq(s21_determinant(&A, &det), INCORRECT_MATRIX);
}
END_TEST

START_TEST(fail_with_no_square) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 2, &A);
  s21_fill_matrix_with(&A, 6, 1, 2, 3, 4, 5, 6);
  ck_assert_int_eq(s21_determinant(&A, &det), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(defaultc) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(3, 3, &A);
  s21_fill_matrix_with(&A, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(classic_toe_case) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(2, 2, &A);
  s21_fill_matrix_with(&A, 4, 4, 8, 12, 16);
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, -32);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(single_point_matrix) {
  matrix_t A = {};
  double det = 0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &det), OK);
  ck_assert_double_eq(det, 21);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant(void) {
  Suite *suite = suite_create("s21_determinant");
  TCase *tc_core = tcase_create("core_of_determinant");
  tcase_add_test(tc_core, incorrect_matr);
  tcase_add_test(tc_core, fail_with_no_square);
  tcase_add_test(tc_core, defaultc);
  tcase_add_test(tc_core, classic_toe_case);
  tcase_add_test(tc_core, single_point_matrix);
  suite_add_tcase(suite, tc_core);

  return suite;
}
