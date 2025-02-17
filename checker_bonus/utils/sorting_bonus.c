#include "../checker_bonus.h"

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


