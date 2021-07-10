#include "../includes/ft_printf.h"

int	ft_proc_putstr(char *s, int i)
{
	int	len;

	len = 0;
	while (len < i && s[len])
		ft_proc_putchar(s[len++]);
	return (len);
}
