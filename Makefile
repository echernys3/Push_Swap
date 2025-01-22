NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror -c
INCLUDES = -I includes/push_swap.h
SRC = $(addprefix src/, )
OBJ = $(SRC:%.c=%.o)
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), )
LIBFT_PATH = libft/
LIBFT = -L$(LIBFT_PATH) -lft


all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC)
$(CC) $(CCFLAGS) $< -o $@ $(INCLUDES)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re