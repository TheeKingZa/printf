#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - EntryPoint. 
 *
 * @va_list: The function begins by initializing a va_list named args to access the variable
 *		arguments.
 *		It also declares some variables to store characters and strings.
 */

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

return (count);
}
