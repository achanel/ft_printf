#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			star;
	int			already_print;
}				t_flags;

int		ft_printf(const char *format, ...);

int		ft_parse_format(char *format, va_list args);
int		ft_proc_putchar(char c);
int		ft_proc_putstr(char *s, int i);
int		proc_types(char c, t_flags flags, va_list args);

int		flag_list(int i);
int		type_list(int i);
char	*ft_unitoa(unsigned int uint);

int		parse_flags(char *format, int i, t_flags *flags, va_list args);
int		flag_dot(char *format, int a, t_flags *flags, va_list args);
t_flags	flag_minus(t_flags flags);
t_flags	flag_width(va_list args, t_flags flags);
t_flags	flag_digit(char c, t_flags flags);

int		ft_width(int width, int minus, int zero);
int		proc_precent(t_flags flags);
int		proc_char(int c, t_flags flags);
int		proc_string(char *s, t_flags flags);
int		proc_int(int integer, t_flags flags);
int		proc_pointer(unsigned long ul, t_flags flags);
int		proc_uint(unsigned int uint, t_flags flags);
int		proc_hex(unsigned int uint, int capitals, t_flags flags);

#endif