NAME = push_swap
CC = cc
CCFLAGS = -Wall -Wextra -Werror -c
INCLUDES = -I includes
SRC = $(addprefix src/, main.c sorting_a.c sorting_b.c) \
	$(addprefix utils/, algo_utils.c node_management.c utils.c) \
	$(addprefix instructions/, push_funcs.c revrotation_funcs.c rotation_funcs.c swap_funcs.c)
OBJ_PATH = obj/
OBJ = $(SRC:%.c=$(OBJ_PATH)%.o)
LIBFT_PATH = libft/
LIBFT = -L$(LIBFT_PATH) -lft

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: %.c | $(OBJ_PATH)
	mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ) $(LIBFT_PATH)libft.a
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT_PATH)libft.a:
	$(MAKE) -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re