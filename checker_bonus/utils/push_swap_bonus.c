/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/17 15:31:22 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void initialize_list(char *args, t_list **a)
{
    t_list *new_number;
    char *arg = NULL;

    arg = ft_strtok(args, ' ');
    while(arg != NULL)
    {
        new_number = ft_lstnew(ft_atoi(arg));
        ft_lstadd_back(a, new_number);
        arg = ft_strtok(NULL, ' ');
    }
}

