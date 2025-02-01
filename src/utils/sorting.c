#include "libft.h"

void rotate_to_top(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	while ((node_a->costtotop > 0 && node_b->costtotop > 0)
			&& node_a->reverse == node_b->reverse)
	{
		if (node_a->reverse == 0)
		{
			rotate_both(a, b, 0);
			set_costtotop(*a, *b);
		}
		else
		{
			rotate_both(a, b, 1);
			set_costtotop(*a, *b);
		}
	}
	if (handle_rotate_both(node_a, node_b, a, b))
		return;
	else
		handle_rotation(node_a, node_b, a, b);
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

	while(ft_lstsize(*a) > 3 && ft_lstsize(*b) < 2)
		pushfirst(a, b, 'b');
	while(ft_lstsize(*a) > 3)
	{
		set_closest(*a, *b);
		set_costtotop(*a, *b);
		temp_b = *b;
		temp_a = find_cheapest(*a, *b);
/* 		ft_printf("temp_a->index: %d\n", temp_a->index);
		ft_printf("temp_a->costtotop: %d\n", temp_a->costtotop);
		ft_printf("temp_a->reverse: %d\n", temp_a->reverse);
		ft_printf("temp_a->closest: %d\n", temp_a->closest); */
		while (temp_b->index != temp_a->closest)
				temp_b = temp_b->next;
/* 		ft_printf("temp_b->index: %d\n", temp_b->index);
		ft_printf("temp_b->costtotop: %d\n", temp_b->costtotop);
		ft_printf("temp_b->reverse: %d\n", temp_b->reverse); */
		rotate_to_top(temp_a, temp_b, a, b);
		if ((temp_a->costtotop == 0 && temp_b->costtotop == 0)
			&& ft_lstsize(*a) > 3)
			pushfirst(a, b, 'b');
	}
	small_sort(a);
}

void sort_to_a(t_list **a, t_list **b)
{
	t_list *lowest_diff;
	
	while(ft_lstsize(*b) > 0)
	{
		lowest_diff = find_lowest_diff(a, b);
		set_costtotop(*a, *b);

/* 		ft_printf("lowest_diff->index: %d\n", lowest_diff->index);
		ft_printf("lowest_diff->costtotop: %d\n", lowest_diff->costtotop);
		ft_printf("lowest_diff->reverse: %d\n", lowest_diff->reverse); */

		send_to_top(lowest_diff, a, 'a');
		if(lowest_diff->reverse == 1 && lowest_diff->costtotop == 0)
		{
			if((*b)->index < lowest_diff->index)
				rotatelist(a, 1, 'a');
		}
		if(lowest_diff->reverse == 0 && lowest_diff->costtotop == 0)
		{
			if((*b)->index > lowest_diff->index)
				rotatelist(a, lowest_diff->reverse, 'a');
		}
		pushfirst(b, a, 'a');
	}
}

