/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/15 20:19:36 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int get_highest(t_list *lst)
{  
    int highest;

    highest = lst->index;

    while (lst)
    {
        if (lst->index > highest)
            highest = lst->index;
  
        lst = lst->next;
    }
    
    return (highest);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        ft_printf("%d - %d ,",lst->index,lst->content);
        lst = lst->next;
    }
	ft_printf("\n");
}

void set_index(t_list **lst)
{
    int index;
    int lstsize;
    t_list *temp;
    t_list *max_node;

    index = 1;
    lstsize = ft_lstsize(*lst);

    while (index <= lstsize)
    {
        temp = *lst;
        max_node = NULL;
		
        while (temp)
        {
            if (temp->index == 0 && (max_node == NULL || temp->content < max_node->content))
                max_node = temp;
            temp = temp->next;
        }
        if (max_node != NULL)
        {
            max_node->index = index;
            index++;
        }
    }
}

int cost_to_top(t_list *lst, int index)
{
    int cost;
    int lstsize;

    cost = 0;
    lstsize  = ft_lstsize(lst);
    while(lst)
    {
        if(lst->index == index)
            break;
        cost++;
        lst = lst->next;
    }

    if(cost > lstsize/2)
        cost = lstsize - cost;
        
    return (cost);
}
int total_cost()
{

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
    
	set_index(&a);
    
    
	// pushfirst(&a,&b,'a');

	//swapfirsttwo(&a,'a');
	//pushfirst(&a,&b,'a');
	//rotatelist(&a, -1, 'a');
	
	ft_printf("STACK A: ");
	print_list(a);
	ft_printf("STACK B: ");
	print_list(b);
}

