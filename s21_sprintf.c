#include "s21_sprintf.h"

int s21_sprintf(char* buffer, const char* format, ...) {
  va_list ap;
  va_start(ap, format);

  char* p2 = buffer;
  specifier_handler handlers[] = {
      {'d', &specifiers_d_and_i}, {'i', &specifiers_d_and_i},
      {'u', &specifier_u},        {'o', &specifier_o},
      {'s', &specifier_s},        {'p', &specifier_p},
      {'x', &specifier_Xx},       {'X', &specifier_Xx},
      {'c', &specifier_c},        {'f', &specifier_f},
  };
  while (*p2 != '\0') {
    *p2++ = '\0';
  }
  s21_process(buffer, format, ap, handlers);
  va_end(ap);
  return s21_strlen(buffer);
}

void s21_process(char* buffer, const char* format, va_list ap,
                 specifier_handler* handlers) {
  char* p = buffer;
  int* n_ptr = 0;

  while (*format) {
    flags f = {0};
    if (*format == '%' && *(format + 1) != '\0') {
      if (*(format + 1) == '%') {
        *p++ = '%';
        format += 2;
        continue;
      }
      format++;
      format = pars_flags(format, &f);
      format = pars_width(format, &f, ap);
      format = pars_precision(format, &f, ap);
      format = pars_length(format, &f);
      f.specifier = *format;
      void (*ptr_handler)(char*, va_list, flags*) = NULL;
      for (long unsigned int i = 0; i <= sizeof(handlers) + 1; i++) {
        if (handlers[i].specifier == f.specifier) {
          ptr_handler = handlers[i].handle;
        }
      }
      if (ptr_handler) {
        ptr_handler(p, ap, &f);
        while (*p != '\0') {
          p++;
        }
      } else if (f.specifier == 'n') {
        specifier_n(buffer, p, n_ptr, ap);
      }
    } else {
      *p++ = *format;
    }
    format++;
  }
  *p++ = '\0';
}

const char* pars_flags(const char* format, flags* f) {
  while ((*format == '%' || *format == '0' || *format == '-' ||
          *format == '+' || *format == ' ' || *format == '#')) {
    switch (*format) {
      case '0':
        f->nol = 1;
        break;
      case '-':
        f->palka = 1;
        break;
      case '+':
        f->krest = 1;
        break;
      case ' ':
        f->probel = 1;
        break;
      case '#':
        f->reshotka = 1;
        break;
    }
    format++;
  }
  return format;
}

//-------------------------------

const char* pars_width(const char* format, flags* f, va_list vp) {
  if (*format == '*') {
    format++;
    f->width = va_arg(vp, int);
    if (f->width < 0) {
      f->width *= -1;
      f->palka = 1;
    }
  } else if (checking_for_number(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; checking_for_number(*format); i++, format++)
      tmp[i] = *format;
    f->width = transformation_in_int(tmp);
  }
  return format;
}

const char* pars_precision(const char* format, flags* f, va_list vp) {
  if (*format == '.') {
    f->off_or_on_precision = 1;
    format++;
  }

  if (*format == '*') {
    format++;
    f->precision = va_arg(vp, int);
    if (f->precision < 0) {
      f->precision = 0;
    }
    f->off_or_on_precision = 1;
    if (f->precision < 0) f->off_or_on_precision = 0;
  } else if (checking_for_number(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; checking_for_number(*format); i++, format++)
      tmp[i] = *format;
    f->precision = transformation_in_int(tmp);
  } /* else f->off_or_on_precision = 0; */
  return format;
}

int checking_for_number(char c) { return (c >= '0' && c <= '9'); }

int transformation_in_int(const char* str) {
  int res = 0;
  int sign = 1;
  int overflow = 0;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && checking_for_number(*str) && overflow == 0) {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = 1;
    }
    str++;
  }
  if (overflow)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;

  return res;
}

const char* pars_length(const char* format, flags* f) {
  switch (*format) {
    case 'h':
      f->length = 'h';
      format++;
      break;
    case 'l':
      f->length = 'l';
      format++;
      break;
    case 'L':
      f->length = 'L';
      format++;
  }
  return format;
}

//-------------------------------

void specifier_f(char* p, va_list ap, flags* f) {
  long double val = 0;
  if (f->length == 'L') {
    val = va_arg(ap, long double);
  } else {
    val = va_arg(ap, double);
  }

  if (!f->off_or_on_precision) {
    f->precision = 6;
  }

  double_to_string(val, p, f);
  format_flags(p, f);
}

