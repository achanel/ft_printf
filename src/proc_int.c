#include "../includes/ft_printf.h"

static int	int_helper(char *s, t_flags flags, int buf_int)
{
	int	len;

	len = 0;
	if (buf_int < 0 && flags.dot >= 0 && buf_int > -2147483648)
		ft_proc_putchar('-');
	if (flags.dot >= 0)
		len += ft_width(flags.dot - 1, ft_strlen(s) - 1, 1);
	len += ft_proc_putstr(s, ft_strlen(s));
	return (len);
}

static int	int_string(char *s, int buf_int, t_flags flags, int len)
{
	if (buf_int == -2147483648 && (flags.zero == 1 || flags.dot >= 0))
		len--;
	if (flags.minus == 1)
		len += int_helper(s, flags, buf_int);
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
		len += int_helper(s, flags, buf_int);
	return (len);
}

int	proc_int(int integer, t_flags flags)
{
	char	*s;
	int		len;
	int		buf_int;

	buf_int = integer;
	len = 0;
	if (flags.dot == 0 && integer == 0)
		return (len += ft_width(flags.width, 0, 0));
	if (integer < 0 && (flags.zero == 1 || flags.dot >= 0))
	{
		if (flags.zero == 1 && flags.dot < 0 && buf_int > -2147483648)
			ft_proc_putchar('-');
		if (buf_int == -2147483648)
			flags.width++;
		integer *= -1;
		flags.zero = 1;
		flags.width -= 1;
		len++;
	}
	s = ft_itoa(integer);
	len = int_string(s, buf_int, flags, len);
	free (s);
	return (len);
}
