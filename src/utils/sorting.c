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
		if(((*stack)->next->content > (*stack)->content) && ((*stack)->next->content > (*stack)->next->next->content))
		{
			if((*stack)->content < (*stack)->next->next->content)
				swapfirsttwo(stack, 'a');
			else
				rotatelist(stack,1,'a');
		}
		if(((*stack)->content > (*stack)->next->content) && ((*stack)->content > (*stack)->next->next->content))
			rotatelist(stack,0,'a');
		if(((*stack)->content > (*stack)->next->content))
			swapfirsttwo(stack, 'a');
	}
}