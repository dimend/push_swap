#include "libft.h"

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
	int avg;
	int total;
	int i;

	avg = is_avg(*a);
	total = ft_lstsize(*a);
	i = 0;
	while (i < (total / 2))
	{
		if ((*a)->index <= avg)
		{
			pushfirst(a, b, 'b');
			i++;
		}
		else
			rotatelist(a, 0, 'a');
	}
	while (ft_lstsize(*a) > 3)
		pushfirst(a, b, 'b');

	small_sort(a);
}

void sort_to_a(t_list **a, t_list **b)
{
	t_list *temp_a;
	t_list *temp_b;
	int total;

	temp_a = *a;
	temp_b = *b;
	total = ft_lstsize(temp_b);

	while(total > 0)
	{
		set_closest(*b, *a);
		set_costtotop(*a, *b);
		temp_a = *a;
		temp_b = find_cheapest(*b, *a);
		while (temp_a->index != temp_b->closest)
				temp_a = temp_a->next;
		rotate_to_top(temp_a, temp_b, a, b);
		if (temp_a->costtotop == 0 && temp_b->costtotop == 0)
		{
			pushfirst(b, a, 'a');
			total--;
		}
			
	}
}

