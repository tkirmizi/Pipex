.SILENT:

NAME = pipex
SRCS = pipex.c pipex_utils.c pipex_utils_2.c exit.c
OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT_OBJS = ./libft/libft.a

FT_PRINTF_PATH = ./printf
FT_PRINTF_OBJ = ./printf/printf.a

cc = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(LIBFT_OBJS):
	make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_OBJS) $(FT_PRINTF_OBJ) $(OBJS) 
	$(CC) $(CFLAGS) $(LIBFT_OBJS) $(FT_PRINTF_OBJ) $(OBJS) -o $(NAME)
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	@echo "\033[0;32mCompiled"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
fclean:
	$(RM) $(NAME)
	$(RM) $(OBJS)
	$(RM) $(LIBFT_OBJS)
re: fclean all