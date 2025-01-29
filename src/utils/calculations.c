#include "libft.h"

t_list *find_lowest_diff(t_list **a, t_list **b)
{
    t_list *lowest_diff;
    t_list *temp_a;
    int diff;
    int smallest_diff;

    diff = 0;
    smallest_diff = 2147483647;
    temp_a = *a;
    while (temp_a)
	{
		diff = (*b)->index - temp_a->index;
            if (abs(diff) < abs(smallest_diff) || 
                (abs(diff) == abs(smallest_diff) && diff < smallest_diff))
            {
			smallest_diff = diff;
			lowest_diff = temp_a;
		}
		temp_a = temp_a->next;
	}
    return (lowest_diff);
}

int get_closest_index(t_list *a, t_list *b)
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

void calc_costtotop(t_list *lst, int lstsize)
{
    int cost;

    if(!lstsize%2)
        lstsize++;

    cost = 0;
    while (lst)
    {
        if (cost > lstsize / 2)
        {
            lst->costtotop = lstsize - cost;
            lst->reverse = 1;
        }
        else
        {
            lst->costtotop = cost;
            lst->reverse = 0;
        }
        cost++;
        lst = lst->next;
    }
}

int calc_cheapest(t_list *a, t_list *b)
{
    int temp_cost;
    t_list *temp_b;

    temp_cost = 2147483647;
    temp_b = b;
    while (temp_b)
    {
        if ((temp_b->index == a->closest) || ((a->index == 1 && a->costtotop == 0)))
        {
            int current_cost = temp_b->costtotop + a->costtotop;
            if ((a->reverse == temp_b->reverse) && ((a->costtotop >= 1) && (temp_b->costtotop >= 1)))
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
    t_list *cheapest_node;
    int temp_cost;
    int cost;

    cost = 2147483647;
    while (a)
    {
        temp_cost = calc_cheapest(a, b);
        if (temp_cost < cost)
        {
            cost = temp_cost;
            cheapest_node = a;
        }
        a = a->next;
    }
    return (cheapest_node);
}
