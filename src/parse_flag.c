#include "../includes/ft_printf.h"

t_flags	flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (10 * flags.width) + (c - '0');
	return (flags);
}

t_flags	flag_width(va_list args, t_flags flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

t_flags	flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

int	flag_dot(char *format, int a, t_flags *flags, va_list args)
{
	int	i;

	i = a;
	i++;
	if (format[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(format[i]))
			flags->dot = (10 * flags->dot) + (format[i++] - '0');
	}
	return (i);
}

int	parse_flags(char *format, int i, t_flags *flags, va_list args)
{
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !flag_list(format[i])
			&& !type_list(format[i]))
			break ;
		if (format[i] == '0' && !flags->width && !flags->minus)
			flags->zero = 1;
		if (format[i] == '.')
			i = flag_dot(format, i, flags, args);
		if (format[i] == '-')
			*flags = flag_minus(*flags);
		if (format[i] == '*')
			*flags = flag_width(args, *flags);
		if (ft_isdigit(format[i]))
			*flags = flag_digit(format[i], *flags);
		if (type_list(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	if (flags->type == 0)
		return (0);
	return (i);
}
