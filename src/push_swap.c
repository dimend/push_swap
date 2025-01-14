/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/14 18:58:13 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void print_list(t_list *lst)
{
    while (lst)
    {
        ft_printf("%d , ", lst->content);
        lst = lst->next;
    }
	ft_printf("\n");
}
void calc_cost(t_list **lsta, t_list **lstb)
{
	int index;
	int cost;
	t_list *temp_b;

	temp_b = *lstb;
	cost = ft_lstsize(temp_b);
	index = 0;
	while(temp_b)
	{
		if( (ft_lstsize(temp_b) - index) < cost)
			cost = ft_lstsize(temp_b) - index;
		index++;
		temp_b = temp_b->next;

		ft_printf("%d" , cost);
		if(cost == 0)
			pushfirst(lsta,lstb,'a');
		if(cost == 1)
		{
			rotatelist(lstb, 1, 'b');
			pushfirst(lsta,lstb,'a');
		}
		if(cost == 2)
		{
			rotatelist(lstb, 1, 'b');
			rotatelist(lstb, 1, 'b');
			pushfirst(lsta,lstb,'a');
		}	
	}
}

int	main(int argC, char *argV[])
{	
	t_list *a = NULL;
	t_list *b = NULL;
	t_list *new_number;
	int i;

	i = 1;

	while(i < argC)
	{
		new_number = ft_lstnew(ft_atoi(argV[i]));
		ft_lstadd_back(&a, new_number);
		i++;
	}
	
	if(argC > 4)
	{
		pushfirst(&a,&b,'a');
		pushfirst(&a,&b,'a');
		calc_cost(&a,&b);
		
	}

	//swapfirsttwo(&a,'a');
	//pushfirst(&a,&b,'a');
	//rotatelist(&a, -1, 'a');
	
	ft_printf("STACK A: ");
	print_list(a);
	ft_printf("STACK B: ");
	print_list(b);
}

