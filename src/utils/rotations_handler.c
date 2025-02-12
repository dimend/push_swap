#include "libft.h"

void send_to_top(t_list *node, t_list **stack, char listname)
{
    while(node->costtotop != 0)
	{
		rotatelist(stack, node->reverse, listname);
		node->costtotop--;
	}
}

void handle_rotation(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	if (node_a->index > node_b->index)
	{
		send_to_top(node_a, a, 'a');
		send_to_top(node_b, b, 'b');
		if (node_a->reverse == 1)
			rotatelist(a, node_a->reverse, 'a');
		if (node_b->reverse == 1)
			rotatelist(b, node_b->reverse, 'b');
	}
	else
	{
		send_to_top(node_a, a, 'a');
		send_to_top(node_b, b, 'b');
		if(node_a->reverse == 0)
			rotatelist(a, node_a->reverse, 'a');
		if (node_b->reverse == 1)
			rotatelist(b, node_b->reverse, 'b');
	}
}

void rotate_to_top(t_list *node_a, t_list *node_b, t_list **a, t_list **b)
{
	while ((node_a->costtotop > 0 && node_b->costtotop > 0)
			&& node_a->reverse == node_b->reverse)
	{
		if (node_a->reverse == 0)
		{
			rotate_both(a, b, 0, 'r');
			set_costtotop(*a, *b);
		}
		else
		{
			rotate_both(a, b, 1, 'r');
			set_costtotop(*a, *b);
		}
	}
	handle_rotation(node_a, node_b, a, b);
}
