NAME = printf.a
SRCS = ft_printf.c ft_putcas.c ft_hexa.c ft_itoa.c ft_printf_adr.c ft_putnbru.c 

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *.o

re: fclean all

.PHONY: all clean fclean re
