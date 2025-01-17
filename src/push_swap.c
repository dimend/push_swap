/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/01/17 19:42:04 by dimendon         ###   ########.fr       */
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
        ft_printf("%d - %d\n",index, lstsize);
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

// void set_costtotop(t_list *lst)
// {
//     int cost;
//     int lstsize;

//     cost = 0;
//     lstsize  = ft_lstsize(lst);
//     while(lst)
//     {
//         lst->costtotop = cost;
//         lst->reverse = 0;
//         cost++;
//         if(lst->costtotop > lstsize/2)
//         {
//             lst->costtotop = lstsize - lst->costtotop;
//             lst->reverse = 1;
//         }
//         lst = lst->next;
//     }
// }
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
    //set_costtotop(a);

	//swapfirsttwo(&a,'a');
	//pushfirst(&a,&b,'a');
	//rotatelist(&a, -1, 'a');
	
	ft_printf("STACK A: ");
	print_list(a);
	ft_printf("STACK B: ");
	print_list(b);
}