void double_to_string(long double val, char* ret, flags* f) {
  char buff[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;
  int neg = val < 0 ? 1 : 0;
  val = neg ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);
  if (f->precision == 0) {
    l = roundl(val);
    r = 0;
  }
  char fractions[BUFF_SIZE] = {'\0'};
  for (int i = 0; i < f->precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < f->precision; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((f->off_or_on_precision && f->precision != 0) ||
      (!f->off_or_on_precision && val == 0) || s21_strlen(fractions))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (neg && i == 0) {
      ret[i] = '-';
      i++;
    }
    ret[i] = buff[idx + 1];
  }
}

void format_flags(char* buff, flags* f) {
  char tmp[BUFF_SIZE + 1] = {'\0'};
  if (f->krest && f->specifier != 'u') {
    tmp[0] = buff[0] == '-' ? buff[0] : '+';
    s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
    s21_strcpy(buff, tmp);
  } else if (f->probel && buff[0] != '-' && f->specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);
  }
  if (f->width > (int)s21_strlen(buff)) {
    int idx = f->width - s21_strlen(buff);
    if (!f->palka) {
      s21_memset(tmp, f->nol ? '0' : ' ', idx);
      s21_strcpy(tmp + idx, buff);
    } else {
      s21_strcpy(tmp, buff);
      s21_memset(tmp + s21_strlen(tmp), ' ', idx);
    }
    s21_strcpy(buff, tmp);
  }
}

void specifiers_d_and_i(char* p, va_list ap, flags* f) {
  long int value = 0;
  if (f->length == 'h')
    value = (short int)va_arg(ap, int);
  else if (f->length == 'l')
    value = va_arg(ap, long int);
  else
    value = va_arg(ap, int);

  int length = 0;
  long int temp = value;
  for (; temp != 0; length++) temp /= 10;
  process_d_ana_i(p, value, length, f);
}

void process_d_ana_i(char* p, long int value, int length, flags* f) {
  int minus = 0;
  int plus = 0;
  if (value < 0) {
    minus = 1;
    if (f->nol) *p++ = '-';
    f->krest = 0;
    f->probel = 0;
    value = -value;
  }
  if (value > 0 && f->krest) plus = 1;
  if (f->probel && !f->krest) *p++ = ' ';
  int size = f->precision
                 ? f->width - ((f->precision - length) + length + minus + plus)
                 : f->width - length - minus - plus;
  if (value != 0) {
    if (f->palka) {
      if (minus == 1) *p++ = '-';
      if (value > 0 && f->krest) *p++ = '+';
      p = obrabotca_precision(p, f->precision - length);
      p = obrabotca_d_and_i(p, value, length);
      obrabotca_width(p, size, f->nol);
    } else {
      p = obrabotca_width(p, size, f->nol);
      if (value > 0 && f->krest) *p++ = '+';
      if (!f->nol && minus == 1) *p++ = '-';
      p = obrabotca_precision(p, f->precision - length);
      obrabotca_d_and_i(p, value, length);
    }
  } else {
    if (f->off_or_on_precision && f->precision == 0) {
    } else {
      if (f->krest && !f->precision) {
        plus = 1;
      }
      int size2 =
          f->precision
              ? f->width - ((f->precision - 1) + 1 + minus + f->krest ? 1 : 0)
              : f->width - 1 - minus - plus;
      if (f->palka) {
        if (f->krest) *p++ = '+';
        p = obrabotca_precision(p, f->precision - 1 - plus);
        *p++ = '0';
        obrabotca_width(p, size2, f->nol);
      } else {
        p = obrabotca_width(p, size2, f->nol);
        if (f->krest) *p++ = '+';
        p = obrabotca_precision(p, f->precision - 1 - plus);
        minus == 1 ? * p++ = '-' : (minus = 0);
        *p++ = '0';
      }
    }
  }
}

void* obrabotca_d_and_i(char* p, long int value, int length) {
  char* current = p + length - 1;
  while (value > 0) {
    *current-- = '0' + (value % 10);
    value /= 10;
  }
  p += length;
  return p;
}

