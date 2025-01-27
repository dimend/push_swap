#include "libft.h"

int get_min_diff(t_list *a, t_list *b)
{
    int diff;
    int min_diff;
    int closest_index;

    min_diff = 2147483647;
    closest_index = 0;
    while (b)
    {
        diff = abs(b->index - a->index);
        if (diff < min_diff)
        {
            min_diff = diff;
            closest_index = b->index;
        }
        b = b->next;
    }

    return (closest_index);
}

void set_closest(t_list *a, t_list *b)
{
    int closest_index;

    closest_index = 0;
    while (a)
    {
        closest_index = get_min_diff(a, b);
        if (closest_index == 0)
            closest_index = 1;
        a->closest = closest_index;
        a = a->next;
    }
}

void calc_costtotop(t_list *lst, int lstsize)
{
    int cost;

    cost = 0;
    while (lst)
    {
        lst->costtotop = cost;
        lst->reverse = 0;
        cost++;

        if (cost > lstsize / 2)
        {
            lst->costtotop = (lstsize - cost)+1;
            lst->reverse = 1;
        }
        lst = lst->next;
    }
}

int calc_cheapest(t_list *a, t_list *b, int cheapest)
{   
    int temp_cost;
    int cost;

    cost = 2147483647;
    temp_cost = 0;
    while (b)
    {
        if ((b->index == a->closest) || ((a->index == 1 && a->costtotop == 0)))
        {
            temp_cost = b->costtotop + a->costtotop;
            if ((a->reverse == b->reverse) && ((a->costtotop >= 1) && (b->costtotop >= 1)))
                temp_cost--;
            if (temp_cost < cost)
            {
                cost = temp_cost;
                cheapest = a->index;
            }
        }
        b = b->next;
    }
    return (cheapest);
}

int find_cheapest(t_list *a, t_list *b)
{
    int cheapest;

    cheapest = 0;
    while (a)
    {
        cheapest = calc_cheapest(a, b, cheapest);
        a = a->next;
    }
    return (cheapest);
}
