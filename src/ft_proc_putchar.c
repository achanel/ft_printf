#include "../includes/ft_printf.h"

int	ft_proc_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
