#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <wchar.h>

#include "s21_string.h"

typedef struct {
  char specifier;  // спецификаторы

  int palka;     // Минус
  int krest;     // Плюс
  int probel;    // Пробел
  int reshotka;  // #
  int nol;       // 0

  int width;                // Ширина
  int precision;            // Точность
  int off_or_on_precision;  // Точность вкл/выкл
  char length;              // Длинна

} flags;

typedef struct {
  char specifier;
  void (*handle)(char*, va_list, flags*);
} specifier_handler;

int s21_sprintf(char* buffer, const char* format,
                ...);  // разобраться с restrict

const char* pars_flags(const char* format, flags* f);

void s21_process(char* buffer, const char* format, va_list ap,
                 specifier_handler* handlers);

//-------------------------------
const char* pars_width(const char* format, flags* f, va_list va);
const char* pars_precision(const char* format, flags* f, va_list va);
int checking_for_number(char c);
int transformation_in_int(const char* str);
const char* pars_length(const char* format, flags* f);
//-------------------------------

void specifiers_d_and_i(char* p, va_list ap, flags* f);
void specifier_u(char* p, va_list ap, flags* f);
void specifier_f(char* p, va_list ap, flags* f);
void specifier_c(char* p, va_list ap, flags* f);
void specifier_s(char* p, va_list ap, flags* f);
void specifier_o(char* p, va_list ap, flags* f);
void specifier_p(char* p, va_list ap, flags* f);
void specifier_Xx(char* p, va_list ap, flags* f);
void specifier_n(const char* buffer, const char* p, int* n_ptr, va_list ap);

void specifier_Ee(char* p, va_list ap, flags* f);

void process_d_ana_i(char* p, long int value, int length, flags* f);
void* obrabotca_d_and_i(char* p, long int value, int length);
void* obrabotca_u(char* p, int64_t value, int length);
void* obrabotca_s(char* p, char** ch, int vkl_s);
void* obrabotca_o(char* p, const char* octal_num, int length);
void* obrabotca_p(char* p, const char* hex_map, int* length, uintptr_t num);
void* obrabotca_Xx(char* p, const char* reverse_hex, int length);
void* obrabotca_reshotku_Xx(char* p, int on_rechotka, char specifier);

char* obrabotca_width(char* p, int len, int f);
char* obrabotca_precision(char* p, int len);

void double_to_string(long double val, char* ret, flags* f);
void format_flags(char* buff, flags* f);

#endif