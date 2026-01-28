// #include "s21_string_test.h"

// START_TEST(strcpy_test) {
//   char s1[50] = "Sample Text";
//   char d1[50] = "";
//   s21_strcpy(d1, s1);
//   ck_assert_msg(!strcmp(d1, s1), "1st  strcpy test failed");

//   char s2[50] = "AAAAA";
//   char d2[50] = "NO";
//   s21_strcpy(d2, s2);
//   ck_assert_msg(!strcmp(d2, s2), "2nd strcpy test failed");

//   char s3[50] = "";
//   char d3[50] = "HELLO";
//   s21_strcpy(d3, s3);
//   ck_assert_msg(!strcmp(d3, s3), "3rd strcpy test failed");

//   char s4[50] = "amogus";
//   char d4[50] = "HELLO";
//   s21_strcpy(d4, s4);
//   ck_assert_msg(!strcmp(d4, s4), "4rth strcpy test failed");

//   char s5[50] = "Shrek";
//   char d5[50] = "what";
//   s21_strcpy(d5, s5);
//   ck_assert_msg(!strcmp(d5, s5), "5th strcpy test failed");
// }
// Suite *s21_string_strcpy_test() {
//   Suite *s;
//   TCase *tc_core;

//   s = suite_create("strcpy_test");
//   tc_core = tcase_create("CORE");

//   tcase_add_test(tc_core, strcpy_test);

//   suite_add_tcase(s, tc_core);

//   return s;
// }

#include "s21_string_test.h"

START_TEST(test_s21_strcpy_1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  ck_assert_pstr_eq(strcpy(s1, s3), s21_strcpy(s2, s3));
}
END_TEST

START_TEST(test_s21_strcpy_2) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";

  ck_assert_pstr_eq(strcpy(s1, s3), s21_strcpy(s2, s3));
}
END_TEST

START_TEST(test_s21_strcpy_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";

  ck_assert_pstr_eq(strcpy(s1, s3), s21_strcpy(s2, s3));
}
END_TEST

START_TEST(test_s21_strcpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";

  ck_assert_pstr_eq(strcpy(s1, s3), s21_strcpy(s2, s3));
}
END_TEST

START_TEST(test_s21_strcpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  strlen(s3);
  ck_assert_pstr_eq(strcpy(s1, s3), s21_strcpy(s2, s3));
}
END_TEST

START_TEST(test_s21_strcpy_6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";

  ck_assert_pstr_eq(strcpy(s1, s3), s21_strcpy(s2, s3));
}
END_TEST

START_TEST(test_s21_strcpy_7) {
  char *s1 = "123";
  char t1[555555] = "";
  char *s2 = "123";
  char t2[555555] = "";

  555555;
  char *res1 = s21_strcpy(t1, s1);
  char *res2 = strcpy(t2, s2);
  ck_assert_str_eq(t1, t2);
  ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *s21_string_strcpy_test() {
  Suite *s;
  TCase *tc_s21_strcpy;
  s = suite_create("strcpy_test");
  tc_s21_strcpy = tcase_create("s21_strcpy");
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_1);
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_2);
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_3);
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_4);
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_5);
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_6);
  tcase_add_test(tc_s21_strcpy, test_s21_strcpy_7);
  suite_add_tcase(s, tc_s21_strcpy);

  return s;
}