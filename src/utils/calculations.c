#include "libft.h"

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
        if (closest_index == 0)
            closest_index = 1;
        a->closest = closest_index;
        a = a->next;
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

        if (cost > lstsize / 2)
        {
            a->costtotop = (lstsize - cost)+1;
            a->reverse = 1;
        }
        a = a->next;
    }

    if (b != NULL)
    {
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