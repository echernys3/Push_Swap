NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
INCLUDES = -IPrintf -ILibft
PRINTF_SRC = $(addprefix Printf/, ft_printf_utils.c ft_print_hex.c ft_print_ptr.c \
		ft_print_unsigned.c ft_printf.c)
LIBFT_SRC = $(addprefix Libft/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_bzero.c ft_toupper.c ft_tolower.c ft_atoi.c ft_substr.c\
		ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_strdup.c ft_calloc.c ft_strmapi.c\
		ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c)
OBJ_PATH = obj/
PRINTF_OBJ = $(PRINTF_SRC:Printf/%.c=$(OBJ_PATH)Printf/%.o)
LIBFT_OBJ = $(LIBFT_SRC:Libft/%.c=$(OBJ_PATH)Libft/%.o)
OBJS = $(PRINTF_OBJ) $(LIBFT_OBJ)
DEPS = $(OBJS:.o=.d)

# Default target
all: $(NAME)

# Create object folders
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)Printf $(OBJ_PATH)Libft

# Compile .c -> .o with dependencies
$(OBJ_PATH)Printf/%.o: Printf/%.c | $(OBJ_PATH)
	$(CC) $(CCFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(OBJ_PATH)Libft/%.o: Libft/%.c | $(OBJ_PATH)
	$(CC) $(CCFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Archive to libft.a
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

# Clean .o files (keep dependencies unless fclean)
clean:
	rm -rf $(OBJ_PATH)

# Full clean including libft.a
fclean: clean
	rm -f $(NAME)

# Proper re: clean everything, then rebuild
re: fclean all

-include $(DEPS)

# Phony rules
.PHONY: all clean fclean re
