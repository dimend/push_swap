/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:12 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/17 16:22:50 by dimendon         ###   ########.fr       */
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
    if(listname != '\0')
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
    if(listname != '\0')
        ft_printf("p%c\n", listname);
}

void rotatelist(t_list **srclst, short int direction, char listname)
{
    t_list *last;
    t_list *second_last;

    second_last = NULL;
    last = *srclst;
    if (direction == 0)
    {
        if(listname != 'r' && listname != '\0')
            ft_printf("r%c\n", listname);
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
        if(listname != 'r' && listname != '\0')
            ft_printf("rr%c\n", listname);
        second_last->next = NULL;
        ft_lstadd_front(srclst, last);
    }
}

void rotate_both(t_list **a, t_list **b, short int direction, char listname)
{
    rotatelist(a, direction, listname);
    rotatelist(b, direction, listname);
    if (direction == 1 && listname != '\0')
        ft_printf("rrr\n");
    else
        ft_printf("rr\n");
}
