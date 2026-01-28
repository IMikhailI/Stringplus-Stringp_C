
#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "s21_sprintf.h"
#include "s21_string.h"
#include "s21_string_test.h"
#define SIZE 7000

START_TEST(simple_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(null_ptr) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "%p";
  char *ptr = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%.15Lf";
  long double val = 15.35;
  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);
  // ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
  // val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_huge_negative) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(e_precision) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%.17Le";
//   long double val = 15.35;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_precision_zero) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%.0Le";
//   long double val = 15.35;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(e_precision_empty) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%.Le";
//   long double val = 15.000009121;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_precision_huge) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%.15Le";
//   long double val = 0.000000000000000123;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(e_precision_huge_negative) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%.15Le";
//   long double val = -15.35581134;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(e_huge) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%Le";
//   long double val = 72537572375.1431341;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_flags) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%015E";
//   float val = 0;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_width) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%15e";
//   float val = 0;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(e_many) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "% .0e %.le %Le %e %le %Le";
//   float val = 0;
//   double val1 = 0;
//   long double val2 = 3515315.153151;
//   float val3 = 5.5;
//   double val4 = 0.094913941;
//   long double val5 = 95919539159.53151351131;
//   ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4,
//   val5),
//                    sprintf(str2, format, val, val1, val2, val3, val4, val5));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(E_int) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char *format = "%.17LE";
//   long double val = 4134121;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(all_empty) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_one_hex_lower) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_one_hex_lower_with_alignment_left) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_right) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_left) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_right) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_alignment) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_alignment) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_one_hex_with_hashtag) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_hashtag) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_one_hex_lower_with_width_star) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_width_star) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_one_hex_lower_with_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_precision) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_precision_and_other) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_precision_and_other) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_one_hex_lower_with_length) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf12) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
//   long double k = 333.33213;

//   ck_assert_int_eq(
//       s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
//       sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf14) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf16) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf28) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf29) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf31) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%e";
//   double x = 111;
//   ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf32) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%e%e%e%e";

//   ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666.,
//   -555.125),
//                    sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf33) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%Le";
//   long double x = 122.1231;

//   ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf35) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%.10e";

//   ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
//                    sprintf(str2, format, 111.184314818));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf36) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%5.3e%3.2e%lf";

//   ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
//                    sprintf(str2, format, 0.000111, 111.555, 1.999));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf37) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%E";

//   ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
//                    sprintf(str2, format, 0.666666));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf38) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%E%E%E";

//   ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
//                    sprintf(str2, format, 0.0000999, 111.9999, 6.666));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf39) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%e ABOBA %Lf %Lf %Le";
//   long double c = 848181;
//   long double a = 0.00000001;
//   long double b = 1111111.11;
//   ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
//                    sprintf(str2, format, 123.123, a, b, c));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(test_sprintf40) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%#e Floppa %#E%#f";

//   ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
//                    sprintf(str2, format, 123.111, 0.0000999, 0.555));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf41) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf42) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf43) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf44) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(g_trailing_zero) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%g";
//   double hex = 0.50300;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_large) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%g";
//   double hex = 5131.43141;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_small) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%g";
//   double hex = 0.123000;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_precision) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%.5g";
//   double hex = 0.123000;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_precision_zero) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%.0g";
//   double hex = 0.123000;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_precision_missing) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%.g";
//   double hex = 0.123000;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_many_zeroes_in_front) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%.g";
//   double hex = 0.0004;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_one_zero) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%g";
//   double hex = 0;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_zero) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%.5g";
//   double hex = 0;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_mantiss) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%g";
//   double hex = 0.0000005;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_mantiss_flags) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%5.8g";
//   double hex = 0.0000005;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(g_short_no_mantiss) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%g";
//   double hex = 0.005;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
// START_TEST(LG) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%LG";
//   long double hex = 0.000005;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format,
//   hex));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(g_many) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};
//   char format[] = "%LG %g %G %Lg %.5g";
//   long double hex = 0.000005;
//   double hex1 = 41.1341;
//   double hex2 = 848.9000;
//   long double hex3 = 0.0843;
//   double hex4 = 0.0005;
//   double hex5 = 0.8481481;
//   ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4,
//   hex5),
//                    sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

// START_TEST(wide_char) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   // setlocale(LC_ALL, "");

//   char *format = "This is a simple wide char %lc";
//   unsigned long w = L'汉';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }

START_TEST(width_char) {
  char str1[SIZE] = {0};
  char str2[SIZE] = {0};

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
// START_TEST(minus_wide_char) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %-5lc";
//   unsigned long w = L'森';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string1) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %5.12ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST

// START_TEST(wide_string2) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %120ls ABOBA";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string3) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %-43ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_string4) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %43ls";
//   wchar_t w[] = L"森我爱菠萝";
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_str_eq(str1, str2);
//   ck_assert_int_eq(a, b);
// }
// END_TEST
// START_TEST(wide_char2) {
//   char str1[SIZE] = {0};
//   char str2[SIZE] = {0};

//   char *format = "This is a simple wide char %43lc";
//   unsigned long w = L'森';
//   int a = s21_sprintf(str1, format, w);
//   int b = sprintf(str2, format, w);
//   ck_assert_int_eq(a, b);
//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(d_simple_int) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  int s21 = 5;
  int system = 5;
  s21_sprintf(s21_buff, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_negative_int) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  int s21 = -19;
  int system = -19;
  s21_sprintf(s21_buff, "This is %d", s21);
  sprintf(buff, "This is %d", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_int_in_middle_of_str) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  int s21 = 1024;
  int system = 1024;
  s21_sprintf(s21_buff, "This is %d number", s21);
  sprintf(buff, "This is %d number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_simple_test) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  char *s21 = "Hello str";
  char *system = "Hello str";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_empty_test) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  char *s21 = "";
  char *system = "";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_int_str_test) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  char *s21 = "12345";
  char *system = "12345";
  s21_sprintf(s21_buff, "This is %s", s21);
  sprintf(buff, "This is %s", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_str_in_middle_of_str) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  char *s21 = "my";
  char *system = "my";
  s21_sprintf(s21_buff, "This is %s string", s21);
  sprintf(buff, "This is %s string", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_simple) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 4.3;
  float system = 4.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_large_exponent) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 1234567891234567891.3;
  float system = 1234567891234567891.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_simple_zero) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 0.34;
  float system = 0.34;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_big_number) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 9.3425789;
  float system = 9.3425789;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_big_int_part) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 10.3;
  float system = 10.3;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_zero) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 0;
  float system = 0;
  s21_sprintf(s21_buff, "This is %f number", s21);
  sprintf(buff, "This is %f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_simple) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 2.322;
  float system = 2.322;
  s21_sprintf(s21_buff, "This is %.2f number", s21);
  sprintf(buff, "This is %.2f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_simple_rounding) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_hard_rounding) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = 2.3228;
  float system = 2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(exactness_with_hard_rounding_minus) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  float s21 = -2.3228;
  float system = -2.3228;
  s21_sprintf(s21_buff, "This is %.3f number", s21);
  sprintf(buff, "This is %.3f number", system);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_simple_char) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%c", 'c');
  sprintf(buff, "%c", 'c');

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_number_ASCII) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%c", 67);
  sprintf(buff, "%c", 67);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_number_char) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%c", '8');
  sprintf(buff, "%c", '8');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_space_char) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%c", ' ');
  sprintf(buff, "%c", ' ');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_simple_test) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%+d", 21);
  sprintf(buff, "%+d", 21);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_negative_number) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%+d", -250);
  sprintf(buff, "%+d", -250);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_plus_zero) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "result: %+d", 0);
  sprintf(buff, "result: %+d", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_simple_test) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "result: % d", 25);
  sprintf(buff, "result: % d", 25);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_negative_number) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "% d", -1000);
  sprintf(buff, "% d", -1000);

  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(flag_space_zero) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "% d", 0);
  sprintf(buff, "% d", 0);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_uint_max) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  unsigned int number = UINT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_int_max) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  int number = INT_MAX;
  s21_sprintf(s21_buff, "%u", number);
  sprintf(buff, "%u", number);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(d_width) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%5d", 1568);
  sprintf(buff, "%5d", 1568);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(f_width) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%4f", 15.15);
  sprintf(buff, "%4f", 15.15);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(c_width) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%10c", 'z');
  sprintf(buff, "%10c", 'z');
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(s_width) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%3s", "Hello, world!");
  sprintf(buff, "%3s", "Hello, world!");
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(left_justify) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  int x = 15;
  s21_sprintf(s21_buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  sprintf(buff, "%-10d %-5d %-7d %-2d", x, x, x, x);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

START_TEST(u_width) {
  char s21_buff[4000] = "";
  char buff[4000] = "";
  s21_sprintf(s21_buff, "%8u", 15678940);
  sprintf(buff, "%8u", 15678940);
  ck_assert_pstr_eq(s21_buff, buff);
}
END_TEST

Suite *sprint_suite() {
  Suite *s;
  TCase *tc_s21_sprintf;
  s = suite_create("sprint_tests");
  tc_s21_sprintf = tcase_create("CORE");
  tcase_add_test(tc_s21_sprintf, simple_int);
  tcase_add_test(tc_s21_sprintf, precise_int);
  tcase_add_test(tc_s21_sprintf, width_int);
  tcase_add_test(tc_s21_sprintf, minus_width_int);
  tcase_add_test(tc_s21_sprintf, plus_width_int);
  tcase_add_test(tc_s21_sprintf, padding_int);
  tcase_add_test(tc_s21_sprintf, star_width_int);
  tcase_add_test(tc_s21_sprintf, star_precision_int);
  tcase_add_test(tc_s21_sprintf, many_flags_many_ints);
  tcase_add_test(tc_s21_sprintf, flags_long_int);
  tcase_add_test(tc_s21_sprintf, flags_short_int);
  tcase_add_test(tc_s21_sprintf, flags_another_long_int);
  tcase_add_test(tc_s21_sprintf, zero_precision_zero_int);
  tcase_add_test(tc_s21_sprintf, space_flag_int);
  tcase_add_test(tc_s21_sprintf, unsigned_val);
  tcase_add_test(tc_s21_sprintf, unsigned_val_width);
  tcase_add_test(tc_s21_sprintf, unsigned_val_flags);
  tcase_add_test(tc_s21_sprintf, unsigned_val_precision);
  tcase_add_test(tc_s21_sprintf, unsigned_val_many_flags);
  tcase_add_test(tc_s21_sprintf, unsigned_val_short);
  tcase_add_test(tc_s21_sprintf, unsigned_val_long);
  tcase_add_test(tc_s21_sprintf, unsigned_val_many);
  tcase_add_test(tc_s21_sprintf, octal);
  tcase_add_test(tc_s21_sprintf, octal_width);
  tcase_add_test(tc_s21_sprintf, octal_flags);
  tcase_add_test(tc_s21_sprintf, octal_precision);
  tcase_add_test(tc_s21_sprintf, octal_many_flags);
  tcase_add_test(tc_s21_sprintf, octal_short);
  tcase_add_test(tc_s21_sprintf, octal_long);
  tcase_add_test(tc_s21_sprintf, octal_many);
  tcase_add_test(tc_s21_sprintf, octal_zero);
  tcase_add_test(tc_s21_sprintf, octal_hash);
  tcase_add_test(tc_s21_sprintf, unsigned_zero);
  tcase_add_test(tc_s21_sprintf, hex_width);
  tcase_add_test(tc_s21_sprintf, hex_flags);
  tcase_add_test(tc_s21_sprintf, hex_precision);
  tcase_add_test(tc_s21_sprintf, hex_many);
  tcase_add_test(tc_s21_sprintf, hex_many_flags);
  tcase_add_test(tc_s21_sprintf, hex_zero);
  tcase_add_test(tc_s21_sprintf, hex_huge);
  tcase_add_test(tc_s21_sprintf, hex_short);
  tcase_add_test(tc_s21_sprintf, hex_long);
  tcase_add_test(tc_s21_sprintf, hex_one_longer_width);
  tcase_add_test(tc_s21_sprintf, hex_two_longer_width);
  tcase_add_test(tc_s21_sprintf, one_char);
  tcase_add_test(tc_s21_sprintf, one_precision);
  tcase_add_test(tc_s21_sprintf, one_flags);
  tcase_add_test(tc_s21_sprintf, one_width);
  tcase_add_test(tc_s21_sprintf, one_many);
  tcase_add_test(tc_s21_sprintf, one_many_flags);
  tcase_add_test(tc_s21_sprintf, string);
  tcase_add_test(tc_s21_sprintf, string_precision);
  tcase_add_test(tc_s21_sprintf, string_width);
  tcase_add_test(tc_s21_sprintf, string_flags);
  tcase_add_test(tc_s21_sprintf, string_long);
  tcase_add_test(tc_s21_sprintf, string_many);
  tcase_add_test(tc_s21_sprintf, ptr);
  tcase_add_test(tc_s21_sprintf, ptr_width);
  tcase_add_test(tc_s21_sprintf, ptr_precision);
  tcase_add_test(tc_s21_sprintf, null_ptr);
  tcase_add_test(tc_s21_sprintf, n_specifier);
  tcase_add_test(tc_s21_sprintf, string_width_huge);
  tcase_add_test(tc_s21_sprintf, f_large_exponent);
  tcase_add_test(tc_s21_sprintf, float_precision);
  tcase_add_test(tc_s21_sprintf, float_width);
  tcase_add_test(tc_s21_sprintf, float_precision_zero);
  tcase_add_test(tc_s21_sprintf, float_precision_empty);
  tcase_add_test(tc_s21_sprintf, float_precision_huge);
  tcase_add_test(tc_s21_sprintf, float_precision_huge_negative);
  tcase_add_test(tc_s21_sprintf, float_huge);
  tcase_add_test(tc_s21_sprintf, float_flags);
  tcase_add_test(tc_s21_sprintf, float_many);
  // tcase_add_test(tc_s21_sprintf, e_precision);
  // tcase_add_test(tc_s21_sprintf, e_precision_zero);
  // tcase_add_test(tc_s21_sprintf, e_precision_empty);
  // tcase_add_test(tc_s21_sprintf, e_precision_huge);
  // tcase_add_test(tc_s21_sprintf, e_precision_huge_negative);
  // tcase_add_test(tc_s21_sprintf, e_huge);
  // tcase_add_test(tc_s21_sprintf, e_many);
  // tcase_add_test(tc_s21_sprintf, e_width);
  // tcase_add_test(tc_s21_sprintf, e_flags);
  // tcase_add_test(tc_s21_sprintf, E_int);
  tcase_add_test(tc_s21_sprintf, all_empty);
  tcase_add_test(tc_s21_sprintf, empty_format_and_parameters);
  tcase_add_test(tc_s21_sprintf, test_one_char);
  tcase_add_test(tc_s21_sprintf, test_many_char);
  tcase_add_test(tc_s21_sprintf, test_one_string);
  tcase_add_test(tc_s21_sprintf, test_many_string);
  tcase_add_test(tc_s21_sprintf, test_one_dec);
  tcase_add_test(tc_s21_sprintf, test_many_dec);
  tcase_add_test(tc_s21_sprintf, test_one_int);
  tcase_add_test(tc_s21_sprintf, test_many_int);
  tcase_add_test(tc_s21_sprintf, test_one_float);
  tcase_add_test(tc_s21_sprintf, test_many_float);
  tcase_add_test(tc_s21_sprintf, test_one_unsigned_dec);
  tcase_add_test(tc_s21_sprintf, test_many_unsigned_dec);
  tcase_add_test(tc_s21_sprintf, test_one_char_with_alignment_left);
  tcase_add_test(tc_s21_sprintf, test_one_char_with_alignment_right);
  tcase_add_test(tc_s21_sprintf, test_many_char_with_alignment);
  tcase_add_test(tc_s21_sprintf, test_one_hex_lower);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper);
  tcase_add_test(tc_s21_sprintf, test_many_hex_lower);
  tcase_add_test(tc_s21_sprintf, test_many_hex_upper);
  tcase_add_test(tc_s21_sprintf, test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc_s21_sprintf, test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc_s21_sprintf, test_many_hex_lower_with_alignment);
  tcase_add_test(tc_s21_sprintf, test_many_hex_upper_with_alignment);
  tcase_add_test(tc_s21_sprintf, test_one_hex_with_hashtag);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper_with_hashtag);
  tcase_add_test(tc_s21_sprintf, test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc_s21_sprintf, test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc_s21_sprintf, test_one_hex_lower_with_width_star);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper_with_width_star);
  tcase_add_test(tc_s21_sprintf,
                 test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc_s21_sprintf, test_many_hex_upper_with_width_star);
  tcase_add_test(tc_s21_sprintf, test_one_hex_lower_with_precision);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper_with_precision);
  tcase_add_test(tc_s21_sprintf, test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc_s21_sprintf, test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc_s21_sprintf, test_one_hex_lower_with_length);
  tcase_add_test(tc_s21_sprintf, test_one_hex_upper_with_length);
  tcase_add_test(tc_s21_sprintf, test_sprintf1);
  tcase_add_test(tc_s21_sprintf, test_sprintf2);
  tcase_add_test(tc_s21_sprintf, test_sprintf3);
  tcase_add_test(tc_s21_sprintf, test_sprintf4);
  tcase_add_test(tc_s21_sprintf, test_sprintf6);
  tcase_add_test(tc_s21_sprintf, test_sprintf7);
  tcase_add_test(tc_s21_sprintf, test_sprintf8);
  tcase_add_test(tc_s21_sprintf, test_sprintf9);
  tcase_add_test(tc_s21_sprintf, test_sprintf10);
  tcase_add_test(tc_s21_sprintf, test_sprintf11);
  // tcase_add_test(tc_s21_sprintf, test_sprintf12);
  tcase_add_test(tc_s21_sprintf, test_sprintf14);
  tcase_add_test(tc_s21_sprintf, test_sprintf15);
  tcase_add_test(tc_s21_sprintf, test_sprintf16);
  tcase_add_test(tc_s21_sprintf, test_sprintf17);
  tcase_add_test(tc_s21_sprintf, test_sprintf18);
  tcase_add_test(tc_s21_sprintf, test_sprintf19);
  tcase_add_test(tc_s21_sprintf, test_sprintf20);
  tcase_add_test(tc_s21_sprintf, test_sprintf24);
  tcase_add_test(tc_s21_sprintf, test_sprintf25);
  tcase_add_test(tc_s21_sprintf, test_sprintf28);
  tcase_add_test(tc_s21_sprintf, test_sprintf29);
  tcase_add_test(tc_s21_sprintf, test_sprintf30);
  // tcase_add_test(tc_s21_sprintf, test_sprintf31);
  // tcase_add_test(tc_s21_sprintf, test_sprintf32);
  // tcase_add_test(tc_s21_sprintf, test_sprintf33);
  // tcase_add_test(tc_s21_sprintf, test_sprintf35);
  // tcase_add_test(tc_s21_sprintf, test_sprintf36);
  // tcase_add_test(tc_s21_sprintf, test_sprintf37);
  // tcase_add_test(tc_s21_sprintf, test_sprintf38);
  // tcase_add_test(tc_s21_sprintf, test_sprintf39);
  // tcase_add_test(tc_s21_sprintf, test_sprintf40);
  tcase_add_test(tc_s21_sprintf, test_sprintf41);
  tcase_add_test(tc_s21_sprintf, test_sprintf42);
  tcase_add_test(tc_s21_sprintf, test_sprintf43);
  tcase_add_test(tc_s21_sprintf, test_sprintf44);
  // tcase_add_test(tc_s21_sprintf, g_trailing_zero);
  // tcase_add_test(tc_s21_sprintf, g_large);
  // tcase_add_test(tc_s21_sprintf, g_small);
  // tcase_add_test(tc_s21_sprintf, g_precision);
  // tcase_add_test(tc_s21_sprintf, g_precision_zero);
  // tcase_add_test(tc_s21_sprintf, g_precision_missing);
  // tcase_add_test(tc_s21_sprintf, g_many_zeroes_in_front);
  // tcase_add_test(tc_s21_sprintf, g_one_zero);
  // tcase_add_test(tc_s21_sprintf, g_mantiss);
  // tcase_add_test(tc_s21_sprintf, g_mantiss_flags);
  // tcase_add_test(tc_s21_sprintf, g_short_no_mantiss);
  // tcase_add_test(tc_s21_sprintf, LG);
  // tcase_add_test(tc_s21_sprintf, g_many);
  // tcase_add_test(tc_s21_sprintf, g_zero);

  tcase_add_test(tc_s21_sprintf, width_char);

  tcase_add_test(tc_s21_sprintf, d_simple_int);
  tcase_add_test(tc_s21_sprintf, d_negative_int);
  tcase_add_test(tc_s21_sprintf, d_int_in_middle_of_str);
  tcase_add_test(tc_s21_sprintf, s_simple_test);
  tcase_add_test(tc_s21_sprintf, s_empty_test);
  tcase_add_test(tc_s21_sprintf, s_int_str_test);
  tcase_add_test(tc_s21_sprintf, s_str_in_middle_of_str);
  tcase_add_test(tc_s21_sprintf, f_simple);
  tcase_add_test(tc_s21_sprintf, f_simple_zero);
  tcase_add_test(tc_s21_sprintf, f_big_number);
  tcase_add_test(tc_s21_sprintf, f_big_int_part);
  tcase_add_test(tc_s21_sprintf, f_zero);
  tcase_add_test(tc_s21_sprintf, exactness_simple);
  tcase_add_test(tc_s21_sprintf, exactness_with_simple_rounding);
  tcase_add_test(tc_s21_sprintf, exactness_with_hard_rounding);
  tcase_add_test(tc_s21_sprintf, exactness_with_hard_rounding_minus);
  tcase_add_test(tc_s21_sprintf, c_simple_char);
  tcase_add_test(tc_s21_sprintf, c_number_ASCII);
  tcase_add_test(tc_s21_sprintf, c_number_char);
  tcase_add_test(tc_s21_sprintf, c_space_char);
  tcase_add_test(tc_s21_sprintf, flag_plus_simple_test);
  tcase_add_test(tc_s21_sprintf, flag_plus_negative_number);
  tcase_add_test(tc_s21_sprintf, flag_plus_zero);
  tcase_add_test(tc_s21_sprintf, flag_space_simple_test);
  tcase_add_test(tc_s21_sprintf, flag_space_negative_number);
  tcase_add_test(tc_s21_sprintf, flag_space_zero);
  tcase_add_test(tc_s21_sprintf, u_uint_max);
  tcase_add_test(tc_s21_sprintf, u_int_max);
  tcase_add_test(tc_s21_sprintf, d_width);
  tcase_add_test(tc_s21_sprintf, f_width);
  tcase_add_test(tc_s21_sprintf, c_width);
  tcase_add_test(tc_s21_sprintf, s_width);
  tcase_add_test(tc_s21_sprintf, left_justify);
  tcase_add_test(tc_s21_sprintf, u_width);
  // tcase_add_test(tc_s21_sprintf, wide_char);
  // tcase_add_test(tc_s21_sprintf, minus_wide_char);
  // tcase_add_test(tc_s21_sprintf, wide_string);
  // tcase_add_test(tc_s21_sprintf, wide_string1);
  // tcase_add_test(tc_s21_sprintf, wide_string2);
  // tcase_add_test(tc_s21_sprintf, wide_string3);
  // tcase_add_test(tc_s21_sprintf, wide_string4);
  // tcase_add_test(tc_s21_sprintf, wide_char2);
  suite_add_tcase(s, tc_s21_sprintf);

  return s;
}