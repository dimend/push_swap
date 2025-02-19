/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:38:16 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 15:43:34 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	count_max_digits(void)
{
	int	max_int;
	int	max_int_digits;

	max_int = INT_MAX;
	max_int_digits = 0;
	while (max_int != 0)
	{
		max_int /= 10;
		max_int_digits++;
	}
	return (max_int_digits);
}

short int	initialize_list(char *args, t_list **a)
{
	t_list	*new_number;
	char	*arg;
	long	number;
	int		max_int_digits;

	arg = NULL;
	max_int_digits = count_max_digits();
	arg = ft_strtok(args, ' ');
	while (arg != NULL)
	{
		number = ft_atoi(arg);
		if (number > INT_MAX || number < INT_MIN
			|| (int)ft_strlen(arg) > max_int_digits + 1)
			return (1);
		new_number = ft_lstnew((int)number);
		if (new_number == NULL)
			return (1);
		ft_lstadd_back(a, new_number);
		arg = ft_strtok(NULL, ' ');
	}
	return (0);
}
