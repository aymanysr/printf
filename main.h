#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct format - match the conversion for printf
 * @specifier: type char pointer to the specifier. (l, h) for d, i, u, o, x, X
 * @p_func: type pointer to the function for the conversion specifier
 */

typedef struct format
{
	char *specifier;
	int (*p_func)();
} convert_match;

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_string(va_list val);
size_t strlen(const char* str);
int printf_37(void);
int printf_dec(va_list args);
int printf_int(va_list args);
#endif
