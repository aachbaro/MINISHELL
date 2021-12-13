NAME = minishell
SRC = SRCS/main.c \

LIBFT = -L./LIBFT -lft
READLINE = -L/usr/local/lib -I/usr/local/include -lreadline
CC = gcc #clang
INC = -I./minishell.h
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -rf
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
	@$(MAKE) -C ./LIBFT
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBFT) $(READLINE)
all: $(NAME)
clean:
	@${RM} ${OBJ}
	@$(MAKE) clean -C ./LIBFT
	@$(MAKE) clean -C ./MLX
fclean: clean
	@$(MAKE) fclean -C ./LIBFT
	@${RM} ${SAVE}
	@${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re