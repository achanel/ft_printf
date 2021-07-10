#include "../includes/ft_printf.h"

int	flag_list(int i)
{
	if ((i == '-') || (i == ' ') || (i == '0') || (i == '.') || (i == '*'))
		return (1);
	else
		return (0);
}

int	type_list(int i)
{
	if ((i == 'c') || (i == 's') || (i == 'p') || (i == 'd') || (i == 'i')
		|| (i == 'u') || (i == 'x') || (i == 'X') || (i == '%'))
		return (1);
	else
		return (0);
}

static int	num_count(long n)
{
	size_t	i;

	i = 0;
	if (n <= 0 )
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*int_to_str(long n, int count, char *str)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[count] = '\0';
	while (count)
	{
		str[--count] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ft_unitoa(unsigned int uint)
{
	char	*str;
	int		count;
	long	n;

	n = uint;
	count = num_count(n);
	str = malloc(count + 1);
	if (str == NULL)
		return (NULL);
	str = int_to_str(n, count, str);
	return (str);
}
