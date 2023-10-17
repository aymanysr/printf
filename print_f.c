#include "main.h"

int _printf(const char *format, ...)
{
	int char_print = 0;

	va_list args_list;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args_list, format);

	while (*format) /*a loop that iterates through the chars of the format*/
	{
		if (*format != '%') /*if format is not the % sign*/
		{
			write(1, format, 1); /*write the char to the standard output*/
			char_print++;
		}
		else /*if format is the % sign*/
		{
			format++; /*check the next character*/

			if (*format == '\0') /*if format is null*/
				break;

			if (*format == '%') /*this is for %%*/
			{
				/*handles doube '%'*/
				write(1, format, 1);
				char_print++;
			}
			else if (*format == 'c')
			{
				/*handles '%c'*/
				char c = va_arg(args_list, int);

				write(1, &c, 1);
				char_print++;
			}
			else if (*format == 's')
			{
				/*handles '%s'*/
				char *str = va_arg(args_list, char*);
				int str_length = 0;

				/*to calculate the length of str*/
				while (str[str_length] != '\0')
					str_length++;
				/*to write the str to the standard output*/
				write(1, str, str_length);
				char_print += str_length;
			}
		}

		format++;
	}

	va_end(args_list);

	return (char_print);
}

int main(void)
{
	_printf("Aim\n");
	_printf("%c\n", 'v');
	_printf("%s\n", "String");
	_printf("%%\n");
	return (0);
}