void specifier_u(char* p, va_list ap, flags* f) {
  unsigned long int value = 0;
  if (f->length == 'h') {
    value = (unsigned short int)va_arg(ap, unsigned int);
  } else if (f->length == 'l') {
    value = va_arg(ap, unsigned long int);
  } else {
    value = va_arg(ap, unsigned int);
  }

  if (value != 0) {
    int length = 0;
    long int temp = value;
    while (temp != 0) {
      temp /= 10;
      ++length;
    }
    if (f->precision < length) f->off_or_on_precision = 0;
    int size = f->off_or_on_precision
                   ? f->width - ((f->precision - length) + length)
                   : f->width - length;

    if (f->palka) {
      p = obrabotca_precision(p, f->precision - length);
      p = obrabotca_u(p, value, length);
      obrabotca_width(p, size, f->nol);
    } else {
      p = obrabotca_width(p, size, f->nol);
      p = obrabotca_precision(p, f->precision - length);
      obrabotca_u(p, value, length);
    }
  } else {
    *p++ = '0';
  }
}

void* obrabotca_u(char* p, long int value, int length) {
  char* current = p + length - 1;
  while (value > 0) {
    *current-- = '0' + (value % 10);
    value /= 10;
  }
  p += length;
  return p;
}

void specifier_c(char* p, va_list ap, flags* f) {
  char ch = (char)va_arg(ap, int);
  if (f->width) {
    if (f->palka) {
      *p++ = ch;
      obrabotca_width(p, f->width - 1, 0);
    } else {
      p = obrabotca_width(p, f->width - 1, 0);
      *p++ = ch;
    }
  } else {
    *p++ = ch;
    f->width = 0;
  }
}

void specifier_s(char* p, va_list ap, flags* f) {
  char* ch = va_arg(ap, char*);
  int vkl_s = f->off_or_on_precision ? f->precision : -1;
  int size = 0;
  if (vkl_s > -1 && (s21_size_t)f->precision < s21_strlen(ch))
    size = f->precision;
  else
    size = s21_strlen(ch);
  if (f->width) {
    if (f->palka) {
      p = obrabotca_s(p, &ch, vkl_s);
      obrabotca_width(p, f->width - size, 0);
    } else {
      p = obrabotca_width(p, f->width - size, 0);
      obrabotca_s(p, &ch, vkl_s);
    }
  } else {
    obrabotca_s(p, &ch, vkl_s);
  }
}

void* obrabotca_s(char* p, char** ch, int vkl_s) {
  for (s21_size_t i = 0;
       i < (vkl_s < 0                             ? s21_strlen(*ch)
            : (s21_size_t)vkl_s > s21_strlen(*ch) ? s21_strlen(*ch)
                                                  : (s21_size_t)vkl_s);
       i++) {
    *p++ = (*ch)[i];
  }

  return p;
}

void specifier_o(char* p, va_list ap, flags* f) {
  long int value = 0;
  if (f->length == 'h') {
    value = (unsigned short int)va_arg(ap, unsigned int);
  } else if (f->length == 'l') {
    value = va_arg(ap, unsigned long int);
  } else {
    value = va_arg(ap, unsigned int);
  }

  int length = 0;
  char octal_num[50] = {0};
  do {
    octal_num[length++] = (char)('0' + (value % 8));
    value /= 8;
  } while (value != 0);

  if (f->palka) {
    if (f->reshotka) *p++ = '0';
    p = obrabotca_precision(p, f->precision - length);
    p = obrabotca_o(p, octal_num, length);
    obrabotca_width(p, f->width - (f->reshotka > 0 ? length + 1 : length),
                    f->nol);
  } else {
    p = obrabotca_width(p, f->width - (f->reshotka > 0 ? length + 1 : length),
                        f->nol);
    if (f->reshotka) *p++ = '0';
    p = obrabotca_precision(p, f->precision - length);
    obrabotca_o(p, octal_num, length);
  }
}

void* obrabotca_o(char* p, const char* octal_num, int length) {
  while (length > 0) {
    *p++ = octal_num[--length];
  }
  return p;
}

