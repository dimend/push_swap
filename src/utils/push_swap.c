/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/17 19:42:04 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void set_closest(t_list *b, t_list *a)
{
    while (b)
    {
        b->closest = get_min_diff(b, a);
        b = b->next;
    }
}

void set_index(t_list *lst)
{
    int index;
    int lstsize;
    t_list *temp;
    t_list *max_node;

    index = 1;
    lstsize = ft_lstsize(lst);
    while (index <= lstsize)
    {
        temp = lst;
        max_node = NULL;
        while (temp)
        {
            if (temp->index == 0 && (max_node == NULL || temp->content < max_node->content))
                max_node = temp;
            temp = temp->next;
        }
        if (max_node != NULL)
        {
            max_node->index = index;
            index++;
        }
    }
}

void set_costtotop(t_list *a, t_list *b)
{
    calc_costtotop(a, ft_lstsize(a));
    calc_costtotop(b, ft_lstsize(b));
}

void final_sort(t_list **a)
{
    t_list *current;

    set_costtotop(*a, NULL);
    
    current = *a;
    while (current && current->index != 1) 
        current = current->next;

    send_to_top(current, a, 'a');
    if(current->reverse == 1)
        rotatelist(a, current->reverse, 'a');
}

