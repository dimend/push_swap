/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/10 16:26:49 by dimendon         ###   ########.fr       */
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
	
	//if(argC == 4)
	//	small_sort(&a);

	//swapfirsttwo(&a,'a');
	//pushfirst(&a,&b,'a');
	//rotatelist(&a, -1, 'a');
	
	ft_printf("STACK A: ");
	print_list(a);
	ft_printf("STACK B: ");
	print_list(b);
}
