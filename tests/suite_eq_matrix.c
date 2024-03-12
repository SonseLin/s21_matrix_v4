#include "s21_matrix_tests.h"

// Leave me trapped in the cage

START_TEST(eq_with_same_values) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  s21_create_matrix(3, 3, &M1);
  s21_create_matrix(3, 3, &M2);
  s21_fill_matrix_with(&M1, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  s21_fill_matrix_with(&M2, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), 1);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(eq_with_diff_sizes) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  s21_create_matrix(3, 3, &M1);
  s21_create_matrix(3, 2, &M2);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), FAILURE);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

START_TEST(eq_with_incorrect_matrix) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  s21_create_matrix(3, 3, &M1);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), FAILURE);
  s21_remove_matrix(&M1);
}
END_TEST

START_TEST(eq_with_diff_values) {
  matrix_t M1 = {};
  matrix_t M2 = {};
  s21_create_matrix(3, 3, &M1);
  s21_create_matrix(3, 3, &M2);
  s21_fill_matrix_with(&M1, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  s21_fill_matrix_with(&M2, 9, 1, 2, 3, 4, 5, 6, 7, 7, 9);
  ck_assert_int_eq(s21_eq_matrix(&M1, &M2), FAILURE);
  s21_remove_matrix(&M1);
  s21_remove_matrix(&M2);
}
END_TEST

Suite *test_eq_matrix(void) {
  Suite *suite = suite_create("s21_eq_matrix");
  TCase *tc_core = tcase_create("core_of_eq_matrix");
  tcase_add_test(tc_core, eq_with_same_values);
  tcase_add_test(tc_core, eq_with_diff_sizes);
  tcase_add_test(tc_core, eq_with_incorrect_matrix);
  tcase_add_test(tc_core, eq_with_diff_values);
  suite_add_tcase(suite, tc_core);

  return suite;
}