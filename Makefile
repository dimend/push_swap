CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes

LIBFT = lib/libft.a lib/libftprintf.a

TARGET = push_swap

SRCS =	src/push_swap.c \
	src/utils/ft_lstnew_bonus.c \
	src/utils/push_swap_controls.c

OBJS = $(SRCS:.c=.o)

HEADERS = includes/libft.h

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L./lib -lft -lftprintf -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: 
	rm -f $(OBJS) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
