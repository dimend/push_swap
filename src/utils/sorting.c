#include "libft.h"

void rotate_to_top(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	while ((node_a->costtotop > 0 && node_b->costtotop > 0) && node_a->reverse == node_b->reverse)
	{
		if (node_a->reverse == 0)
		{
			rotate_both(a, b, 0);
			node_a->costtotop--;
			node_b->costtotop--;
		}
		else
		{
			rotate_both(a, b, 1);
			node_a->costtotop--;
			node_b->costtotop--;
		}
	}
	while(node_a->costtotop != 0)
	{
		rotatelist(a, node_a->reverse, 'a');
		node_a->costtotop--;
	}
	while(node_b->costtotop != 0)
	{
		rotatelist(b, node_b->reverse, 'b');
		node_b->costtotop--;
	}
}

short int is_sorted(t_list *stack)
{
	while(stack && stack->next)
	{
		if(stack->content > stack->next->content)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

void small_sort(t_list **stack)
{
	while(is_sorted(*stack) != 1)
	{
		if(ft_lstsize(*stack) == 2)
		{
			if((*stack)->content > (*stack)->next->content)
				swapfirsttwo(stack, 'a');
		}
		else
		{
			if(((*stack)->next->content > (*stack)->content) 
			&& ((*stack)->next->content > (*stack)->next->next->content))
			{
				if((*stack)->content < (*stack)->next->next->content)
					swapfirsttwo(stack, 'a');
				else
					rotatelist(stack, 1, 'a');
			}
			if(((*stack)->content > (*stack)->next->content) 
			&& ((*stack)->content > (*stack)->next->next->content))
				rotatelist(stack, 0, 'a');
			if(((*stack)->content > (*stack)->next->content))
				swapfirsttwo(stack, 'a');
		}
	}
}

void sort_to_b(t_list **a, t_list **b)
{
	t_list *temp_a;
	t_list *temp_b;
	int cheapest;

	while(ft_lstsize(*a) > 3 && ft_lstsize(*b) < 2)
		pushfirst(a, b, 'b');
		
	set_closest(*a, *b);
	set_costtotop(*a, *b);
	temp_a = *a;
	temp_b = *b;
	cheapest = find_cheapest(temp_a, temp_b);
	while (temp_a->index != cheapest)
		temp_a = temp_a->next;
	if (temp_a->closest != 1 && temp_a->index != 1)
	{
		while (temp_b->index != temp_a->closest)
			temp_b = temp_b->next;
	}
	rotate_to_top(temp_a, temp_b, a, b);
	if ((temp_a->costtotop == 0 && temp_b->costtotop == 0) && ft_lstsize(*a) > 3)
	{
		pushfirst(a, b, 'b');
		set_costtotop(*a, *b);
	}
}

void sort_to_a(t_list **a, t_list **b)
{
	t_list *lowest_diff;

	lowest_diff = find_lowest_diff(a, b);
	set_costtotop(*a, *b);
	while(lowest_diff->costtotop > 0)
	{
		rotatelist(a, lowest_diff->reverse, 'a');
		lowest_diff->costtotop--;
	}
	if((*b)->index > (*a)->index)
	{
		pushfirst(b, a, 'a');
		swapfirsttwo(a, 'a');
	}
	else
		pushfirst(b, a, 'a');
}
