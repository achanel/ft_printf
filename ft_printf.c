#include "includes/ft_printf.h"
#include <stdio.h>

t_flags	ft_init_falgs(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.star = 0;
	return (flags);
}

int	ft_parse_format(char *format, va_list args)
{
	int		len;
	int		i;
	t_flags	flags;

	i = 0;
	len = 0;
	while (1)
	{
		flags = ft_init_falgs();
		if (!format[i])
			break ;
		else if (format[i] == '%' && format[i + 1])
		{
			i = parse_flags(format, ++i, &flags, args);
			if (type_list(format[i]))
				len += proc_types((char)flags.type, flags, args);
			else if (format[i])
				len += ft_proc_putchar(format[i]);
		}
		else if (format[i] != '%')
			len += ft_proc_putchar(format[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	len += ft_parse_format((char *)format, args);
	va_end(args);
	return (len);
}
