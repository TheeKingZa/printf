#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;
char ch;
char *str;

va_start(args, format);

for (ptr = format; *ptr != '\0'; ptr++)
{
	if (*ptr == '%')
	{
	ptr++;

	switch (*ptr)
	{
		case 'c':
		ch = va_arg(args, int);
		putchar(ch);
		count++;
		break;

		case 's':
		str = va_arg(args, char *);
		fputs(str, stdout);
		count += strlen(str);
		break;
		
		case '%':
		putchar('%');
		count++;
		break;

		default:
		putchar('%');
		putchar(*ptr);
		count += 2;
		break;
	}
	}
	else
	{

	putchar(*ptr);
	count++;
	}
}

va_end(args);

return count;
}
