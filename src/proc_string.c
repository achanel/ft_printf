#include "../includes/ft_printf.h"

static int	string_helper(char *s, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
	{
		len += ft_width(flags.dot, ft_strlen(s), 0);
		len += ft_proc_putstr(s, flags.dot);
	}
	else
		len += ft_proc_putstr(s, ft_strlen(s));
	return (len);
}

int	proc_string(char *s, t_flags flags)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(s))
		flags.dot = ft_strlen(s);
	if (flags.minus == 1)
		len += string_helper(s, flags);
	if (flags.dot >= 0)
		len += ft_width(flags.width, flags.dot, 0);
	else
		len += ft_width(flags.width, ft_strlen(s), flags.zero);
	if (flags.minus == 0)
		len += string_helper(s, flags);
	return (len);
}
