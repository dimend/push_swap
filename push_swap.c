/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2024/12/11 19:01:48 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s , ", lst->content);
        lst = lst->next;
    }
	printf("\n");
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
		new_number = ft_lstnew(argV[i]);
		ft_lstadd_back(&ahead, new_number);
		i++;
	}
	
	swapfirsttwo(&ahead);
	sendfirst(&ahead,&bhead);
	
	printf("STACK A: ");
	print_list(ahead);
	printf("STACK B: ");
	print_list(bhead);
}
