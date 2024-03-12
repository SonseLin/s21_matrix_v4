#include "s21_matrix_tests.h"

// Let the clouds heal me of the stains

START_TEST(diff_matrix) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  ck_assert_int_eq(s21_sum_matrix(&M1, &M2, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(fail_with_diff_size) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &M1);
  s21_create_matrix(5, 5, &M2);
  ck_assert_int_eq(s21_sum_matrix(&M1, &M2, &result), CALCULATION_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(normal_case) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  matrix_t result = {};
  s21_create_matrix(3, 3, &M1);
  s21_create_matrix(3, 3, &M2);
  s21_create_matrix(3, 3, &result);
  s21_fill_matrix_with(&M1, 9, 1,2,3,4,5,6,7,8,9);
  s21_fill_matrix_with(&M2, 9,9,8,7,6,5,4,3,2,1);
  ck_assert_int_eq(s21_sum_matrix(&M1, &M2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &result), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(uninit_values) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(5, 5, &M1);
  s21_create_matrix(5, 5, &M2);
  s21_create_matrix(5, 5, &eq_matrix);
  ck_assert_int_eq(s21_sum_matrix(&M1, &M2, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
    s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(curse_case) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &M1);
  s21_create_matrix(3, 3, &M2);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_fill_matrix_with(&M1, 9, 1, 2, 3, 4, 5, 1, 2, 3, 4);
  s21_fill_matrix_with(&M2, 9, 5, 4, 3, 2, 1, 5, 4, 3, 2);
  ck_assert_int_eq(s21_sum_matrix(&M1, &M2, &result), OK);
  s21_fill_matrix_with(&eq_matrix, 9, 6, 6, 6, 6, 6, 6, 6, 6, 6);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *test_sum_matrix(void) {
  Suite *suite = suite_create("s21_sum_matrix");
  TCase *tc_core = tcase_create("core_of_sum_matrix");
  tcase_add_test(tc_core, diff_matrix);
  tcase_add_test(tc_core, fail_with_diff_size);
  tcase_add_test(tc_core, normal_case);
  tcase_add_test(tc_core, uninit_values);
  tcase_add_test(tc_core, curse_case);
  suite_add_tcase(suite, tc_core);

  return suite;
}
