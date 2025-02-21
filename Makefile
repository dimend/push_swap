CC = cc

CFLAGS = -Wall -Wextra -Werror -g -I./includes -I./

TARGET = push_swap
CHECKER = checker

OBJ_PATH = obj/

SRCS = src/main.c \
       src/utils/push_swap.c \
       src/utils/libft/ft_atoi.c \
       src/utils/libft/ft_lstadd_back_bonus.c \
       src/utils/libft/ft_lstclear_bonus.c \
       src/utils/libft/ft_lstadd_front_bonus.c \
       src/utils/libft/ft_lstnew_bonus.c \
       src/utils/libft/ft_lstsize_bonus.c \
       src/utils/libft/ft_putchar_fd.c \
       src/utils/libft/ft_putstr_fd.c \
       src/utils/libft/ft_putnbr_fd.c \
       src/utils/libft/ft_strlen.c \
       src/utils/ft_printf/ft_printf.c \
       src/utils/calculations.c \
       src/utils/push_swap_controls.c \
       src/utils/rotations_handler.c \
       src/utils/sorting.c \
       src/utils/validations.c

BONUS_SRCS = checker_bonus/main_bonus.c \
             checker_bonus/utils/push_swap_bonus.c \
             checker_bonus/utils/push_swap_controls_bonus.c \
             checker_bonus/utils/validations_bonus.c \
             checker_bonus/utils/libft/ft_atoi_bonus.c \
             checker_bonus/utils/libft/ft_lstadd_back_bonus.c \
             checker_bonus/utils/libft/ft_lstadd_front_bonus.c \
             checker_bonus/utils/libft/ft_lstclear_bonus.c \
             checker_bonus/utils/libft/ft_lstnew_bonus.c \
             checker_bonus/utils/libft/ft_strlen_bonus.c \
             checker_bonus/utils/sorting_bonus.c \
             checker_bonus/utils/gnl/get_next_line_bonus.c \
             checker_bonus/utils/gnl/get_next_line_utils_bonus.c

OBJS = $(SRCS:src/%.c=$(OBJ_PATH)%.o)
BONUS_OBJS = $(BONUS_SRCS:checker_bonus/%.c=$(OBJ_PATH)%.o)

HEADERS = includes/push_swap.h

$(OBJ_PATH)%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)gnl/%.o: checker_bonus/gnl/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: checker_bonus/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(CHECKER): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(CFLAGS) -o $(CHECKER)

bonus: $(CHECKER)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) -r $(OBJ_PATH)

fclean: clean
	rm -f $(TARGET) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
