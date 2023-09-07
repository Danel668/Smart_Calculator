#include "test_calc.h"

START_TEST(simple_test1) {
  const char str[] = "5+3";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 8);
}

START_TEST(simple_test2) {
  const char str[] = "5+3*2";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 11);
}

START_TEST(simple_test3) {
  const char str[] = "(5+3*2)/11";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 1);
}

START_TEST(simple_test4) {
  const char str[] = "(5+3*2)/11-3";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, -2);
}

START_TEST(simple_test5) {
  const char str[] = "3.1+4.22";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 7.32);
}

START_TEST(simple_test6) {
  const char str[] = "11mod3";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 2);
}

START_TEST(simple_test7) {
  const char str[] = "sqrt(121)";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 11);
}

START_TEST(simple_test8) {
  const char str[] = "2^(2^(2))";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, 16);
}

START_TEST(simple_test9) {
  const char str[] = "sin(9)";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  int test_res = fabs(ans - sin(9)) < 1e-6 ? 1 : 0;

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(test_res, 1);
}

START_TEST(simple_test10) {
  const char str[] =
      "sin(9)+cos(5)+tan(11)+ln(2)+log(99)+asin(0.9)+acos(0.3)*atan(12)";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  int test_res = fabs(ans - (sin(9) + cos(5) + tan(11) + log(2) + log10(99) +
                             asin(0.9) + acos(0.3) * atan(12))) < 1e-6
                     ? 1
                     : 0;

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(test_res, 1);
}

START_TEST(simple_test11) {
  const char str[] = "x*3-12";
  double ans = 0;

  int res = api_calculate(str, 2, &ans);

  ck_assert_int_eq(1, res);
  ck_assert_double_eq(ans, -6);
}

START_TEST(wrong_test1) {
  const char* str = NULL;
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(0, res);
  ck_assert_double_eq(ans, 0);
}

START_TEST(wrong_test2) {
  const char str[] = "log(0)";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(0, res);
  // ck_assert_double_eq(ans, 0);
}

START_TEST(wrong_test3) {
  const char str[] = "ln(-1)";
  double ans = 0;

  int res = api_calculate(str, 0, &ans);

  ck_assert_int_eq(0, res);
  // ck_assert_double_eq(ans, nan);
}

START_TEST(stack_test1) {
  Stack stack;
  initializeStack(&stack);

  StackNode tmp = pop(&stack);

  ck_assert_double_eq(0, tmp.value);
  ck_assert_int_eq(0, tmp.priority);
  ck_assert_int_eq(0, tmp.type);
}

START_TEST(input_validation_test1) {
  char* str = "0.";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test2) {
  char* str = "3+.";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test3) {
  char* str = "((";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test4) {
  char* str = "(3+5))";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test5) {
  char* str = ")";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test6) {
  char* str = "(3+5)x";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test7) {
  char* str = "3++5";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test8) {
  char* str = NULL;

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

START_TEST(input_validation_test9) {
  char* str = "(3+5)9";

  int res = isValid(str);

  ck_assert_int_eq(0, res);
}

Suite* suite_controller() {
  Suite* s = suite_create("CONTROLLER");
  TCase* test_case = tcase_create("CONTROLLER");

  if (s != NULL && test_case != NULL) {
    tcase_add_test(test_case, simple_test1);
    tcase_add_test(test_case, simple_test2);
    tcase_add_test(test_case, simple_test3);
    tcase_add_test(test_case, simple_test4);
    tcase_add_test(test_case, simple_test5);
    tcase_add_test(test_case, simple_test6);
    tcase_add_test(test_case, simple_test7);
    tcase_add_test(test_case, simple_test8);
    tcase_add_test(test_case, simple_test9);
    tcase_add_test(test_case, simple_test10);
    tcase_add_test(test_case, simple_test11);
    tcase_add_test(test_case, wrong_test1);
    tcase_add_test(test_case, wrong_test2);
    tcase_add_test(test_case, wrong_test3);
    tcase_add_test(test_case, stack_test1);
    tcase_add_test(test_case, input_validation_test1);
    tcase_add_test(test_case, input_validation_test2);
    tcase_add_test(test_case, input_validation_test3);
    tcase_add_test(test_case, input_validation_test4);
    tcase_add_test(test_case, input_validation_test5);
    tcase_add_test(test_case, input_validation_test6);
    tcase_add_test(test_case, input_validation_test7);
    tcase_add_test(test_case, input_validation_test8);
    tcase_add_test(test_case, input_validation_test9);

    suite_add_tcase(s, test_case);
  }
  return s;
}