#include "main.h"
#include <stdio.h>
#include <string.h>

int handler(const char *format, va_list args, char *buffer, int *count)
{
    /* ... */

    else if (*format == 'd' || *format == 'i')
    {
        int num = va_arg(args, int);
        sprintf(buffer, "%+d", num); /* Handle the + flag for signed integers */
        *count += strlen(buffer);
    }
    else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        sprintf(buffer, "%#u", num); /* Handle the # flag for unsigned integers */
        *count += strlen(buffer);
    }
    else if (*format == 'f' || *format == 'F')
    {
        double num = va_arg(args, double);
        sprintf(buffer, "%+f", num); /* Handle the + flag for floating-point numbers */
        *count += strlen(buffer);
    }
    else if (*format == 'g' || *format == 'G')
    {
        double num = va_arg(args, double);
        sprintf(buffer, "%+g", num); /* Handle the + flag for general floating-point numbers */
        *count += strlen(buffer);
    }
    else if (*format == 'e' || *format == 'E')
    {
        double num = va_arg(args, double);
        sprintf(buffer, "%+e", num); /* Handle the + flag for exponential floating-point numbers */
        *count += strlen(buffer);
    }
    else if (*format == 'x' || *format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        sprintf(buffer, "%#x", num); /* Handle the # flag for hexadecimal numbers */
        *count += strlen(buffer);
    }
    else if (*format == 'p')
    {
        void *ptr = va_arg(args, void *);
        uintptr_t address = (uintptr_t)ptr;
        sprintf(buffer, "%p", (void *)address);
        *count += strlen(buffer);
    }

    /* ... */

    return (*count);
}

