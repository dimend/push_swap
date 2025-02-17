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
        if ((args_str[i] < '0' || args_str[i] > '9') && (args_str[i] != ' ' && args_str[i] != '-'))
            return (0);
        if(args_str[i] == ' ' && args_str[i] == '-')
            return (0);
        i++;
    }
    return (1);
}

char *ft_strcat(char *src, const char *new, size_t size_src, size_t size_new, short int last_arg)
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
