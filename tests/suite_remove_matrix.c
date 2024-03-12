#include "s21_matrix_tests.h"

// Let my heart bravely spread the wings

START_TEST(remove_matrix) {
  matrix_t M = {};
  s21_create_matrix(10, 10, &M);
  s21_remove_matrix(&M);
  ck_assert_ptr_null(M.matrix);
}
END_TEST

START_TEST(handle_null) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(handle_incorrect) {
  matrix_t M = {};
  s21_remove_matrix(&M);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(with_init_values) {
  matrix_t M = {};
  s21_create_matrix(3, 3, &M);
  s21_fill_matrix_with(&M, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  s21_remove_matrix(&M);
  ck_assert_int_eq(1, 1);
}
END_TEST

Suite *test_remove_matrix(void) {
  Suite *suite = suite_create("s21_remove_matrix");
  TCase *tc_core = tcase_create("core_of_remove_matrix");
  tcase_add_test(tc_core, remove_matrix);
  tcase_add_test(tc_core, handle_null);
  tcase_add_test(tc_core, handle_incorrect);
  tcase_add_test(tc_core, with_init_values);
  suite_add_tcase(suite, tc_core);

  return suite;
}