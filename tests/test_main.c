#include "s21_matrix_tests.h"

// I dream

void run_tests(void) {
  int count_testcases = 0;
  Suite *list_cases[] = {
      test_create_matrix(),    test_remove_matrix(),  test_eq_matrix(),
      test_sum_matrix(),       test_sub_matrix(),     test_determinant(),
      test_calc_complements(), test_inverse_matrix(), NULL};
  for (Suite **current_test_case = list_cases; *current_test_case != NULL;
       current_test_case++) {
    run_testcase(*current_test_case, count_testcases);
    count_testcases++;
  }
}

void run_testcase(Suite *testcase, int counter_testcase) {
  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}
