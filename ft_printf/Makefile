NAME = libftprintf.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror -c
AR = ar
ARFLAGS = rcs
SRC = ft_numlen.c ft_print_hex.c ft_print_ptr.c \
		ft_print_unsigned.c ft_printf.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm -f $(OBJ) *.gch
	
fclean: clean
	rm -f $(NAME)

re: fclean all