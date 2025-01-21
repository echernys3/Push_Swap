CC = cc
CCFLAGS = -Wall -Wextra -Werror -c
SRC = src/algo_utils.c src/main.c src/sorting_a.c src/sorting_b.c
utils/node_management.c utils/utils.cc instructions/push_funcs.c instructions/revrotation_funcs.c instructions/rrr_funcs.cc instructions/swap_funcs.c
OBJ = $(SRC:.c.o)

