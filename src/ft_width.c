#include "../includes/ft_printf.h"

int	ft_width(int width, int minus, int zero)
{
	int	len;

	len = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_proc_putchar('0');
		else
			ft_proc_putchar(' ');
		width--;
		len++;
	}
	return (len);
}