void specifier_Xx(char* p, va_list ap, flags* f) {
  long int value = 0;
  if (f->length == 'h') {
    value = (unsigned short int)va_arg(ap, unsigned int);
  } else if (f->length == 'l') {
    value = va_arg(ap, unsigned long int);
  } else {
    value = va_arg(ap, unsigned int);
  }
  // int minus = 0;
  // if (value < 0) {
  //   // minus = 1;
  //   f->krest = 0;
  //   f->probel = 0;
  //   value = -value;
  // }

  if (value != 0) {
    char reverse_hex[200] = {0};
    int i = 0;

    if (f->reshotka && f->nol) {
      p = obrabotca_reshotku_Xx(p, f->reshotka, f->specifier);
    }

    while (value > 0) {
      int remainder = value % 16;
      if (remainder < 10) {
        reverse_hex[i] = remainder + '0';
      } else {
        reverse_hex[i] = remainder - 10 + (f->specifier == 'x' ? 'a' : 'A');
      }
      value /= 16;
      i++;
    }

    int length = i;

    int kakoi = 0;
    if (f->reshotka) kakoi += 2;
    if (f->precision < (int)s21_strlen(reverse_hex)) f->off_or_on_precision = 0;
    int size = f->off_or_on_precision
                   ? f->width - ((f->precision - length) +
                                 s21_strlen(reverse_hex) + kakoi)
                   : f->width - (s21_strlen(reverse_hex) + kakoi);

    if (f->palka) {
      if (!f->nol) p = obrabotca_reshotku_Xx(p, f->reshotka, f->specifier);
      p = obrabotca_precision(p, f->precision - s21_strlen(reverse_hex));
      p = obrabotca_Xx(p, reverse_hex, length);
      obrabotca_width(p, size, f->nol);
    } else {
      p = obrabotca_width(p, size, f->nol);
      if (!f->nol) p = obrabotca_reshotku_Xx(p, f->reshotka, f->specifier);
      p = obrabotca_precision(p, f->precision - s21_strlen(reverse_hex));
      obrabotca_Xx(p, reverse_hex, length);
    }
  } else {
    int size =
        f->precision ? f->width - ((f->precision - 1) + 1) : f->width - 1;
    if (f->palka) {
      p = obrabotca_precision(p, f->precision - 1);
      *p++ = '0';
      obrabotca_width(p, size, f->nol);
    } else {
      p = obrabotca_width(p, size, f->nol);
      p = obrabotca_precision(p, f->precision - 1);
      *p++ = '0';
    }
  }
}

void* obrabotca_reshotku_Xx(char* p, int on_rechotka, char specifier) {
  if (on_rechotka) {
    if (specifier == 'x') {
      *p++ = '0';
      *p++ = 'x';
    } else {
      *p++ = '0';
      *p++ = 'X';
    }
  }
  return p;
}

void* obrabotca_Xx(char* p, const char* reverse_hex, int length) {
  for (int j = 0; j < length; j++) {
    *p++ = reverse_hex[length - j - 1];
  }
  return p;
}

void specifier_n(const char* buffer, const char* p, int* n_ptr, va_list ap) {
  n_ptr = va_arg(ap, int*);
  *n_ptr = p - buffer;
}

void specifier_p(char* p, va_list ap, flags* f) {
  uintptr_t num = va_arg(ap, uintptr_t);
  if (num) {
    const char hex_map[] = "0123456789abcdef";

    int length = 0;
    if (f->krest) *p++ = '+';
    if (f->probel && !f->krest) *p++ = ' ';
    obrabotca_p(p, hex_map, &length, num);

    int size = f->precision ? f->width - ((f->precision - length) + length)
                            : f->width - length - 2;

    if (f->palka) {
      *p++ = '0';
      *p++ = 'x';
      p = obrabotca_precision(p, f->precision - length);
      length = 0;
      p = obrabotca_p(p, hex_map, &length, num);
      obrabotca_width(p, size, f->nol);
    } else {
      p = obrabotca_width(p, size, f->nol);
      *p++ = '0';
      *p++ = 'x';
      p = obrabotca_precision(p, f->precision - length);
      length = 0;
      obrabotca_p(p, hex_map, &length, num);
    }
  } else {
    char* str = "(nil)";
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      *p++ = str[i];
    }
  }
}

void* obrabotca_p(char* p, const char* hex_map, int* length, uintptr_t num) {
  int non_zero = 0;
  int shift = sizeof(void*) * 2 - 1;
  while (shift >= 0) {
    int index = (num >> (shift * 4)) & 0xF;
    if (index > 0 || non_zero) {
      *p++ = hex_map[index];
      (*length)++;
      non_zero = 1;
    }
    shift--;
  }
  if (*length == 0) {
    *p++ = '0';
  }
  return p;
}

char* obrabotca_width(char* p, int len, int f) {
  for (int i = 0; i < len; i++) {
    f == 0 ? (*p++ = ' ') : (*p++ = '0');
  }
  return p;
}

char* obrabotca_precision(char* p, int len) {
  for (int i = 0; i < len; i++) {
    *p++ = '0';
  }
  return p;
}
