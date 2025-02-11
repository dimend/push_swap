#include "libft.h"

char	*ft_strcat(char *src, const char *new, size_t size_src, size_t size_new, short int last_arg)
{
    char	*newdata;
    size_t	i;

    newdata = NULL;
    i = 0;
    newdata = malloc(size_src + size_new + (size_t)last_arg);
    if (!newdata)
        return (NULL);
    while (i < size_src)
    {
        newdata[i] = src[i];
        i++;
    }
    i = 0;
    while (i < size_new)
    {
        newdata[size_src + i] = new[i];
        i++;
    }
    if (last_arg == 2)
        newdata[size_src + size_new] = ' ';
    newdata[size_src + size_new + (last_arg - 1)] = '\0';
	free(src);
	return (newdata);
}

char *concat_args(char *argV[], int argC)
{
    int i;
    short int last_arg;
    char *args_str;

    last_arg = 2;
    i = 1;
    args_str = malloc(1);
    if (!args_str)
		return (NULL);
    args_str[0] = '\0';
    while (i < argC)
    {
        if(i == argC - 1)
            last_arg = 1;
        args_str = ft_strcat(args_str, argV[i], ft_strlen(args_str), ft_strlen(argV[i]), last_arg);
        i++;
    }
    return (args_str);
}

char *ft_strtok(char *str, const char delim)
{
    static char *input;
    char *start;

    if (str)
        input = str;
    if (!input)
        return NULL;
    
    while (*input != '\0' && *input == delim)
        input++;
    if (*input == '\0')
        return NULL;
    start = input;
    while (*input != '\0' && *input != delim)
        input++;
    if (*input == delim)
    {
        *input = '\0';
        input++;
    }
    if (*input == '\0')
        input = NULL;
    return start;
}

void sort(t_list **a, t_list **b)
{
    set_index(*a);
    sort_to_b(a, b);
    sort_to_a(a, b);
    final_sort(a);
}

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    char *args_str = NULL;

    args_str = concat_args(argV, argC);
    if (validate_args(args_str) == 0)
        ft_printf("Error\n");
    else
    {
        initialize_list(args_str, &a);
        if (check_duplicates(a) == 1)
            ft_printf("Error\n");
        else
        {
            if (ft_lstsize(a) < 4)
                small_sort(&a);
            else
            {
                if (is_sorted(a) == 0)
                    sort(&a, &b);
            }
        }
    }
    free(args_str);
    ft_lstclear(&a);
}
