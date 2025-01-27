/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:15:12 by dimendon          #+#    #+#             */
/*   Updated: 2024/11/19 14:31:24 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
