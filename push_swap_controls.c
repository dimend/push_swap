/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_controls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:12 by dimendon          #+#    #+#             */
/*   Updated: 2024/12/11 20:02:05 by dimendon         ###   ########.fr       */
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

// Send 1st element to the top of the other stack.
void sendfirst(t_list **srclst, t_list **destlst)
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

// // Shift up/down all elements of stack by 1.
// void upelements()
// {

// }
