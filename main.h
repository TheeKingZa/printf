#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_integer(int num);
int print_binary(unsigned int num);
int print_string(char *str);
int handler(const char *format, va_list args, char *buffer, int *count);


#endif /* MAIN_H */

