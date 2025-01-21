CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I./includes

LIBFT = lib/libftprintf.a

TARGET = push_swap

SRCS =	src/push_swap.c \
	src/utils/ft_atoi.c \
	src/utils/ft_lstadd_back_bonus.c \
	src/utils/ft_lstadd_front_bonus.c \
	src/utils/ft_lstnew_bonus.c \
	src/utils/ft_lstsize_bonus.c \
	src/utils/push_swap_controls.c \
	src/utils/sorting.c

OBJS = $(SRCS:.c=.o)

HEADERS = includes/libft.h

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./lib -lftprintf -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: 
	rm -f $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
