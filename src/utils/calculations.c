#include "libft.h"

t_list *find_lowest_diff(t_list **a, t_list **b)
{
    t_list *lowest_diff = NULL;
    t_list *temp_a = *a;
    int smallest_diff = 2147483647;
    int diff;

    if (!a || !b || !*a || !*b)
        return NULL;

    while (temp_a) 
    {
        diff = (*b)->index - temp_a->index;
        if (abs(diff) < smallest_diff) 
        {
            smallest_diff = abs(diff);
            lowest_diff = temp_a;
        }
        temp_a = temp_a->next;
    }
    return lowest_diff;
}

int get_min_diff(t_list *a, t_list *b)
{
    int diff;
    int min_diff = 2147483647;
    int closest_index = 0;

    while (b)
    {
        diff = b->index - a->index;
        if (abs(diff) < min_diff)
        {
            min_diff = abs(diff);
            closest_index = b->index;
        }
        b = b->next;
    }

    return closest_index;
}

void calc_costtotop(t_list *lst, int lstsize)
{
    int cost;
    
    cost = 0;
    while (lst)
    {
        if ((cost-1) < lstsize / 2)
        {
            lst->costtotop = cost;
            lst->reverse = 0;
        }
        else
        {
            lst->costtotop = lstsize - cost - 1;
            lst->reverse = 1;
        }
        cost++;
        lst = lst->next;
    }
}

int calc_cheapest(t_list *a, t_list *b)
{
    int temp_cost = 2147483647;
    t_list *temp_b = b;

    while (temp_b)
    {
        if ((temp_b->index == a->closest) || (a->index == 1 && a->costtotop == 0 && a->reverse == 0))
        {
            int current_cost = a->costtotop + temp_b->costtotop;

            if (a->reverse == temp_b->reverse && a->costtotop >= 1 && temp_b->costtotop >= 1)
                current_cost--;

            if (current_cost < temp_cost)
                temp_cost = current_cost;
        }
        temp_b = temp_b->next;
    }
    return temp_cost;
}

t_list *find_cheapest(t_list *a, t_list *b)
{
    t_list *cheapest_node = NULL;
    int temp_cost;
    int min_cost = 2147483647;

    while (a)
    {
        temp_cost = calc_cheapest(a, b);
        if (temp_cost < min_cost)
        {
            min_cost = temp_cost;
            cheapest_node = a;
        }
        a = a->next;
    }
    return cheapest_node;
}
