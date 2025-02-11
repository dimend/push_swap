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

short int validate_args(char *args_str)
{
    int i;

    i = 0; 
    while(args_str[i] != '\0')
    {
        if ((args_str[i] < '0' || args_str[i] > '9') && args_str[i] != ' ')
            return (0);
        if(args_str[i] == ' ')
        {
            if (args_str[i + 1] < '0' || args_str[i + 1] > '9')
                return (0);
        }
        i++;
    }
    return (1);
}
