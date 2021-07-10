#include "../includes/ft_printf.h"

int	proc_types(char c, t_flags flags, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = proc_char(va_arg(args, int), flags);
	if (c == 's')
		len = proc_string(va_arg(args, char *), flags);
	if (c == 'p')
		len = proc_pointer(va_arg(args, unsigned long), flags);
	if (c == 'd' || c == 'i')
		len = proc_int(va_arg(args, int), flags);
	if (c == 'u')
		len = proc_uint((unsigned int)va_arg(args, unsigned int), flags);
	if (c == 'x')
		len = proc_hex(va_arg(args, unsigned int), 1, flags);
	if (c == 'X')
		len = proc_hex(va_arg(args, unsigned int), 0, flags);
	if (c == '%')
		len = proc_precent(flags);
	return (len);
}
