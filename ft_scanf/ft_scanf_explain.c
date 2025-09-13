#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

static int read_int(va_list *args)
{
	int c, sign = 1, num = 0, digits = 0;

	while ((c = fgetc(stdin)) != EOF && isspace(c))
		;

	if (c == EOF)
		return 0;

	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		c = fgetc(stdin);
	}

	while (c != EOF && isdigit(c))
	{
		num = num * 10 + (c - '0');
		digits++;
		c = fgetc(stdin);
	}

	if (digits == 0)
		return 0;
	if (c != EOF)
		ungetc(c, stdin);
	*(va_arg(*args, int *)) = num * sign;
	return 1;
}

static int read_string(va_list *args)
{
	int c, count = 0;
	char *str;

	while ((c = fgetc(stdin)) != EOF && isspace(c))
		;
	if (c == EOF)
		return 0;

	str = va_arg(*args, char *);
	while (c != EOF && !isspace(c))
	{
		*str++ = c;
		count++;
		c = fgetc(stdin);
	}

	if (count == 0)
		return 0;
	*str = '\0';
	if (c != EOF)
		ungetc(c, stdin);
	return 1;
}

static int read_char(va_list *args)
{
	int c = fgetc(stdin);
	if (c == EOF)
		return 0;
	*(va_arg(*args, char *)) = c;
	return 1;
}

static int handle_whitespace(void)
{
	int c;
	while ((c = fgetc(stdin)) != EOF && isspace(c))
		;
	if (c != EOF)
		ungetc(c, stdin);
	return 1;
}

static int handle_literal(char expected)
{
	int c = fgetc(stdin);
	if (c != expected)
	{
		if (c != EOF)
			ungetc(c, stdin);
		return 0;
	}
	return 1;
}

int ft_scanf(const char *str, ...)
{
	va_list args;
	int count = 0;

	va_start(args, str);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd')
			{
				if (!read_int(&args))
				{
					va_end(args);
					return count;
				}
				count++;
			}
			if (*str == 's')
			{
				if (!read_string(&args))
				{
					va_end(args);
					return count;
				}
				count++;
			}
			if (*str == 'c')
			{
				if (!read_char(&args))
				{
					va_end(args);
					return count;
				}
				count++;
			}
		}
		if (*str != '%' && isspace(*str))
		{
			handle_whitespace();
		}
		if (*str != '%' && !isspace(*str))
		{
			if (!handle_literal(*str))
			{
				va_end(args);
				return count;
			}
		}
		str++;
	}

	va_end(args);
	return count;
}
