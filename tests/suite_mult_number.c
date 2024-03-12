#include "s21_matrix_tests.h"

// Someday, i`ll make a dream unchained

START_TEST(incorrect_matrix) {
  matrix_t M1 = {};
  double number = 3.14;
  s21_create_matrix(3, 3, &M1);
  s21_fill_matrix_with(&M1, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  ck_assert_int_eq(s21_mult_number(&M1, number, NULL), INCORRECT_MATRIX);
  s21_remove_matrix(&M1);
}
END_TEST

START_TEST(uninit_values) {
  matrix_t M1 = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &M1);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&M1, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&result);
    s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(init_values) {
  matrix_t M1 = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &M1);
  s21_fill_matrix_with(&M1, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_fill_matrix_with(&eq_matrix, 9, 3, 6, 9, 12, 15, 18, 21, 24, 27);
  ck_assert_int_eq(s21_mult_number(&M1, number, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&M1);
    s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

Suite *test_mult_number(void) {
  Suite *suite = suite_create("s21_mult_number");
  TCase *tc_core = tcase_create("core_of_mult_number");
  tcase_add_test(tc_core, incorrect_matrix);
  tcase_add_test(tc_core, uninit_values);
  tcase_add_test(tc_core, init_values);
  suite_add_tcase(suite, tc_core);

  return suite;
}
