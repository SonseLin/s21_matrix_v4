#include "s21_matrix_tests.h"

// Soaring past the night, to trace the primal light

START_TEST(uninit_matrixes) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  ck_assert_int_eq(s21_sub_matrix(&M1, &M2, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(diff_size) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &M1);
  s21_create_matrix(5, 5, &M2);
  ck_assert_int_eq(s21_sub_matrix(&M1, &M2, &result), CALCULATION_ERROR);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
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
  ck_assert_int_eq(s21_sub_matrix(&M1, &M2, &result), OK);
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
  ck_assert_int_eq(s21_sub_matrix(&M1, &M2, &result), OK);
  s21_fill_matrix_with(&eq_matrix, 9, -4, -2, 0, 2, 4, -4, -2, 0, 2);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
    s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *test_sub_matrix(void) {
  Suite *suite = suite_create("s21_sub_matrix");
  TCase *tc_core = tcase_create("core_of_sub_matrix");
  tcase_add_test(tc_core, uninit_matrixes);
  tcase_add_test(tc_core, diff_size);
  tcase_add_test(tc_core, uninit_values);
  tcase_add_test(tc_core, curse_case);
  suite_add_tcase(suite, tc_core);

  return suite;
}
