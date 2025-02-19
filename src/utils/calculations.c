/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:16:40 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:14 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_diff(t_list *b, t_list *a)
{
	int	diff;
	int	min_diff;
	int	closest_index;

	min_diff = INT_MAX;
	closest_index = 0;
	while (a)
	{
		diff = a->index - b->index;
		if (abs(diff) < min_diff)
		{
			min_diff = abs(diff);
			closest_index = a->index;
		}
		a = a->next;
	}
	return (closest_index);
}

void	calc_costtotop(t_list *lst, int lstsize)
{
	int	cost;

	cost = 0;
	while (lst)
	{
		if ((cost - 1) < lstsize / 2)
		{
			lst->costtotop = cost;
			lst->reverse = 0;
		}
		else
		{
			lst->costtotop = lstsize - cost - 1;
			lst->reverse = 1;
		}
		cost++;
		lst = lst->next;
	}
}

int	calc_cheapest(t_list *a, t_list *b)
{
	int		temp_cost;
	t_list	*temp_b;
	int		current_cost;

	temp_cost = INT_MAX;
	temp_b = b;
	while (temp_b)
	{
		if ((temp_b->index == a->closest) || (a->index == 1 && a->costtotop == 0
				&& a->reverse == 0))
		{
			current_cost = a->costtotop + temp_b->costtotop;
			if (a->reverse == temp_b->reverse && a->costtotop >= 1
				&& temp_b->costtotop >= 1)
				current_cost--;
			if (current_cost < temp_cost)
				temp_cost = current_cost;
		}
		temp_b = temp_b->next;
	}
	return (temp_cost);
}

t_list	*find_cheapest(t_list *a, t_list *b)
{
	t_list	*cheapest_node;
	int		temp_cost;
	int		min_cost;

	min_cost = INT_MAX;
	cheapest_node = NULL;
	while (a)
	{
		temp_cost = calc_cheapest(a, b);
		if (temp_cost < min_cost)
		{
			min_cost = temp_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	return (cheapest_node);
}

int	is_avg(t_list *a)
{
	int	avg;
	int	total;

	total = 0;
	avg = 0;
	while (a)
	{
		avg = avg + a->index;
		total++;
		a = a->next;
	}
	return (avg / total);
}
