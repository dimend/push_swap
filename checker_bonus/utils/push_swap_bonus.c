/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/17 19:27:33 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

short int initialize_list(char *args, t_list **a)
{
    t_list *new_number;
    char *arg = NULL;

    arg = ft_strtok(args, ' ');
    while(arg != NULL)
    {
        new_number = ft_lstnew(ft_atoi(arg));
        if(new_number == NULL)
            return (1);
        ft_lstadd_back(a, new_number);
        arg = ft_strtok(NULL, ' ');
    }
    return (0);
}

