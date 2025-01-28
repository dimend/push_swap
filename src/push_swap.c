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

void set_closest(t_list *a, t_list *b)
{
    int closest_index;

    closest_index = 0;
    while (a)
    {
        closest_index = get_min_diff(a, b);
        if (closest_index == 0)
            closest_index = 1;
        a->closest = closest_index;
        a = a->next;
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

    while (current->costtotop > 0)
    {
        rotatelist(a, current->reverse, 'a');
        current->costtotop--;
    }
}

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    t_list *new_number;
    int i;

    i = 1;
    while (i < argC)
    {
        new_number = ft_lstnew(ft_atoi(argV[i]));
        ft_lstadd_back(&a, new_number);
        i++;
    }
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
    ft_lstclear(&a);
}
