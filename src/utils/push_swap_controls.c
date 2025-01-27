/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:12 by dimendon          #+#    #+#             */
/*   Updated: 2024/12/23 16:08:54 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void swapfirsttwo(t_list **lst, char listname)
{
    t_list *aux;

    aux = *lst;
    if(lst && (*lst)->next)
    {
        *lst = (*lst)->next;
        aux->next = (*lst)->next;
        (*lst)->next = aux;
    }
    ft_printf("s%c\n", listname);
}

void pushfirst(t_list **srclst, t_list **destlst, char listname)
{
    t_list *first;
    
    if (*srclst)
    {
        first = *srclst;
        *srclst = first->next;
        first->next = *destlst;
        *destlst = first;
    }
    ft_printf("p%c\n", listname);
}

void rotatelist(t_list **srclst, short int direction, char listname)
{
    t_list *last;
    t_list *second_last;

    if (*srclst == NULL || (*srclst)->next == NULL)
        return;
    second_last = NULL;
    last = *srclst;
    if (direction == 0)
    {
        if(listname != 'r') ft_printf("r%c\n", listname);
        ft_lstadd_back(srclst, last);
        *srclst = (*srclst)->next;
        last->next = NULL;
    }
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    if (direction == 1)
    {
        if(listname != 'r') ft_printf("rr%c\n", listname);
        second_last->next = NULL;
        ft_lstadd_front(srclst, last);
    }
}

void rotate_both(t_list **a, t_list **b, short int direction)
{
    rotatelist(a, direction, 'r');
    rotatelist(b, direction, 'r');
    if (direction == 1)
        ft_printf("rrr\n");
    else
        ft_printf("rr\n");
}

t_list *find_lowest_diff(t_list **a, t_list **b)
{
    t_list *lowest_diff;
    t_list *temp_a;
    int diff;
    int smallest_diff;

    diff = 0;
    smallest_diff = 2147483647;
    temp_a = *a;
    while (temp_a)
	{
		diff = (*b)->index - temp_a->index;
		if (abs(diff) < abs(smallest_diff))
		{
			smallest_diff = diff;
			lowest_diff = temp_a;
		}
		temp_a = temp_a->next;
	}
    return (lowest_diff);
}
