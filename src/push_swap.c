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
        ft_printf("content: %d - ",lst->content);
        ft_printf("index: %d - ",lst->index);
        ft_printf("closest: %d - ",lst->closest);
        ft_printf("costtotop: %d - ",lst->costtotop);
        ft_printf("reverse: %d \n",lst->reverse);
        
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

void set_costtotop(t_list *a, t_list *b)
{
     int cost;
     int lstsize;

     cost = 0;
     lstsize  = ft_lstsize(a);
     while(a)
     {
        a->costtotop = cost;
        a->reverse = 0;
        cost++;

        if(a->costtotop > lstsize/2)
        {
            a->costtotop = lstsize - a->costtotop;
            a->reverse = 1;
        }
        a = a->next;
     }

        cost = 0;
     lstsize  = ft_lstsize(b);
     while(b)
     {
        b->costtotop = cost;
        b->reverse = 0;
        cost++;

        if(b->costtotop > lstsize/2)
        {
            b->costtotop = lstsize - b->costtotop;
            b->reverse = 1;
        }
        b = b->next;
     }
 }

void set_closest(t_list *a, t_list *b)
{
    int closest_index;
    int min_diff;
    int diff;
    t_list *temp_b;

    temp_b = b;
    while (a)
    {
        closest_index = 0;
        diff = 0;
        min_diff = 2147483647;
        temp_b = b;
        while (temp_b)
        {
            diff = abs(temp_b->index - a->index);
            if (diff < min_diff)
            {
                min_diff = diff;
                closest_index = temp_b->index;
            }
            temp_b = temp_b->next;
        }
        a->closest = closest_index;
        a = a->next;
        temp_b = b;
    }
}

int find_cheapest(t_list *a, t_list *b)
{  
    int cost;
    int cheapest;
    t_list *temp_b;

    cheapest = 2147483647;
    cost = 2147483647;
    while (a)
    {
        b = temp_b;
        while(temp_b)
        {
            if((temp_b->index == a->closest) && (temp_b->costtotop + a->costtotop < cost))
            {
                cost = temp_b->costtotop + a->costtotop;
                cheapest = a->index;
            }
            temp_b = temp_b->next;
        }
        a = a->next;
        temp_b = b;
    }
    ft_printf("cost: %d\n",cost);
    return (cheapest);
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
    pushfirst(&a,&b,'b');
    pushfirst(&a,&b,'b');
    set_costtotop(a, b);
    set_closest(a, b);

    //7 5 2
    rotatelist(&b, -1, 'b'); 
    pushfirst(&a,&b,'b');
    set_costtotop(a, b);
    set_closest(a, b);
    
    //1 7 5 2
    pushfirst(&a,&b,'b'); 
    set_costtotop(a, b);
    set_closest(a, b);



    ft_printf("CHEAPEST: %d\n",find_cheapest(a, b));


	//swapfirsttwo(&a,'a');
	//pushfirst(&a,&b,'a');
	//rotatelist(&a, -1, 'a');
	
	ft_printf("STACK A:\n");
	print_list(a);
	ft_printf("STACK B:\n");
	print_list(b);
}

