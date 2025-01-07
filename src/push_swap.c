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
        printf("%d , ", lst->content);
        lst = lst->next;
    }
	printf("\n");
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
	t_list *ahead = NULL;
	t_list *bhead = NULL;
	t_list *new_number;
	int i;

	i = 1;

	while(i < argC)
	{
		new_number = ft_lstnew(ft_atoi(argV[i]));
		ft_lstadd_back(&ahead, new_number);
		i++;
	}
	
	printf("%d \n", is_sorted(ahead));

	//swapfirsttwo(&ahead);
	//pushfirst(&ahead,&bhead);
	//rotatelist(&ahead, -1);
	
	printf("STACK A: ");
	print_list(ahead);
	printf("STACK B: ");
	print_list(bhead);
}
