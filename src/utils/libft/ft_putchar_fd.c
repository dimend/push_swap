/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimendon <dimendon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:04:02 by dimendon          #+#    #+#             */
/*   Updated: 2025/02/19 16:06:31 by dimendon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd, int *count)
{
	if (fd < 0)
		return ;
	(*count)++;
	if (write(fd, &c, 1) < 0)
		(*count) = -1;
}
