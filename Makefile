CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I./includes

TARGET = push_swap

SRCS =	src/push_swap.c \
	src/utils/libft/ft_atoi.c \
	src/utils/libft/ft_lstadd_back_bonus.c \
	src/utils/libft/ft_lstclear_bonus.c \
	src/utils/libft/ft_lstadd_front_bonus.c \
	src/utils/libft/ft_lstnew_bonus.c \
	src/utils/libft/ft_lstsize_bonus.c \
	src/utils/libft/ft_putchar_fd.c \
	src/utils/libft/ft_putstr_fd.c \
	src/utils/libft/ft_putnbr_fd.c \
	src/utils/ft_printf/ft_printf.c \
	src/utils/calculations.c \
	src/utils/push_swap_controls.c \
	src/utils/sorting.c

OBJS = $(SRCS:.c=.o)

HEADERS = includes/libft.h

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: 
	rm -f $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
