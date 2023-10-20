#include "main.h"

int _printf(const char *format, ...)
{
	/**
	 * An array of structures, each defining a format specifier
	 * and a corresponding function for handling that specifier.
	 */
	convert_match m[] = {
		{"%c", printf_char}, {"%s", printf_string}, {"%%", printf_37}
	};

	va_list args_list;

	int i = 0, j, len = 0;

	va_start(args_list, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

	while (format[i] != '\0') /*Loop through the format string.*/
	{
		j = 2; /*Initialize j to the last index of the conversion specifier array.*/
		while (j >= 0)
		{
			/*Check if the current format matches any of the conversion specifiers.*/
			if (m[j].specifier[0] == format[i] && m[j].specifier[1] == format[i + 1])
			{
				/*Call the appropriate function and update the length and index.*/
				len += m[j].p_func(args_list);
				i += 2;
				break; /*exit loop*/
			}
			j--;
		}
		/*
		 * if no matching conversion specifier is found,
		 * print the character and update the length
		 */
		if (j < 0)
		{
			_putchar(format[i]);
			len++;
			i++;
		}
	}
	va_end(args_list);

	return (len);
}
