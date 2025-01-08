/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/07 16:06:46 by dimendon         ###   ########.fr       */
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
short int is_sorted(t_list *lst)
{
	while(lst && lst->next)
	{
		if(lst->content > lst->next->content)
			return (0);
		else
			lst = lst->next;
	}
	return (1);
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
	
	while(is_sorted(a) != 1)
	{
		if((a->next->content > a->content) && (a->next->content > a->next->next->content))
		{
			if(a->content < a->next->next->content)
				swapfirsttwo(&a, 'a');
			else
				rotatelist(&a,1,'a');
		}
		if((a->content > a->next->content) && (a->content > a->next->next->content))
			rotatelist(&a,-1,'a');
		if((a->content > a->next->content))
			swapfirsttwo(&a, 'a');
	}

	//swapfirsttwo(&a);
	//pushfirst(&a,&b);
	//rotatelist(&a, -1);
	
	ft_printf("STACK A: ");
	print_list(a);
	ft_printf("STACK B: ");
	print_list(b);
}
