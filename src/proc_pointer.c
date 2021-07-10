#include "../includes/ft_printf.h"

static int	poingter_helper(char *s, t_flags flags)
{
	int	len;

	len = 0;
	len += ft_proc_putstr("0x", 2);
	if (flags.dot >= 0)
	{
		len += ft_width(flags.width, ft_strlen(s), 1);
		len += ft_proc_putstr(s, flags.dot);
	}
	else
		len += ft_proc_putstr(s, ft_strlen(s));
	return (len);
}

static int	base_healper(unsigned long ul)
{
	int	len;

	len = 0;
	while (ul != 0)
	{
		ul /= 16;
		len++;
	}
	return (len);
}

static char	*itoa_base(unsigned long ul)
{
	int					count;
	char				*s;
	unsigned long long	buf_ul;

	count = 0;
	buf_ul = ul;
	s = 0;
	if (ul == 0)
		return (ft_strdup("0"));
	count = base_healper(ul);
	s = malloc(sizeof(s) * (count + 1));
	if (!s)
		return (NULL);
	s[count] = '\0';
	count--;
	while (ul != 0)
	{
		if (ul % 16 < 10)
			s[count] = ul % 16 + 48;
		else
			s[count] = ul % 16 + 87;
		ul /= 16;
		count--;
	}
	return (s);
}

int	proc_pointer(unsigned long ul, t_flags flags)
{
	char	*s;
	int		len;

	len = 0;
	if (ul == 0 && flags.dot >= 0)
	{
		s = "0x";
		len += ft_proc_putstr(s, 2);
		len += ft_width(flags.width, ft_strlen(s), flags.zero);
		if (flags.dot > 0)
			len += ft_width(flags.dot, 0, 1);
		return (len);
	}
	s = itoa_base(ul);
	if ((size_t)flags.dot < ft_strlen(s))
		flags.dot = ft_strlen(s);
	if (flags.minus == 1)
		len += poingter_helper(s, flags);
	len += ft_width(flags.width, ft_strlen(s) + 2, 0);
	if (flags.minus == 0)
		len += poingter_helper(s, flags);
	free (s);
	return (len);
}
