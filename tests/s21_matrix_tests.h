#ifndef S21_MATRIX_TESTS_H
#define S21_MATRIX_TESTS_H

// If i can stop one heart from breaking

#include <check.h>

#include "../s21_matrix.h"

Suite *test_create_matrix(void);
Suite *test_eq_matrix(void);
Suite *test_remove_matrix(void);

Suite *test_sum_matrix(void);
Suite *test_sub_matrix(void);

Suite *test_transpose(void);
Suite *test_determinant(void);

Suite *test_calc_complements(void);
Suite *test_inverse_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase, int counter_testscase);

#endif
