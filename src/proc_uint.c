#include "../includes/ft_printf.h"

static int	uint_helper(char *s, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
		len += ft_width(flags.dot - 1, ft_strlen(s) - 1, 1);
	len += ft_proc_putstr(s, ft_strlen(s));
	return (len);
}

int	proc_uint(unsigned int uint, t_flags flags)
{
	char	*s;
	int		len;

	len = 0;
	uint = (unsigned int)(4294967295 + 1 + uint);
	if (uint == 0 && flags.dot == 0)
		return (len += ft_width(flags.width, 0, 0));
	s = ft_unitoa(uint);
	if (flags.minus == 1)
		len += uint_helper(s, flags);
	if (flags.dot >= 0 && ((size_t)flags.dot < ft_strlen(s)))
		flags.dot = ft_strlen(s);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		len += ft_width(flags.width, 0, 0);
	}
	else
		len += ft_width(flags.width, ft_strlen(s), flags.zero);
	if (flags.minus == 0)
		len += uint_helper(s, flags);
	free (s);
	return (len);
}
