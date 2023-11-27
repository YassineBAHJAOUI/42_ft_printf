NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printer.c



OBJS = $(SRCS:.c=.o)

all:$(NAME)

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

$(NAME):$(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
