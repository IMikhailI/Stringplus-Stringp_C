#ifndef S21_STRING_TEST
#define S21_STRING_TEST

#include <check.h>
#include <string.h>

#include "../s21_string.h"

Suite *s21_string_memchr_test();
Suite *s21_string_memcmp_test();
Suite *s21_string_memcpy_test();
Suite *s21_string_memset_test();
Suite *s21_string_strncat_test();
Suite *s21_string_strchr_test();
Suite *s21_string_strncmp_test();
Suite *s21_string_strncpy_test();
Suite *s21_string_strcspn_test();
Suite *s21_strerror_suite();
Suite *s21_string_strlen_test();
Suite *s21_string_strpbrk_test();
Suite *s21_string_strrchr_test();
Suite *s21_string_strstr_test();
Suite *s21_string_strtok_test();
Suite *s21_string_suite();
Suite *sprint_suite();
Suite *s21_string_strcpy_test();

#endif