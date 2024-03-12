#include "s21_matrix_tests.h"

// Then what fetters my fate?

START_TEST(create_normal) {
  matrix_t M = {};
  ck_assert_int_eq(s21_create_matrix(10, 10, &M), OK);
  s21_remove_matrix(&M);
}
END_TEST

START_TEST(create_nil_row) {
  matrix_t M = {};
  ck_assert_int_eq(s21_create_matrix(0, 10, &M), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_nil_column) {
  matrix_t M = {};
  ck_assert_int_eq(s21_create_matrix(10, 0, &M), INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_null_ptr) {
  ck_assert_int_eq(s21_create_matrix(10, 10, NULL), INCORRECT_MATRIX);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *suite = suite_create("s21_create_matrix");
  TCase *tc_core = tcase_create("core_of_create_matrix");
  tcase_add_test(tc_core, create_normal);
  tcase_add_test(tc_core, create_nil_row);
  tcase_add_test(tc_core, create_nil_column);
  tcase_add_test(tc_core, create_null_ptr);
  suite_add_tcase(suite, tc_core);

  return suite;
}
