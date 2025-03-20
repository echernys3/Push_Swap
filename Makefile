# Variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -c -g
LIBFT_PATH = libft/
LIBFT_A = $(LIBFT_PATH)libft.a

# Source files and objects
SRC = $(addprefix src/, main.c push_swap.c radix.c) \
	$(addprefix utils/, args_utils.c exit.c index_utils.c list_utils.c more_list_utils.c ps_split.c) \
	$(addprefix instructions/, push_funcs.c revrotation_funcs.c rotation_funcs.c swap_funcs.c)
OBJ = $(SRC:.c=.o)
OBJ_DIR = obj/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJ))

# Dependency files
DEP = $(OBJ_FILES:.o=.d)

# Rules
all: $(NAME)

# Main target
$(NAME): $(OBJ_FILES) $(LIBFT_A)
	$(CC) $(OBJ_FILES) -o $(NAME) -L$(LIBFT_PATH) -lft

# Object files
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I includes -MMD -MP -c $< -o $@

# Include dependencies
-include $(DEP)

# Libft build only if needed
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_PATH) all

# Clean
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_PATH) clean

# Full clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Rebuild
re: fclean all

# .SILENT: fclean clean all
.PHONY: all clean fclean re