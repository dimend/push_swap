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
    lstsize = ft_lstsize(a);
    while (a)
    {
        a->costtotop = cost;
        a->reverse = 0;
        cost++;

        if (a->costtotop > lstsize / 2)
        {
            a->costtotop = lstsize - a->costtotop;
            a->reverse = 1;
        }
        a = a->next;
    }

    cost = 0;
    lstsize = ft_lstsize(b);
    while (b)
    {
        b->costtotop = cost;
        b->reverse = 0;
        cost++;

        if (b->costtotop > lstsize / 2)
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
            if (temp_b->index < a->index)
            {
                diff = abs(temp_b->index - a->index);
                if (diff < min_diff)
                {
                    min_diff = diff;
                    closest_index = temp_b->index;
                }
            }
            temp_b = temp_b->next;
        }
        if (closest_index == 0)
        {
            closest_index = 1;
        }
        a->closest = closest_index;
        a = a->next;
    }
}

int find_cheapest(t_list *a, t_list *b)
{
    int temp_cost;
    int cost;
    int cheapest;
    t_list *temp_b;

    cheapest = 2147483647;
    cost = 2147483647;
    temp_cost = 0;

    while (a)
    {
        temp_b = b;
        while (temp_b)
        {
            if ((temp_b->index == a->closest) || ((a->index == 1 && a->costtotop == 0)))
            {
                temp_cost = temp_b->costtotop + a->costtotop;
                if ((a->reverse == temp_b->reverse) && ((a->costtotop >= 1) && (temp_b->costtotop >= 1)))
                    temp_cost--;

                if (temp_cost < cost)
                {
                    cost = temp_cost;
                    cheapest = a->index;
                }
            }
            temp_b = temp_b->next;
        }
        a = a->next;
    }

    return (cheapest);
}

int main(int argC, char *argV[])
{
    t_list *a = NULL;
    t_list *b = NULL;
    t_list *temp_a;
    t_list *temp_b;
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
        set_index(&a);
        pushfirst(&a, &b, 'b');
        if (ft_lstsize(a) > 3)
            pushfirst(&a, &b, 'b');
        set_costtotop(a, b);
        set_closest(a, b);
        while (ft_lstsize(a) > 3)
        {
            temp_a = a;
            temp_b = b;

            int cheapest = find_cheapest(a, b);

            temp_a = a;
            temp_b = b;

            if (temp_a->index != cheapest)
            {
                while (temp_a->index != cheapest)
                    temp_a = temp_a->next;
            }

            if (temp_a->closest != 1 && temp_a->index != 1)
            {
                while (temp_b->index != temp_a->closest)
                    temp_b = temp_b->next;
            }

            while (temp_a->costtotop > 0)
            {
                rotatelist(&a, temp_a->reverse, 'a');
                temp_a->costtotop--;
            }
            while (temp_b->costtotop > 0)
            {
                rotatelist(&b, temp_b->reverse, 'b');
                temp_b->costtotop--;
            }

            if (temp_a->costtotop == 0 && temp_b->costtotop == 0)
            {
                pushfirst(&a, &b, 'b');
                set_costtotop(a, b);
                set_closest(a, b);
            }
        }

        small_sort(&a);

        temp_a = a;

        int smallest_diff = 2147483647;

        

        while (ft_lstsize(b) > 0)
        {
            temp_a = a;
            while (temp_a)
            {
                if(b->index - temp_a->index < smallest_diff && b->index - temp_a->index > 0)
                    smallest_diff = b->index - temp_a->index;
                temp_a = temp_a->next;
            }
            ft_printf("smallest_diff: %d\n", smallest_diff);

            if (a->index - b->index != smallest_diff)
            {
                if (b->index == ft_lstsize(a) + ft_lstsize(b))
                    pushfirst(&b, &a, 'a');
                else
                    rotatelist(&a, 1, 'a');
            }
            else
                pushfirst(&b, &a, 'a');
        }
        while (a->index != 1)
            rotatelist(&a, 1, 'a');
    }

    ft_printf("STACK A:\n");
    print_list(a);
    ft_printf("STACK B:\n");
    print_list(b);
}
