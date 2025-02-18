#include "libft.h"

int count_max_digits()
{
    int max_int;
    int max_int_digits;

    max_int = INT_MAX;
    max_int_digits = 0;
    while(max_int != 0)
    {
        max_int /= 10;
        max_int_digits++;
    }

    return (max_int_digits);
}

void sort(t_list **a, t_list **b)
{
    set_index(*a);
    sort_to_b(a, b);
    sort_to_a(a, b);
    final_sort(a);
}

void free_all(t_list **a, t_list **b)
{
    ft_lstclear(a);
    ft_lstclear(b);
}

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    char *args_str = NULL;

    args_str = concat_args(argV, argC);
    if (validate_args(args_str) == 1)
        ft_printf("Error\n");
    else
    {
        if (initialize_list(args_str, &a) == 1 || check_duplicates(a) == 1)
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
    free_all(&a, &b);
}
