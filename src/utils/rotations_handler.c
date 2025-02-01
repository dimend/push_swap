#include "libft.h"

void handle_send_to_top(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	send_to_top(node_a, a, 'a');
	if ((node_a->costtotop == 0 && node_b->costtotop > 0) 
		&& node_a->reverse == 1 && node_b->reverse == 1)
	{
		rotate_both(a, b, 1);
		return;
	}
	if (node_a->reverse == 1)
		rotatelist(a, node_a->reverse, 'a');
	send_to_top(node_b, b, 'b');
}

void handle_rotation(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	if ((node_b->costtotop == 0 && node_a->costtotop > 0) 
		&& (node_a->reverse == 1 && node_b->reverse == 1))
	{
		rotate_both(a, b, 1);
		return;
	}
	else
	{
		if (node_a->index > node_b->index)
		{
			handle_send_to_top(node_a, node_b, a, b);
			if (node_b->reverse == 1)
				rotatelist(b, node_b->reverse, 'b');
		}
		else
		{
			handle_send_to_top(node_a, node_b, a, b);
			if (node_b->reverse == 0)
				rotatelist(b, node_b->reverse, 'b');
		}
	}
}

short int handle_rotate_both(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	if (node_a->index > node_b->index 
		&& ((node_b->costtotop == 0 && node_a->costtotop == 0) 
		&& (node_a->reverse == 1 && node_b->reverse == 1)))
	{
		rotate_both(a, b, 1);
		return (1);
	}
	if (node_a->index < node_b->index 
		&& ((node_b->costtotop == 0 && node_a->costtotop > 0) 
		&& (node_a->reverse == 0 && node_b->reverse == 0)))
	{
		rotate_both(a, b, 0);
		return (1);
	}
	return (0);
}
