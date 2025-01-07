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

// Swap the first 2 elements.
void swapfirsttwo(t_list **lst)
{
    t_list *aux;

    aux = *lst;
    if(lst && (*lst)->next)
    {
        *lst = (*lst)->next;
        aux->next = (*lst)->next;
        (*lst)->next = aux;
    }
}

// Push first element to the top of the other stack.
void pushfirst(t_list **srclst, t_list **destlst)
{
    t_list *first;
    
    if (*srclst)
    {
        first = *srclst;
        *srclst = first->next;
        first->next = *destlst;
        *destlst = first;
    }
}

// Shift positions by 1 either up or down.
void rotatelist(t_list **srclst, short int direction)
{
    t_list *last;
    t_list *second_last;

    if (*srclst == NULL || (*srclst)->next == NULL)
        return;

    second_last = NULL;
    last = *srclst;
    if (direction == -1)
    {
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
        second_last->next = NULL;
        ft_lstadd_front(srclst, last);
    }
}
