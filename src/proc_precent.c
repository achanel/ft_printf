#include "../includes/ft_printf.h"

int	proc_precent(t_flags flags)
{
	int		len;

	len = 0;
	if (flags.minus == 1)
		len += ft_proc_putchar('%');
	len += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		len += ft_proc_putchar('%');
	return (len);
}
