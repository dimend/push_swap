/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:15:12 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:26 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	char	*ptr;
	int		strlen;

	if (!s)
	{
		(*count) += 6;
		write(fd, "(null)", 6);
		return ;
	}
	if (fd < 0)
		return ;
	ptr = s;
	strlen = 0;
	while (*ptr != '\0')
	{
		ptr++;
		strlen++;
		(*count)++;
	}
	if (write(fd, s, strlen) < 0)
		(*count) = -1;
}
