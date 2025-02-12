CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I../includes

TARGET = ../checker

OBJ_PATH = obj/

SRCS = 	main.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		../src/utils/push_swap.c \
		../src/utils/libft/ft_atoi.c \
		../src/utils/libft/ft_lstadd_back_bonus.c \
		../src/utils/libft/ft_lstclear_bonus.c \
		../src/utils/libft/ft_lstadd_front_bonus.c \
		../src/utils/libft/ft_lstnew_bonus.c \
		../src/utils/libft/ft_lstsize_bonus.c \
		../src/utils/libft/ft_putchar_fd.c \
		../src/utils/libft/ft_putstr_fd.c \
		../src/utils/libft/ft_putnbr_fd.c \
		../src/utils/libft/ft_strlen.c \
		../src/utils/ft_printf/ft_printf.c \
		../src/utils/calculations.c \
		../src/utils/push_swap_controls.c \
		../src/utils/rotations_handler.c \
		../src/utils/sorting.c \
		../src/utils/validations.c

OBJS = $(SRCS:%.c=$(OBJ_PATH)%.o)

HEADERS = ../includes/libft.h

$(OBJ_PATH)%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
