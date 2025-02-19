/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:03:48 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:28 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_printbackwards(char *converted, int fd, int *count)
{
	int	i;

	i = 0;
	while (*converted != '\0')
	{
		i++;
		converted++;
	}
	while (i > 0)
	{
		converted--;
		if (write(fd, &*converted, 1) < 0)
			(*count) = -1;
		i--;
	}
}

static void	assignvalues(char *s, int n, int *count)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		s[i] = (n % 10) + 48;
		n = n / 10;
		(*count) += 1;
		i++;
	}
	s[i] = '\0';
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	char	nbtoch[11];

	if (n == -2147483648)
	{
		(*count) += 11;
		if (write(fd, "-2147483648", 11) < 0)
			(*count) = -1;
		return ;
	}
	else if (n < 0)
	{
		(*count) += 1;
		n = n * (-1);
		if (write(fd, "-", 1) < 0)
			(*count) = -1;
	}
	else if (n == 0)
	{
		(*count) += 1;
		if (write(fd, "0", 1) < 0)
			(*count) = -1;
		return ;
	}
	assignvalues(nbtoch, n, count);
	ft_printbackwards(nbtoch, fd, count);
}
