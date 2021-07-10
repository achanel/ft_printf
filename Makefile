LIBFT = ./libft/libft.a

NAME	= libftprintf.a

SRCS	= ft_printf.c src/ft_healper.c src/ft_proc_putchar.c src/ft_proc_putstr.c\
src/ft_width.c src/parse_flag.c src/proc_char.c src/proc_string.c src/proc_int.c\
src/proc_precent.c src/proc_types.c src/proc_pointer.c src/proc_uint.c src/proc_hex.c

PF_OBJS	= ft_healper.o ft_proc_putchar.o ft_proc_putstr.o\
ft_width.o parse_flag.o proc_char.o proc_string.o proc_int.o\
proc_precent.o proc_types.o proc_pointer.o proc_uint.o proc_hex.o

INCLUDES = includes/

OBJS	= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS	= -c -Wall -Wextra -Werror

$(NAME):	$(OBJS)
			$(MAKE) bonus -C ./libft
			cp libft/libft.a $(NAME)
			$(CC) $(CFLAGS) -I$(INCLUDES) $(SRCS)
			ar -rcs $(NAME) $(OBJS)
		
all:		$(NAME)

clean:				
					$(MAKE) clean -C ./libft
					${RM} $(PF_OBJS)
					${RM} ${OBJS} 

fclean:		clean
			$(MAKE) fclean -C ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus