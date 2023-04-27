#include "main.h"

/**
 * my_putchar - writes the character c to stdout
 *
 * @c: The character that is to be printed
 *
 * Description: Custom implementation of putchar
 *
 * Return: On sucess 1.
 * on error, -1 is returned, and erno is set appropriately
 */
int my_putchar(int c)
{
	return (write(1, &c, 1));
}


/**
 * my_printf - custom implementation of printf function
 *
 * @format: format string
 *
 * Description: A custom printf function
 * Return: void
 */
void my_printf(char *format, ...)
{
	va_list arg_list;
	char *s;

	va_start(arg_list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					s = va_arg(arg_list, char *);
					while (*s != '\0')
					{
						my_putchar(*s++);
					}
					break;
				default:
					my_putchar(*format);
					break;
			}
		}
		else
		{
			my_putchar(*format);
		}
		format++;
	}

	va_end(arg_list);
}
