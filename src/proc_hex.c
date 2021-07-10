#include "../includes/ft_printf.h"

static int	hex_helper(char *s, t_flags flags)
{
	int	len;

	len = 0;
	if (flags.dot >= 0)
		len += ft_width(flags.dot - 1, ft_strlen(s) - 1, 1);
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

static char	*itoa_healper(unsigned long ul, int capitals, char *s, int count)
{
	if (capitals == 1)
	{
		while (ul != 0)
		{
			if (ul % 16 < 10)
				s[count] = ul % 16 + 48;
			else
				s[count] = ul % 16 + 87;
			ul /= 16;
			count--;
		}
	}
	else
	{
		while (ul != 0)
		{
			if (ul % 16 < 10)
				s[count] = ul % 16 + 48;
			else
				s[count] = ul % 16 + 55;
			ul /= 16;
			count--;
		}
	}
	return (s);
}

static char	*itoa_base(unsigned long ul, int capitals)
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
	s = itoa_healper(ul, capitals, s, count);
	return (s);
}

int	proc_hex(unsigned int uint, int capitals, t_flags flags)
{
	char	*s;
	int		len;

	len = 0;
	uint = (unsigned int)(4294967295 + 1 + uint);
	if (flags.dot == 0 && uint == 0)
		return (len += ft_width(flags.width, 0, 0));
	s = itoa_base(uint, capitals);
	if (flags.minus == 1)
		len += hex_helper(s, flags);
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
		len += hex_helper(s, flags);
	free (s);
	return (len);
}
