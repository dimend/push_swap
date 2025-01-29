#include "libft.h"

void rotate_to_top(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	while ((node_a->costtotop > 0 && node_b->costtotop > 0)
			&& node_a->reverse == node_b->reverse)
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
	send_to_top(node_a, a, 'a');
	send_to_top(node_b, b, 'b');
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

	while(ft_lstsize(*a) > 3)
	{
		pushfirst(a, b, 'b');
	}
}

t_list *get_min(t_list **a)
{
    t_list *temp;
    t_list *min_node;
    int min;

    if (!a || !(*a))  // Handle empty list case
        return (NULL);

    temp = *a;
    min_node = temp;   // Initialize min_node to the first node
    min = temp->index; 

    while (temp)
    {
        if (temp->index < min)
        {
            min = temp->index;
            min_node = temp;
        }
        temp = temp->next;
    }
    return (min_node);
}


int b_new_highest(t_list *a, t_list *b)
{
    t_list *temp;

    if (!a || !b)
        return (0); // If A or B is empty, return false

    temp = a;
    while (temp)
    {
        if (b->index < temp->index)
            return (0); // If B's header is not higher than some A elements, return false
        temp = temp->next;
    }
    return (1); // If B's header is higher than all A elements, return true
}

void sort_to_a(t_list **a, t_list **b)
{
	t_list *lowest_diff;
	t_list *min;

	small_sort(a);
	while(ft_lstsize(*b) > 0)
	{
		set_costtotop(*a, *b);
		if(b_new_highest(*a,*b))
		{
			min = get_min(a);
			lowest_diff = min;
		}
		else
			lowest_diff = find_lowest_diff(a, b);

		ft_printf("%d\n",lowest_diff->index);
		ft_printf("%d\n",lowest_diff->costtotop);
		ft_printf("%d\n",lowest_diff->reverse);
		while(lowest_diff->costtotop > 1 && lowest_diff->reverse != 1)
		{
			rotatelist(a, lowest_diff->reverse, 'a');
			set_costtotop(*a,*b);
		}
			pushfirst(b, a, 'a');
	}
}
