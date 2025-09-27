#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

int ft_scanf(const char *str, ...)
{
	va_list args;
	int count = 0;
	int c;
	int num;
	int sign;
	int digits;
	char *s;

	va_start(args, str);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
			{
				while ((c = fgetc(stdin)) != EOF && isspace(c))
					;
				if (c == EOF)
					break;

				sign = 1;
				if (c == '-' || c == '+')
				{
					if (c == '-')
						sign = -1;
					c = fgetc(stdin);
				}

				num = 0;
				digits = 0;
				while (c != EOF && isdigit(c))
				{
					num = num * 10 + (c - '0');
					digits++;
					c = fgetc(stdin);
				}

				if (digits == 0)
					break;
				if (c != EOF)
					ungetc(c, stdin);
				*(va_arg(args, int *)) = num * sign;
				count++;
			}
			else if (*str == 's')
			{
				while ((c = fgetc(stdin)) != EOF && isspace(c))
					;
				if (c == EOF)
					break;

				s = va_arg(args, char *);
				digits = 0;
				while (c != EOF && !isspace(c))
				{
					*s++ = c;
					digits++;
					c = fgetc(stdin);
				}

				if (digits == 0)
					break;
				*s = '\0';
				if (c != EOF)
					ungetc(c, stdin);
				count++;
			}
			else if (*str == 'c')
			{
				c = fgetc(stdin);
				if (c == EOF)
					break;
				*(va_arg(args, char *)) = c;
				count++;
			}
		}
		else if (isspace(*str))
		{
			while ((c = fgetc(stdin)) != EOF && isspace(c))
				;
			if (c != EOF)
				ungetc(c, stdin);
		}
		else
		{
			c = fgetc(stdin);
			if (c != *str)
			{
				if (c != EOF)
					ungetc(c, stdin);
				break;
			}
		}
		str++;
	}

	va_end(args);
	return count;
}
