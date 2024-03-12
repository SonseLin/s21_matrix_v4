#include "s21_matrix_tests.h"

// Birds are born with no... shackles

START_TEST(incorrect_matrix) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(fail_with_vector) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 3, &A);
  s21_fill_matrix_with(&A, 3, 1, 2, 3);
  ck_assert_int_eq(s21_calc_complements(&A, &result), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(normal_case) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_fill_matrix_with(&A, 9, 1, 2, 3, 0, 4, 2, 5, 2, 1);
  ck_assert_int_eq(s21_calc_complements(&A, &result), OK);
  s21_fill_matrix_with(&eq_matrix, 9, 0, 10, -20, 4, -14, 8, -8, -2, 4);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *test_calc_complements(void) {
  Suite *suite = suite_create("s21_calc_complements");
  TCase *tc_core = tcase_create("core_of_calc_complements");
  tcase_add_test(tc_core, incorrect_matrix);
  tcase_add_test(tc_core, fail_with_vector);
  tcase_add_test(tc_core, normal_case);
  suite_add_tcase(suite, tc_core);

  return suite;
}
