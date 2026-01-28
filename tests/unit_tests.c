#include <check.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#include "s21_string_test.h"

START_TEST(to_upper_test) {
  char destination[] = "Here w0 are123\0";
  char *test01 = s21_to_upper(destination);
  ck_assert_str_eq(test01, "HERE W0 ARE123");
  free(test01);

  char destination2[] = "Here w0 are\n\0";
  char *test02 = s21_to_upper(destination2);
  ck_assert_str_eq(test02, "HERE W0 ARE\n");
  free(test02);

  char destination3[] = "a\n\0";
  char *test03 = s21_to_upper(destination3);
  ck_assert_str_eq(test03, "A\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_upper(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_upper(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_upper(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_upper(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(to_lower_test) {
  char destination[] = "HERE W0 ARE123\0";
  char *test01 = s21_to_lower(destination);
  ck_assert_str_eq(test01, "here w0 are123");
  free(test01);

  char destination2[] = "HERE W0 ARE\n\0";
  char *test02 = s21_to_lower(destination2);
  ck_assert_str_eq(test02, "here w0 are\n");
  free(test02);

  char destination3[] = "A\n\0";
  char *test03 = s21_to_lower(destination3);
  ck_assert_str_eq(test03, "a\n");
  free(test03);

  char destination4[] = " \n\0";
  char *test04 = s21_to_lower(destination4);
  ck_assert_str_eq(test04, " \n");
  free(test04);

  char destination5[] = " \0";
  char *test05 = s21_to_lower(destination5);
  ck_assert_str_eq(test05, " ");
  free(test05);

  char destination6[] = "\n\0";
  char *test06 = s21_to_lower(destination6);
  ck_assert_str_eq(test06, "\n");
  free(test06);

  char destination7[] = "\0";
  char *test07 = s21_to_lower(destination7);
  ck_assert_str_eq(test07, "");
  free(test07);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = "School-21 test";
  char *s2 = "insert ";
  char *s3 = "amogus";
  char *s4 = "is";
  char *s5 = "shrek";
  char *res1 = s21_insert(s1, " ", 3);
  char *res2 = s21_insert(s5, s3, 5);
  char *res3 = s21_insert(s3, s5, 0);
  char *res4 = s21_insert(s5, s4, 5);
  char *res5 = s21_insert(s2, s1, 4);

  ck_assert_str_eq(res1, "Sch ool-21 test");
  ck_assert_str_eq(res2, "shrekamogus");
  ck_assert_str_eq(res3, "shrekamogus");
  ck_assert_str_eq(res4, "shrekis");
  ck_assert_str_eq(res5, "inseSchool-21 testrt ");

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = NULL;
  char s3[] = "";
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = NULL;
  char *s3 = NULL;
  char *s4 = NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char s1[] = " wtf ";
  char *s3 = NULL;
  char *s4 = "wtf";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

// Suite *s21_string_suite(void) {
//   Suite *s;
//   TCase *tc_core;

//   s = suite_create("s21_string");
//   tc_core = tcase_create("Core");

//   suite_add_tcase(s, tc_core);

//   return s;
// }

START_TEST(s21_to_lower_1) {
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_2) {
  char str1[] = "aBc";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_3) {
  char str1[] = "abC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_4) {
  char str1[] = "ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_5) {
  char str1[] = "123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "123");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_6) {
  char str1[] = "123ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "123abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_7) {
  char str1[] = "aBaBc";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "ababc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_8) {
  char str1[] = ".,/.,/.,";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, ".,/.,/.,");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_9) {
  char str1[] = "09876ABC";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "09876abc");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_10) {
  char str1[] = "ABC123";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abc123");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_11) {
  char str1[] = " ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_12) {
  char str1[] = "";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_13) {
  char str1[] = "A1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_14) {
  char str1[] = " A1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, " a1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_15) {
  char str1[] = "A1A1A1 ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1 ");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_16) {
  char str1[] = "AA1A1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "aa1a1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_17) {
  char str1[] = "A1a1A1A";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1a1a");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_18) {
  char str1[] = "A1A1\0a1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a1\0a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_19) {
  char str1[] = "A1a\n1A1";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "a1a\n1a1");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_20) {
  char str1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *str2 = s21_to_lower(str1);
  ck_assert_str_eq(str2, "abcdefghijklmnopqrstuvwxyz");
  free(str2);
}
END_TEST

