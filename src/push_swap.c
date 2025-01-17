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

void print_list(t_list *lst)
{
    while (lst)
    {
        ft_printf("%d - %d , ",lst->index,lst->content);
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

void total_cost(t_list **stacka, t_list **stackb)
{
    t_list *temp_a;
    int highest;
    int cost;
    int cheapest;
    int min_cost;

    highest = get_highest(*stackb);
    temp_a = *stacka;
    min_cost = 2147483647;
    cheapest = -1;

    while (temp_a)
    {
        cost = cost_to_top(*stackb, highest);
        cost += cost_to_top(*stacka, temp_a->index);
        ft_printf("COST - %d\n", cost+1);

        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest = temp_a->index;
        }
        temp_a = temp_a->next;
    }
    ft_printf("CHEAPEST COST - %d, INDEX - %d\n", min_cost+1, cheapest);
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
    pushfirst(&a,&b,'a');
    pushfirst(&a,&b,'a');
    total_cost(&a,&b);
    

	//swapfirsttwo(&a,'a');
	//pushfirst(&a,&b,'a');
	//rotatelist(&a, -1, 'a');
	
	ft_printf("STACK A: ");
	print_list(a);
	ft_printf("STACK B: ");
	print_list(b);
}

