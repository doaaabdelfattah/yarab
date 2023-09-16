#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
    int i, count;
    char *str;
    va_list arglist;

    va_start(arglist, format);
    if (format == NULL)
        return (-1);
    else
    {
        i = 0;
        count = 0;
        while (format[i] != '\0')
        if (format[i] != '%')
        {
            output_1(format[i]);
            count += 1;
            i++;
        }
        else
        {
            i++;
            if (format[i] == 'c')
            {
                output_1(va_arg(arglist, int));
                i++;
                count ++;
            }
            if (format[i] == 's')
            {
                str = va_arg(arglist, char *);
                output(str, strlen(str));
                i++;
                count ++;
            }
        }
    }
    va_end(arglist);
    return (count);
}

int main(void)
{
    _printf("my name is doaa ");
    _printf("my first letter is %c and second is %c and my total name is %s ", 'd', 'o', "doaa");
}

//    str = va_arg(arglist, char*);
//     j = 0;
//     while (str[j] != '\0')
//     output_1(str[j]);
//     count++;
//     j++;
