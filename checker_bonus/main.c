#include "ft_get_next_line/get_next_line.h"
#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}

void execute_command(char *command, t_list **a, t_list **b)
{
        if (ft_strncmp(command, "sa", 2) == 0)
            swapfirsttwo(a, '\0');
        else if (ft_strncmp(command, "sb", 2) == 0)
            swapfirsttwo(b, '\0');
        else if (ft_strncmp(command, "pa", 2) == 0)
            pushfirst(b, a, '\0');
        else if (ft_strncmp(command, "pb", 2) == 0)
            pushfirst(a, b, '\0');
        else if (ft_strncmp(command, "ra", 2) == 0)
            rotatelist(a, 0, '\0');
        else if (ft_strncmp(command, "rb", 2) == 0)
            rotatelist(b, 0, '\0');
        else if (ft_strncmp(command, "rra", 3) == 0)
            rotatelist(a, 1, '\0');
        else if (ft_strncmp(command, "rrb", 3) == 0)
            rotatelist(b, 1, '\0');
        else if (ft_strncmp(command, "rr", 2) == 0)
            rotate_both(a, b, 0, '\0');
        else if (ft_strncmp(command, "rrr", 3) == 0)
            rotate_both(a, b, 1, '\0');
}

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    char *args_str = NULL;
    char *command;

    args_str = concat_args(argV, argC);
    if (validate_args(args_str) == 0)
        ft_printf("Error\n");
    else
        initialize_list(args_str, &a);
    while ((command = get_next_line(0)) != NULL)
    {
        execute_command(command, &a, &b);
        free(command);
    }
    if (is_sorted(a) && b == NULL)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    free(args_str);
    ft_lstclear(&a);
    ft_lstclear(&b);
    return 0;
}
