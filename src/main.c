#include "libft.h"

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    
    initialize_list(argC, argV, &a);
    if(check_duplicates(a) == 1)
        ft_printf("Error\n");
    else
    {
        if (ft_lstsize(a) < 4)
            small_sort(&a);
        else
        {
            if(is_sorted(a) == 0)
            {
                set_index(a);
                sort_to_b(&a, &b);
                sort_to_a(&a, &b);
                final_sort(&a);
            }
        }
    }
    ft_lstclear(&a);
}
