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
        ft_printf("content: %d - ", lst->content);
        ft_printf("index: %d - ", lst->index);
        ft_printf("closest: %d - ", lst->closest);
        ft_printf("costtotop: %d - ", lst->costtotop);
        ft_printf("reverse: %d \n", lst->reverse);

        lst = lst->next;
    }
    ft_printf("\n");
}

void set_index(t_list *lst)
{
    int index;
    int lstsize;
    t_list *temp;
    t_list *max_node;

    index = 1;
    lstsize = ft_lstsize(lst);
    while (index <= lstsize)
    {
        temp = lst;
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

void final_sort(t_list **a)
{
    t_list *current;

    set_costtotop(*a, NULL);
    
    current = *a;
    while (current && current->index != 1) 
        current = current->next;

    while (current->costtotop > 0)
    {
        rotatelist(a, current->reverse, 'a');
        current->costtotop--;
    }
}

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    t_list *new_number;
    int i;

    i = 1;
    while (i < argC)
    {
        new_number = ft_lstnew(ft_atoi(argV[i]));
        ft_lstadd_back(&a, new_number);
        i++;
    }

    if (ft_lstsize(a) == 3)
        small_sort(&a);
    else
    {
        set_index(a);
        while(ft_lstsize(a) > 3)
            sort_to_b(&a, &b);
        small_sort(&a);
        while(ft_lstsize(b) > 0)
            sort_to_a(&a, &b);
        final_sort(&a);
    }
}