START_TEST(s21_to_lower_21) {
  char *str1 = (char *)s21_to_lower("SLISH! A NU VSTAL!");
  char *str2 = "slish! a nu vstal!";
  ck_assert_str_eq(str1, str2);
  free(str1);

  char *str3 = (char *)s21_to_lower("aaa14353423aa!!!");
  char *str4 = "aaa14353423aa!!!";
  ck_assert_str_eq(str3, str4);
  free(str3);

  char *str7 = (char *)s21_to_lower("KomM hieR! scHneLl!");
  char *str8 = "komm hier! schnell!";
  ck_assert_str_eq(str7, str8);
  free(str7);
}
END_TEST

START_TEST(s21_to_lower_22) {
  char *str1 = s21_NULL;
  char *str2 = s21_to_lower(str1);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_1) {
  char str1[] = "abc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_2) {
  char str1[] = "aBc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_3) {
  char str1[] = "abC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_4) {
  char str1[] = "ABC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_5) {
  char str1[] = "123";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "123");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_6) {
  char str1[] = "123abc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "123ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_7) {
  char str1[] = "aBaBc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_8) {
  char str1[] = ".,/.,/.,";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, ".,/.,/.,");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_9) {
  char str1[] = "09876abc";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "09876ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_10) {
  char str1[] = "abc123";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC123");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_11) {
  char str1[] = " ";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_12) {
  char str1[] = "";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_13) {
  char str1[] = "a1a1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_14) {
  char str1[] = " a1a1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, " A1A1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_15) {
  char str1[] = "a1a1a1 ";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1A1 ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_16) {
  char str1[] = "Aa1a1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "AA1A1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_17) {
  char str1[] = "a1a1a1A";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1A1A");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_18) {
  char str1[] = "a1a1\0a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A1\0A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_19) {
  char str1[] = "a1a\n1a1";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "A1A\n1A1");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_20) {
  char str1[] = "abcdefghijklmnopqrstuvwxyz";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_21) {
  char str1[] = ")(*&^YTRYUIKJHWR<LR3.,tmwnrg.";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, ")(*&^YTRYUIKJHWR<LR3.,TMWNRG.");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_22) {
  char str1[] = " ";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, " ");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_23) {
  char str1[] = "ABC";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "ABC");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_24) {
  char str1[] = "_az{";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2, "_AZ{");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_25) {
  char str1[] =
      "SDFGHJKLPOIUYTREWQWERTYUIOP["
      "OIUYTRFGHJKLJHBVNMASDFGHJKLPOIUYTREWQWERTYUIO";
  char *str2 = s21_to_upper(str1);
  ck_assert_str_eq(str2,
                   "SDFGHJKLPOIUYTREWQWERTYUIOP["
                   "OIUYTRFGHJKLJHBVNMASDFGHJKLPOIUYTREWQWERTYUIO");
  free(str2);
}
END_TEST

START_TEST(s21_to_upper_26) {
  char *str1 = (char *)s21_to_upper("slish! a nu vstal!");
  char *str2 = "SLISH! A NU VSTAL!";
  ck_assert_str_eq(str1, str2);
  free(str1);
  char *str3 = (char *)s21_to_upper("AAAAA14353423AA!!!");
  char *str4 = "AAAAA14353423AA!!!";
  ck_assert_str_eq(str3, str4);
  free(str3);
  char *str7 = (char *)s21_to_upper("KomM hieR! scHneLl!");
  char *str8 = "KOMM HIER! SCHNELL!";
  ck_assert_str_eq(str7, str8);
  free(str7);
}
END_TEST

START_TEST(s21_to_upper_27) {
  char *str1 = s21_NULL;
  char *str2 = s21_to_upper(str1);
  ck_assert_ptr_null(str2);
  free(str2);
}
END_TEST

