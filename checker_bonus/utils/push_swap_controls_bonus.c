/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_controls_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:12 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/21 16:53:43 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	swapfirsttwo(t_list **lst)
{
	t_list	*aux;

	aux = *lst;
	if (lst && (*lst)->next)
	{
		*lst = (*lst)->next;
		aux->next = (*lst)->next;
		(*lst)->next = aux;
	}
}

void	pushfirst(t_list **srclst, t_list **destlst)
{
	t_list	*first;

	if (*srclst)
	{
		first = *srclst;
		*srclst = first->next;
		first->next = *destlst;
		*destlst = first;
	}
}

void	rotatelist(t_list **srclst, short int direction)
{
	t_list	*last;
	t_list	*second_last;

	if (*srclst == NULL || (*srclst)->next == NULL)
		return ;
	second_last = NULL;
	last = *srclst;
	if (direction == 0)
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

void	rotate_both(t_list **a, t_list **b, short int direction)
{
	rotatelist(a, direction);
	rotatelist(b, direction);
}

void	swap_both(t_list **a, t_list **b)
{
	swapfirsttwo(a);
	swapfirsttwo(b);
}
