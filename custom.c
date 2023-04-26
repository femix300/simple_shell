#include "main.h"

/**
 * my_putchar - writes the character c to stdout
 * @c: The character that is to be printed
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
 * Return: void
 */
void my_printf(char *format, ...)
{
	va_list arg_list;
	va_start(arg_list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					{
						char *s = va_arg(arg_list, char *);
						while (*s != '\0')
						{
							my_putchar(*s++);
						}
						break;
					}
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

/**
 * my_snprintf - custom implementation of snprintf function
 *
 * @str: output string
 * @size: maximum length of output string
 * @format: format string
 * @...: variable arguments
 *
 * Return: the number of characters written (excluding null byte), or
 *         the number of characters that would have been written if
 *         the buffer was large enough.
 */

int my_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list arg_list;
	int chars_written = 0;
	size_t i = 0;

	va_start(arg_list, format);

	while (format[i] != '\0' && i < size) 
	{
		if (format[i] == '%') 
		{
			i++;
			if (format[i] == 's') 
			{
				char *s = va_arg(arg_list, char *);
				while (*s != '\0' && i < size) 
				{
					str[chars_written] = *s;
					chars_written++;
					s++;
					i++;
				}
			} 
			else 
			{
				str[chars_written] = format[i];
				chars_written++;
			}
		} 
		else 
		{
			str[chars_written] = format[i];
			chars_written++;
		}
		i++;
	}

	va_end(arg_list);

	if (i < size) 
	{
		str[i] = '\0';
	} 
	else if (size > 0) 
	{
		str[size - 1] = '\0';
	}

	return chars_written;
}