START_TEST(s21_insert_1) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdef");
  free(str3);
}
END_TEST

START_TEST(s21_insert_2) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 2;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abdefc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_3) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "adefbc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_4) {
  char str1[] = "abc";
  char str2[] = "def";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "defabc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_5) {
  char str1[] = "abcdefghijkl123456789";
  char str2[] = "xyz";
  int n = 5;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abcdexyzfghijkl123456789");
  free(str3);
}
END_TEST

START_TEST(s21_insert_6) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_7) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_8) {
  char str1[] = "abc";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_9) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 1;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_10) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "abc");
  free(str3);
}
END_TEST

START_TEST(s21_insert_11) {
  char str1[] = "";
  char str2[] = "abc";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_12) {
  char str1[] = "";
  char str2[] = "";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_pstr_eq(str3, s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_13) {
  char str1[] = "";
  char str2[] = "";
  int n = 0;
  char *str3 = s21_insert(str1, str2, n);
  ck_assert_str_eq(str3, "");
  free(str3);
}
END_TEST

START_TEST(s21_insert_14) {
  char *str1 = (char *)s21_insert("Sloniki", "iki", 2);
  char *str2 = "Slikioniki";
  ck_assert_str_eq(str1, str2);
  free(str1);
  char *str3 = (char *)s21_insert("salo", "ska", 3);
  char *str4 = "salskao";
  ck_assert_str_eq(str3, str4);
  free(str3);
  char *str5 = (char *)s21_insert("", "help", 5);
  char *str6 = s21_NULL;
  fail_unless(str5 == str6);
  free(str5);
  char *str7 = (char *)s21_insert("help!", "111", 5);
  char *str8 = "help!111";
  ck_assert_str_eq(str7, str8);
  free(str7);
}
END_TEST

START_TEST(s21_insert_15) {
  char *str1 = "SOS";
  char *str2 = s21_NULL;
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_16) {
  char *str1 = s21_NULL;
  char *str2 = "SOS";
  int n = 3;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_17) {
  char *str1 = "123";
  char *str2 = "SOS";
  int n = 6;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_18) {
  char *str1 = "123";
  char *str2 = "SOS";
  int n = -1;
  char *str3 = s21_insert(str1, str2, n);
  fail_unless(str3 == s21_NULL);
  free(str3);
}
END_TEST

START_TEST(s21_insert_19) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_20) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_21) {
  char src[] = "";
  char str[] = "";
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_22) {
  char *src = NULL;
  char *str = NULL;
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_23) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_insert_24) {
  char *src = "123";
  char *str = "456";
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

Suite *s21_string_suite() {
  Suite *s = suite_create("test");
  TCase *tc_core = tcase_create("test");

  tcase_add_test(tc_core, to_upper_test);
  tcase_add_test(tc_core, to_lower_test);
  tcase_add_test(tc_core, insert_test);
  tcase_add_test(tc_core, test_trim_1);
  tcase_add_test(tc_core, test_trim_2);
  tcase_add_test(tc_core, test_trim_3);
  tcase_add_test(tc_core, test_trim_4);
  tcase_add_test(tc_core, test_trim_5);
  tcase_add_test(tc_core, test_trim_6);
  tcase_add_test(tc_core, test_trim_7);
  tcase_add_test(tc_core, test_trim_8);
  tcase_add_test(tc_core, test_trim_9);
  tcase_add_test(tc_core, test_trim_10);

  tcase_add_test(tc_core, s21_to_lower_1);
  tcase_add_test(tc_core, s21_to_lower_2);
  tcase_add_test(tc_core, s21_to_lower_3);
  tcase_add_test(tc_core, s21_to_lower_4);
  tcase_add_test(tc_core, s21_to_lower_5);
  tcase_add_test(tc_core, s21_to_lower_6);
  tcase_add_test(tc_core, s21_to_lower_7);
  tcase_add_test(tc_core, s21_to_lower_8);
  tcase_add_test(tc_core, s21_to_lower_9);
  tcase_add_test(tc_core, s21_to_lower_10);
  tcase_add_test(tc_core, s21_to_lower_11);
  tcase_add_test(tc_core, s21_to_lower_12);
  tcase_add_test(tc_core, s21_to_lower_13);
  tcase_add_test(tc_core, s21_to_lower_14);
  tcase_add_test(tc_core, s21_to_lower_15);
  tcase_add_test(tc_core, s21_to_lower_16);
  tcase_add_test(tc_core, s21_to_lower_17);
  tcase_add_test(tc_core, s21_to_lower_18);
  tcase_add_test(tc_core, s21_to_lower_19);
  tcase_add_test(tc_core, s21_to_lower_20);
  tcase_add_test(tc_core, s21_to_lower_21);
  tcase_add_test(tc_core, s21_to_lower_22);
  // tcase_add_test(tc_core, s21_to_lower_23);
  // tcase_add_test(tc_core, s21_to_lower_24);
  // tcase_add_test(tc_core, s21_to_lower_25);

  tcase_add_test(tc_core, s21_to_upper_1);
  tcase_add_test(tc_core, s21_to_upper_2);
  tcase_add_test(tc_core, s21_to_upper_3);
  tcase_add_test(tc_core, s21_to_upper_4);
  tcase_add_test(tc_core, s21_to_upper_5);
  tcase_add_test(tc_core, s21_to_upper_6);
  tcase_add_test(tc_core, s21_to_upper_7);
  tcase_add_test(tc_core, s21_to_upper_8);
  tcase_add_test(tc_core, s21_to_upper_9);
  tcase_add_test(tc_core, s21_to_upper_10);
  tcase_add_test(tc_core, s21_to_upper_11);
  tcase_add_test(tc_core, s21_to_upper_12);
  tcase_add_test(tc_core, s21_to_upper_13);
  tcase_add_test(tc_core, s21_to_upper_14);
  tcase_add_test(tc_core, s21_to_upper_15);
  tcase_add_test(tc_core, s21_to_upper_16);
  tcase_add_test(tc_core, s21_to_upper_17);
  tcase_add_test(tc_core, s21_to_upper_18);
  tcase_add_test(tc_core, s21_to_upper_19);
  tcase_add_test(tc_core, s21_to_upper_20);
  tcase_add_test(tc_core, s21_to_upper_21);
  tcase_add_test(tc_core, s21_to_upper_22);
  tcase_add_test(tc_core, s21_to_upper_23);
  tcase_add_test(tc_core, s21_to_upper_24);
  tcase_add_test(tc_core, s21_to_upper_25);
  tcase_add_test(tc_core, s21_to_upper_26);
  tcase_add_test(tc_core, s21_to_upper_27);

  tcase_add_test(tc_core, s21_insert_1);
  tcase_add_test(tc_core, s21_insert_2);
  tcase_add_test(tc_core, s21_insert_3);
  tcase_add_test(tc_core, s21_insert_4);
  tcase_add_test(tc_core, s21_insert_5);
  tcase_add_test(tc_core, s21_insert_6);
  tcase_add_test(tc_core, s21_insert_7);
  tcase_add_test(tc_core, s21_insert_8);
  tcase_add_test(tc_core, s21_insert_9);
  tcase_add_test(tc_core, s21_insert_10);
  tcase_add_test(tc_core, s21_insert_11);
  tcase_add_test(tc_core, s21_insert_12);
  tcase_add_test(tc_core, s21_insert_13);
  tcase_add_test(tc_core, s21_insert_14);
  tcase_add_test(tc_core, s21_insert_15);
  tcase_add_test(tc_core, s21_insert_16);
  tcase_add_test(tc_core, s21_insert_17);
  tcase_add_test(tc_core, s21_insert_18);
  tcase_add_test(tc_core, s21_insert_19);
  tcase_add_test(tc_core, s21_insert_20);
  tcase_add_test(tc_core, s21_insert_21);
  tcase_add_test(tc_core, s21_insert_22);
  tcase_add_test(tc_core, s21_insert_23);
  tcase_add_test(tc_core, s21_insert_24);

  suite_add_tcase(s, tc_core);

  return s;
}
