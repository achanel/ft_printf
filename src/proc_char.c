#include "../includes/ft_printf.h"

int	proc_char(int c, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.minus == 1)
		ft_proc_putchar(c);
	len += ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_proc_putchar(c);
	return (len + 1);
}
