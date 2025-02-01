#include "libft.h"

short int check_duplicates(t_list *list)
{
    t_list *current;
    t_list *runner;

    current = list;
    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            if (current->content == runner->content)
                return 1;
            runner = runner->next;
        }
        current = current->next;
    }
    return 0;
}